#include "../Includes/grafoPMC.h"
#include "../Includes/alg_grafoPMC.h"
#include "../Includes/alg_grafo_E-S.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

struct ciudad{
    double x, y;
    ciudad(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

double distancia(const ciudad& a, const ciudad& b){
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

template <typename T>
void construirIsla(GrafoP<T>& G, const vector<ciudad>& c){
    for (int i = 0; i < c.size(); ++i){
        for (int j = 0; j < c.size(); ++j){
            if (i == j){
                G[i][j] = GrafoP<T>::INFINITO;
            }
            else{
                G[i][j] = distancia(c[i], c[j]);
            }
        }
    }
    G = Prim(G);
}

template <typename T>
GrafoP<T> unirIslas(const GrafoP<T>& A, const GrafoP<T>& B,
                unsigned a, unsigned b, T dPuente){
    const unsigned nA = A.numVert();
    const unsigned nB = B.numVert();
    const unsigned n = nA + nB;
    GrafoP<T> G(n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i < nA && j < nA){
                if (A[i][j] != GrafoP<T>::INFINITO)
                    G[i][j] = A[i][j];
            }
            else if (i >= nA && j >= nA){
                if (B[i - nA][j - nA] != GrafoP<T>::INFINITO)
                    G[i][j] = B[i - nA][j - nA];
            }
        }
    }
    G[a][b + nA] = G[b + nA][a] = dPuente;
    return G;
}

template <typename T>
T reconstruccionGrecolana(vector<ciudad> ciudadesFobos,
                        vector<ciudad> ciudadesDeimos,
                        vector<bool> costerasFobos,
                        vector<bool> costerasDeimos,
                        unsigned origen, int islaO, unsigned destino, int islaD){
    const unsigned nF = ciudadesFobos.size();
    const unsigned nD = ciudadesDeimos.size();
    GrafoP<T> Fobos(nF), Deimos(nD);
    construirIsla(Fobos, ciudadesFobos);
    construirIsla(Deimos, ciudadesDeimos);
    unsigned puenteFobos, puenteDeimos;
    T costeMin = GrafoP<T>::INFINITO;
    for (int i = 0; i < nF; ++i){
        if (costerasFobos[i])
            for (int j = 0; j < nD; ++j){
                if (costerasDeimos[j]){
                    T dIJ = distancia(ciudadesFobos[i], ciudadesDeimos[j]);
                if (dIJ < costeMin){
                    costeMin = dIJ;
                    puenteFobos = i;
                    puenteDeimos = j;
                }
            }
        }
    }
    T dPuente = distancia(ciudadesFobos[puenteFobos], ciudadesDeimos[puenteDeimos]);
    GrafoP<T> Grecoland = unirIslas(Fobos, Deimos, puenteFobos, puenteDeimos, dPuente);
    vector<typename GrafoP<T>::vertice> P;
    unsigned origenVerdadero = origen + (islaO ? nF : 0);
    unsigned destinoVerdadero = destino + (islaD ? nF : 0);
    return Dijkstra(Grecoland, origenVerdadero, P)[destinoVerdadero];
}

int main()
{
    std::vector<ciudad> cFobos(3), cDeimos(2);
    cFobos[0] = (ciudad{0, 0});
    cFobos[1] = (ciudad{1, 1});
    cFobos[2] = (ciudad{1, 2});
    cDeimos[0] = (ciudad{5, 4});
    cDeimos[1] = (ciudad{6, 6});

    std::vector<bool> cosF(3, true), cosD(2, true);
    cosD[1] = false;

    cout << "Coste: " << reconstruccionGrecolana<double>(cFobos, cDeimos, cosF, cosD,
                                                0, 0, 1, 1) << endl;
}
