ARBOL GENERAL
// Un árbol general se define como un árbol cuyos nodos son de cualquier
// grado, es decir, pueden tener un número cualquiera de hijos. Los hijos de un nodo
// están ordenados de izquierda a derecha, de tal forma que el primer hijo de un nodo
// se llama hijo izquierdo, el segundo es el hermano derecho de éste, el tercero es el
// hermano derecho del segundo y así sucesivamente.

1. VECTORIAL MEDIANTE LISTAS DE HIJOS
template <typename T>
class Agen {
	public:
		typedef int nodo; // índice de la matriz entre 0 y maxNodos-1
		static const nodo NODO_NULO;
		explicit Agen(size_t maxNodos); // ctor., requiere ctor. T()
		Agen(const Agen<T>& a); // ctor. de copia
		Agen<T>& operator =(const Agen<T>& a); // asignación de árboles
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(nodo n, const T& e);
		void insertarHermDrcho(nodo n, const T& e);
		void eliminarHijoIzqdo(nodo n);
		void eliminarHermDrcho(nodo n);
		void eliminarRaiz();
		bool arbolVacio() const;
		const T& elemento(nodo n) const; // acceso a elto, lectura
		T& elemento(nodo n); // acceso a elto, lectura/escritura
		nodo raiz() const;
		nodo padre(nodo n) const;
		nodo hijoIzqdo(nodo n) const;
		nodo hermDrcho(nodo n) const;
		~Agen(); // destructor
	private:
		struct celda {
			T elto;
			nodo padre;
			Lista<nodo> hijos;
		};
		celda *nodos; // vector de nodos
		int maxNodos; // tamaño del vector
		int numNodos; // número de nodos del árbol
};


2. CELDAS ENLAZADAS
template <typename T>
class Agen {
	struct celda;
	public:
		typedef celda* nodo;
		static const nodo NODO_NULO;
		Agen(); // ctor.
		Agen(const Agen<T>& a); // ctor. de copia
		Agen<T>& operator =(const Agen<T>& a); // asignación de árboles
		void insertarRaiz(const T& e);
		void insertarHijoIzqdo(nodo n, const T& e);
		void insertarHermDrcho(nodo n, const T& e);
		void eliminarHijoIzqdo(nodo n);
		void eliminarHermDrcho(nodo n);
		void eliminarRaiz();
		bool arbolVacio() const;
		const T& elemento(nodo n) const; // acceso a elto, lectura
		T& elemento(nodo n); // acceso a elto, lectura/escritura
		nodo raiz() const;
		nodo padre(nodo n) const;
		nodo hijoIzqdo(nodo n) const;
		nodo hermDrcho(nodo n) const;
		~Agen(); // destructor
	private:
		struct celda {
			T elto;
			nodo padre, hizq, heder;
			celda(const T& e, nodo p = NODO_NULO): elto(e), padre(p), hizq(NODO_NULO), heder(NODO_NULO) {}
		};
		nodo r; // nodo raíz del árbol
		void destruirNodos(nodo& n);
		nodo copiar(nodo n);
};