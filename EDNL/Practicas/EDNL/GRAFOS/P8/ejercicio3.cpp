#include "../Includes/grafoPMC.h"
#include "../Includes/alg_grafoPMC.h"

template <typename T>
GrafoP<T> arbolExtensionMaximo(const GrafoP<T>& G){
    GrafoP<T> Gc(G.numVert());
    // Al multiplicar por -1, cuando los
    // ordene el orden se invertirá.
    for (int i = 0; i < G.numVert(); ++i){
        for (int j = 0; j < G.numVert(); ++j){
            if (G[i][j] != GrafoP<T>::INFINITO)
                Gc[i][j] = G[i][j] * -1;
        }
    }
    Gc = Kruskall(Gc);
    for (int i = 0; i < G.numVert(); ++i){
        for (int j = 0; j < G.numVert(); ++j){
            if (Gc[i][j] != GrafoP<T>::INFINITO)
                Gc[i][j] = Gc[i][j] * -1;
        }
    }
    return Gc;
}