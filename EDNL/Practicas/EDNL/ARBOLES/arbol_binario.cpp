ARBOL BINARIO
// Un árbol binario se define como un árbol
// cuyos nodos son, a lo sumo, de grado 2, es
// decir, tienen 0, 1 ó 2 hijos. Éstos se llaman
// hijo izquierdo e hijo derecho.

1. VECTORIAL
template <typename T> 
class Abin{
	public:
		typedef int nodo; // índice de la matriz entre 0 y maxNodos-1
		static const nodo NODO_NULO;
		explicit Abin(size_t maxNodos); // constructor
		Abin(const Abin<T>& a); // ctor. de copia
		Abin<T>& operator =(const Abin<T>& a); // asignación
		void insertarRaizB(const T& e);
		void insertarHijoIzqdoB(nodo n, const T& e);
		void insertarHijoDrchoB(nodo n, const T& e);
		void eliminarHijoIzqdoB(nodo n);
		void eliminarHijoDrchoB(nodo n);
		void eliminarRaizB();
		bool arbolVacioB() const;
		const T& elemento(nodo n) const; // acceso a elto, lectura
		T& elemento(nodo n); // acceso a elto, lectura/escritura
		nodo raizB() const;
		nodo padreB(nodo n) const;
		nodo hijoIzqdoB(nodo n) const;
		nodo hijoDrchoB(nodo n) const;
		~Abin(); // destructor
	private:
		struct celda {
			T elto;
			nodo padre, hizq, hder;
		};
		celda *nodos; // vector de nodos
		int maxNodos; // tamaño del vector
		int numNodos; // número de nodos del árbol
};


2. ENLAZADA
template <typename T> 
class Abin{
	struct celda; // declaración adelantada privada
	public:
		typedef celda* nodo;
		static const nodo NODO_NULO;
		Abin(); // constructor
		Abin(const Abin<T>& a); // ctor. de copia
		Abin<T>& operator =(const Abin<T>& a); //asignación de árboles
		void insertarRaizB(const T& e);
		void insertarHijoIzqdoB(nodo n, const T& e);
		void insertarHijoDrchoB(nodo n, const T& e);
		void eliminarHijoIzqdoB(nodo n);
		void eliminarHijoDrchoB(nodo n);
		void eliminarRaizB();
		bool arbolVacioB() const;
		const T& elemento(nodo n) const; // acceso a elto, lectura
		T& elemento(nodo n); // acceso a elto, lectura/escritura
		nodo raizB() const;
		nodo padreB(nodo n) const;
		nodo hijoIzqdoB(nodo n) const;
		nodo hijoDrchoB(nodo n) const;
		~Abin(); // destructor
	private:
		struct celda {
			T elto;
			nodo padre, hizq, hder;
			celda(const T& e, nodo p = NODO_NULO): elto(e), padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
		};
		nodo r; // nodo raíz del árbol
		void destruirNodos(nodo& n);
		nodo copiar(nodo n);
};


3. POSICIONES RELATIVAS
	hizq(i) = 2i+1;
	hder(i) = 2i+2;
	padre(i) = (i-1)/2;