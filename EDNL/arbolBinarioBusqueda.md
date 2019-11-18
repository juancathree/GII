# Arbol binario de busqueda

Un **`árbol binario de búsqueda`** es un árbol binario en el que los nodos almacenan elementos de un conjunto 
(no existen elementos repetidos). La propiedad que define a estos árboles es que todos los elementos almacenados en
el subárbol izquierdo de cualquier nodo n son menores que el elemento de n, y todos los elementos almacenados en el 
subárbol derecho de n son mayores que el elemento almacenado en el mismo.  

Consideraremos que existe un orden lineal definido sobre el tipo de los elementos dado por el operador <.

## Operaciones

**`Abb()`**
- **Post:** Construye un árbol binario de búsqueda vacío.

**`const Abb& buscar(const T& e) const`**
- **Post:** Si el elemento e pertenece al árbol, devuelve el subárbol en cuya raíz se encuentra e; en caso contrario, 
devuelve un árbol vacío.

**`void insertar(const T& e)`**
- **Post:** Si e no pertenece al árbol, lo inserta; en caso contrario, el árbol no se modifica.

**`void eliminar(const T& e)`**
- **Post:** Elimina el elemento e del árbol. Si e no se encuentra, el árbol no se modifica.

**`bool vacio() const`**
- **Post:** Devuelve true si el árbol está vacío y false en caso contrario.

**`const T& elemento() const`**
- **Pre:** Árbol no vacío.
- **Post:** Devuelve el elemento de la raíz de un árbol binario de búsqueda.

**`const Abb& izqdo() const`**
- **Pre:** Árbol no vacío.
- **Post:** Devuelve el subárbol izquierdo.

**`const Abb& drcho() const`**
- **Pre:** Árbol no vacío.
- **Post:** Devuelve el subárbol derecho.
