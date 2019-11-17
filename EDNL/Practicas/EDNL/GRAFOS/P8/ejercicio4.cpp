#include "../Includes/alg_grafo_E-S.h"
#include <iostream>
#include "ejercicio3.cpp"

using namespace std;

struct canal{
    unsigned c1, c2;
    int distancia;
    canal(unsigned c1, unsigned c2, int distancia)
    : c1(c1), c2(c2), distancia(distancia) {}
};

template <typename T>
vector<canal> canalizacionValleJerte(const GrafoP<T> G){
    vector<canal> canalizacion;
    GrafoP<T> canales = arbolExtensionMaximo(G);
    // GrafoP<T> canales = Kruskall(G);
    for (int i = 0; i < canales.numVert(); ++i)
        for (int j = i + 1; j < canales.numVert(); ++j){
            if (canales[i][j] != GrafoP<T>::INFINITO){
                canalizacion.push_back(canal(i, j, canales[i][j]));
            }
        }
    return canalizacion;
}

void con(int a, int b, int c, GrafoP<int>& G){
    G[a][b] = G[b][a] = c;
}

int main()
{
    GrafoP<int> G(6);
    con(0, 2, 5, G);
    con(0, 3, 10, G);
    con(1, 2, 20, G);
    con(1, 3, 100, G);
    con(1, 5, 70, G);
    con(1, 4, 40, G);
    con(4, 5, 40, G);
    con(2, 5, 50, G);

    for (canal& c : canalizacionValleJerte(G))
    {
        cout << "Canal: " << c.c1 << " -- " << c.c2 << " :: " << c.distancia << endl;
    }

}