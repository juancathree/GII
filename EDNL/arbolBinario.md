# Arbol Binario

Un **`árbol binario`** se define como un árbol cuyos nodos son, a lo sumo, de grado 2, es decir, tienen 0, 1 ó 2 hijos. Éstos se llaman hijo izquierdo e hijo derecho.

<h3><img src="imagenes/arbolbinario.png" width="300px"/></h3>

## Operaciones

**`Abin ()`**
- **Post:** Crea y devuelve un árbol vacío.

**`void insertarRaizB (const T& e)`**
- **Pre:** El árbol está vacío.
- **Post:** Inserta el nodo raíz cuyo contenido será e.

**`void insertarHijoIzqdoB (nodo n, const T& e)`**
- **Pre:** n es un nodo del árbol que no tiene hijo izquierdo.
- **Post:** Inserta el elemento e como hijo izquierdo del nodo n.

**`void insertarHijoDrchoB (nodo n, const T& e)`**
- **Pre:** n es un nodo del árbol que no tiene hijo derecho.
- **Post:** Inserta el elemento e como hijo derecho del nodo n.

**`void eliminarHijoIzqdoB (nodo n)`**
- **Pre:** n es un nodo del árbol. Existe hijoIzqdoB(n) y es una hoja.
- **Post:** Destruye el hijo izquierdo del nodo n.

**`void eliminarHijoDrchoB (nodo n)`**
- **Pre:** n es un nodo del árbol. Existe hijoDrchoB(n) y es una hoja.
- **Post:** Destruye el hijo derecho del nodo n.

**`void eliminarRaizB ()`**
- **Pre:** El árbol no está vacío y raizB() es una hoja.
- **Post:** Destruye el nodo raíz. El árbol queda vacío

**`bool arbolVacioB () const`**
- **Post:** Devuelve true si el árbol está vacío y false en caso contrario.

**`const T& elemento(nodo n) const`**  
**`T& elemento(nodo n)`**
- **Pre:** n es un nodo del árbol.
- **Post:** Devuelve el elemento del nodo n.

**`nodo raízB () const`**
- **Post:** Devuelve el nodo raíz del árbol. Si el árbol está vacío, devuelve NODO_NULO.

**`nodo padreB (nodo n) const`**
- **Pre:** n es un nodo del árbol.
- **Post:** Devuelve el padre del nodo n. Si n es el nodo raíz, devuelve NODO_NULO.

**`nodo hijoIzqdoB (nodo n) const`**
- **Pre:** n es un nodo del árbol.
- **Post:** Devuelve el nodo hijo izquierdo del nodo n. Si no existe, devuelve NODO_NULO.

**`nodo hijoDrchoB (nodo n) const`**
- **Pre:** n es un nodo de A.
- **Post:** Devuelve el nodo hijo derecho del nodo n. Si no existe, devuelve NODO_NULO.

## Implementacion

### Vectorial

```c++
#ifndef ABIN_VEC0_H
#define ABIN_VEC0_H
#include <cassert>

template <typename T> 
class Abin {
    public:
        typedef int nodo; //índice de la matriz
                          // entre 0 y maxNodos-1
        static const nodo NODO_NULO;
        explicit Abin(size_t maxNodos); // constructor
        void insertarRaizB(const T& e);
        void insertarHijoIzqdoB(nodo n, const T& e);
        void insertarHijoDrchoB(nodo n, const T& e);
        void eliminarHijoIzqdoB(nodo n);
        void eliminarHijoDrchoB(nodo n);
        void eliminarRaizB();
        ~Abin(); // destructor
        bool arbolVacioB() const;
        const T& elemento(nodo n) const; // acceso a elto, lectura
        T& elemento(nodo n); // acceso a elto, lectura/escritura
        nodo raizB() const;
        nodo padreB(nodo n) const;
        nodo hijoIzqdoB(nodo n) const;
        nodo hijoDrchoB(nodo n) const;
        Abin(const Abin<T>& a); // ctor. de copia
        Abin<T>& operator =(const Abin<T>& a); // asignación
    private:
        struct celda {
            T elto;
            nodo padre, hizq, hder;
        };
        celda *nodos; // vector de nodos
        int maxNodos; // tamaño del vector
        int numNodos; // número de nodos del árbol
};

/* Definición del nodo nulo */
template <typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

template <typename T>
inline Abin<T>::Abin(size_t maxNodos) :
nodos(new celda[maxNodos]),
maxNodos(maxNodos),
numNodos(0)
{}
template <typename T>
void Abin<T>::insertarRaizB(const T& e)
{
assert(numNodos == 0); // árbol vacío
numNodos = 1;
nodos[0].elto = e;
nodos[0].padre = NODO_NULO;
nodos[0].hizq = NODO_NULO;
nodos[0].hder = NODO_NULO;
}
```
