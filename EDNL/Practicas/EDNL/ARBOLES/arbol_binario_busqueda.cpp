ARBOL BINARIO DE BUSQUEDA
// Un árbol binario de búsqueda es un árbol binario en el que los nodos
// almacenan elementos de un conjunto (no existen elementos repetidos). La
// propiedad que define a estos árboles es que todos los elementos almacenados en
// el subárbol izquierdo de cualquier nodo n son menores que el elemento de
// n, y todos los elementos almacenados en el subárbol derecho de
// n son mayores que el elemento almacenado en el mismo.
// Consideraremos que existe un orden lineal definido sobre el tipo de los
// elementos dado por el operador <.	

template <typename T> 
class Abb {
	public:
		Abb(); // constructor
		const Abb& buscar(const T& e) const;
		void insertar(const T& e);
		void eliminar(const T& e);
		bool vacio() const;
		const T& elemento() const;
		const Abb& izqdo() const;
		const Abb& drcho() const;
		Abb(const Abb& A); // ctor. de copia
		Abb& operator =(const Abb& A); // asig. árboles
		~Abb(); // destructor
	private:
		struct arbol {
			T elto;
			Abb izq, der;
			arbol(const T& e): elto(e) {}
		};
		arbol* r; // raíz del árbol
		T borrarMin();
		void copiar(const Abb& A);
};