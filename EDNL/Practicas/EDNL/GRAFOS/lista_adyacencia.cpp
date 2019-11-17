class Grafo {
	public:
   		typedef size_t vertice;
   		explicit Grafo(size_t n): ady(n) {}
   		explicit Grafo(const std::string& nf);
   		size_t numVert() const {return ady.size();}
   		const Lista<vertice>& adyacentes(vertice v) const {return ady[v];}
   		Lista<vertice>& adyacentes(vertice v) {return ady[v];}
	private:
  	 	vector<Lista<vertice>> ady; // vector de listas de vértices
};