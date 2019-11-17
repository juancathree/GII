#include "../Includes/grafoPMC.h"
#include "../Includes/alg_grafoPMC.h"
#include <iostream>

using namespace std;

struct canal{
    unsigned c1, c2;
    double distancia, caudal;
    canal(unsigned c1, unsigned c2, double distancia, double caudal = 0)
    : c1(c1), c2(c2), distancia(distancia), caudal(caudal) {}
};

template <typename T>
vector<canal> canalizacionSubvencionadaCaudalosa(const GrafoP<double>& distancias,
                                                const GrafoP<double>& caudales, T subvencion, T costeKM){
    typedef typename GrafoP<double>::arista arista;
    typedef typename GrafoP<double>::vertice vertice;
    const unsigned n = distancias.numVert();
    GrafoP<double> G(n);
    GrafoP<double> K(n);
    // cada coste es la distancia entre ciudades * coste por kilómetro
    // menos lo que nos subvencione el estado, que será el maximo caudal que
    // que podamos llevar por el canal * la subvencion por caudal.
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            G[i][j] = G[j][i] = distancias[i][j] * costeKM;
        }
    }
    K = Kruskall(G);
    double caudal = GrafoP<double>::INFINITO;
    vector<canal> canales;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (K[i][j] != GrafoP<double>::INFINITO) {
                if (caudales[i][j] < caudal){
                    caudal = caudales[i][j];
                }
                canales.push_back(canal(i, j, distancias[i][j]));
            }
        }
    }
    for (canal& c : canales){
        c.caudal = caudal;
    }
    return canales;
}

void con(int a, int b, int c, GrafoP<double>& G){
    G[a][b] = G[b][a] = c;
}

int main()
{
    GrafoP<double> G(6);
    con(0, 2, 5, G);
    con(0, 3, 10, G);
    con(1, 2, 20, G);
    con(1, 3, 100, G);
    con(1, 5, 70, G);
    con(1, 4, 40, G);
    con(4, 5, 40, G);
    con(2, 5, 50, G);

    GrafoP<double> caudales(6);
    con(0, 2, 300, caudales);
    con(0, 3, 300, caudales);
    con(1, 2, 300, caudales);
    con(1, 3, 1000, caudales);
    con(1, 5, 500, caudales);
    con(1, 4, 600, caudales);
    con(4, 5, 700, caudales);
    con(2, 5, 800, caudales);

    vector<canal> canales = canalizacionSubvencionadaCaudalosa(G, caudales, 50, 10);
    for (canal& c : canales)
    {
        cout << "Canal: " << c.c1 << " - " << c.c2 << " | " << c.distancia << " Km | "
            << c.caudal << " m3/s" << endl;
    }
}
