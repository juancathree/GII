class Grafo {
	public:
   		typedef size_t vertice;
   		explicit Grafo(size_t n): ady(n, vector<bool>(n, false)) {}
   		explicit Grafo(const std::string& nf);
   		template <typename T> Grafo(const GrafoP<T>& G);
   		size_t numVert() const {return ady.size();}
   		const vector<bool>& operator [](vertice v) const {return ady[v];}
   		vector<bool>& operator [](vertice v) {return ady[v];}
   		bool esDirigido() const;
	private:
   		vector< vector<bool> > ady;
};