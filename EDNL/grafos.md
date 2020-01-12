# Grafos

Un **grafo** G = (V, A) consta de un conjunto de **vértices o nodos**, V, y un conjunto de **aristas o arcos** A ⊆ (V×V) que
define una relación binaria en V. Cada arista es, por tanto, un par de vértices (v, w) ∈ A.

Si cada arista (v, w) ∈ A es un par ordenado, es decir, si (v, w) y (w, v) no son equivalentes, entonces el grafo 
es **dirigido** y la arista (v, w) se representa como una flecha de v a w. El vértice v se dice que es **incidente** sobre
el vértice w y w es adyacente a v.

Si, por el contrario, cada arista es un par no ordenado de vértices y por tanto (v, w) = (w, v), entonces el 
grafo es **no dirigido** y la arista (v, w) se representa como un segmento entre v y w. En este caso,
se dice que v y w son adyacentes y la arista (v, w) es incidente sobre v y w.

Una arista puede tener un valor asociado, llamado **peso**, que representa un tiempo,
una distancia, un coste, etc. Un grafo cuyas aristas tienen pesos asociados recibe el
nombre de **grafo ponderado**.


## Definiciones

- **`Grado:`** El grado de un vértice en un grafo no dirigido es el número de arcos del vértice. Si
el grafo es dirigido, se distingue entre grado de entrada (número de arcos incidentes
en el vértice) y grado de salida (número de arcos adyacentes al vértice).  

- **`Camino:`** Una sucesión de vértices de un grafo n 1 , n 2 , ..., n k , tal que (n i , n i+1 ) es una arista
para 1 ≤ i < k. La longitud de un camino es el número de arcos que comprende, en
este caso k-1. Si el grafo es ponderado la longitud de un camino se calcula como la
suma de los pesos de las aristas que lo constituyen.
- **`Camino simple:`** Un camino cuyos arcos son todos distintos. Si además todos los vértices
son distintos, se llama camino elemental.
- **`Ciclo:`** Es un camino en el que coinciden los vértices inicial y final. Si el camino es simple, el
ciclo es simple y si el camino es elemental, entonces el ciclo se llama elemental. Se
permiten arcos de un vértice a sí mismo; si un grafo contiene arcos de la forma (v, v),
lo cual no es frecuente, estos son ciclos de longitud 1; de lo contrario y como caso
especial, un vértice v por sí mismo denota un camino de longitud 0.
- **`Grafo conexo:`** Grafo no dirigido en el que hay al menos un camino entre cualquier par de
vértices.
- **`Grafo fuertemente conexo:`** Grafo dirigido en el que hay al menos un camino entre
cualquier par de vértices. Si un grafo dirigido no es fuertemente conexo, pero el grafo
no dirigido subyacente (sin dirección en los arcos) es conexo, entonces es débilmente
conexo.
- **`Grafo completo:`** Aquel en el cual existe una arista entre cualquier par de vértices (en
ambos sentidos si el grafo es dirigido).
- **`Subgrafo:`** Dado un grafo G = (V, A), diremos que G’ = (V’, A’), donde V’ ⊆ V y A’ ⊆ A, es un
subgrafo de G si A’ sólo contiene todas las aristas de A que unen vértices de V’.
