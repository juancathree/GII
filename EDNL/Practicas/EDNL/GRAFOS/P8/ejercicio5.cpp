#include "../Includes/grafoPMC.h"
#include "../Includes/alg_grafoPMC.h"

#include <iostream>

using namespace std;

template <typename T>
T enfibrarEspanita(const GrafoP<T>& G){
    GrafoP<T> arbolGeneradorMinimo = Kruskall(G);
    T total = 0;
    for (int i = 0; i < G.numVert(); ++i)
        for (int j = i + 1; j < G.numVert(); ++j){
            if (arbolGeneradorMinimo[i][j] != GrafoP<T>::INFINITO){
                total += arbolGeneradorMinimo[i][j];
            }
        }
    return total;
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

    cout << "Lo minimo para enfibrar españita es: " << enfibrarEspanita(G) << " kms." << endl;
}