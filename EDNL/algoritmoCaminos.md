# Algoritmos de caminos de coste minimo

## Algoritmo de Dijkstra
Calcula los caminos de coste mínimo entre origen y todos los vértices del grafo G. Salida:
- Un vector de costes mínimos de tamaño G.numVert().
- P, un vector de vértices de tamaño G.numVert(), tal que P[i] es el vértice
anterior a i en el camino de coste mínimo desde origen hasta i.

```c++
template <typename tCoste>
vector<tCoste> Dijkstra(const GrafoP<tCoste>& G, 
                        typename GrafoP<tCoste>::vertice origen,
                        vector<typename GrafoP<tCoste>::vertice>& P);
```

## Algoritmo de Floyd
Calcula los caminos de coste mínimo entre cada par de vértices del grafo G. Salida:
- Una matriz de costes mínimos de tamaño n x n, con n = G.numVert()
- P, una matriz de vértices de tamaño n x n, tal que P[i][j] es un vértice
intermedio por el que pasa el camino de coste mínimo desde i a j.

```c++
template <typename tCoste>
matriz<tCoste> Floyd(const GrafoP<tCoste>& G,
                     matriz<typename GrafoP<tCoste>::vertice>& P);
```

## Algoritmo de Warshall
Determina si hay un camino entre cada par de vértices del grafo no ponderado G. Salida:
- Una matriz booleana cuadrada de tamaño G.numVert(), tal que una posición
[i][j] es true si existe al menos un camino entre el vértice i y el vértice j, y
false si no existe ningún camino entre estos vértices.

```c++
matriz<bool> Warshall(const Grafo& G);
```
