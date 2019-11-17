ARBOL PARCIALMENTE ORDENADO
// Un árbol parcialmente ordenado (montículo) es un árbol completo en el que
// el valor en cualquier nodo es menor que el de todos sus descendientes, o
// sea, en un APO, para todo nodo X, el valor en el padre de X es menor o igual
// que el valor en X (con excepción de la raíz, que no tiene padre). 

template <typename T> 
class Apo {
	public:
		explicit Apo(size_t maxNodos); // constructor
		void insertar(const T& e);
		void suprimir();
		const T& cima() const;
		bool vacio() const;
		Apo(const Apo<T>& A); // ctor. de copia
		Apo<T>& operator =(const Apo<T>& A); // asignación de apo
		~Apo(); // destructor
	private:
		typedef int nodo; // índice del vector entre 0 y maxNodos-1
		T* nodos; // vector de nodos
		int maxNodos; // tamaño del vector
		nodo ultimo; // último nodo del árbol
		nodo padre(nodo i) const { return (i-1)/2; }
		nodo hIzq(nodo i) const { return 2*i+1; }
		nodo hDer(nodo i) const { return 2*i+2; }
		void flotar(nodo i);
		void hundir(nodo i);
};