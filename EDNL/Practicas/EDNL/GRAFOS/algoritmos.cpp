
// Suma de costes. Devuelve GrafoP<tCoste>::INFINITO si alguno de los
// dos parámetros vale GrafoP<tCoste>::INFINITO.
template <typename tCoste> 
tCoste suma(tCoste x, tCoste y);


// Calcula los caminos de coste mínimo entre origen y todos los
// vértices del grafo G. Devuelve un vector de tamaño G.numVert()
// con estos costes mínimos y un vector P, también de tamaño
// G.numVert(), tal que P[i] es el último vértice del camino de
// coste mínimo de origen a i.
template <typename tCoste>
vector<tCoste> Dijkstra(const GrafoP<tCoste>& G, 
						typename GrafoP<tCoste>::vertice origen, 
						vector<typename GrafoP<tCoste>::vertice>& P);


// Devuelve el camino de coste mínimo entre los vértices orig e i
// a partir de un vector P obtenido mediante la función Dijkstra().
template <typename tCoste> 
typename GrafoP<tCoste>::tCamino camino(typename GrafoP<tCoste>::vertice orig, 
										typename GrafoP<tCoste>::vertice i,
          								const vector<typename GrafoP<tCoste>::vertice>& P);


// Calcula los caminos de coste mínimo entre cada par de vértices
// del grafo G. Devuelve una matriz de costes mínimos de tamaño
// n x n, con n = G.numVert(), y una matriz de vértices P de
// tamaño n x n, tal que P[i][j] es el vértice por el que pasa el
// camino de coste mínimo de i a j, si este vértice es i el camino es directo.
template <typename tCoste>
matriz<tCoste> Floyd(const GrafoP<tCoste>& G, matriz<typename GrafoP<tCoste>::vertice>& P);


// Devuelve el camino de coste mínimo desde i hasta j a partir
// de una matriz P obtenida mediante la función Floyd().
template <typename tCoste> 
typename GrafoP<tCoste>::tCamino camino(typename GrafoP<tCoste>::vertice i,
          								typename GrafoP<tCoste>::vertice j,
          								const matriz<typename GrafoP<tCoste>::vertice>& P);


// Devuelve un árbol generador de coste mínimo
// de un grafo no dirigido ponderado y conexo G.
template <typename tCoste>
GrafoP<tCoste> Prim(const GrafoP<tCoste>& G);
    
 
// Devuelve un árbol generador de coste mínimo
// de un grafo no dirigido ponderado y conexo G.
template <typename tCoste>
GrafoP<tCoste> Kruskall(const GrafoP<tCoste>& G);


// Determina si hay un camino entre cada par de vértices
// del grafo G.
// Devuelve una matriz booleana A de tamaño n x n, tal que
// A[i][j] == true si existe al menos un camino entre
// el vértice i y el vértice j, y A[i][j] == false si no
// existe ningún camino entre los vértices i y j.
matriz<bool> Warshall(const Grafo& G);


/*----------------------------------------------------------------------------*/
/* Recorridos de grafos no ponderados                                         */
/*----------------------------------------------------------------------------*/
enum visitas {NO_VISITADO, VISITADO};

Lista<Grafo::vertice> Profundidad2(const Grafo& G, Grafo::vertice u);

Lista<Grafo::vertice> Anchura(const Grafo& G, Grafo::vertice u);
