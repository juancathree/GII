template <typename T> 
class GrafoP {
   public:
      typedef T tCoste;
      typedef size_t vertice;
      typedef Lista<vertice> tCamino;
      static const tCoste INFINITO;
      struct arista {
         vertice orig, dest;
         tCoste coste;
         explicit arista(vertice v = vertice(), vertice w = vertice(), tCoste c = tCoste()): orig(v), dest(w), coste(c) {}
         bool operator <(const arista& a) const {return coste < a.coste;}
      };
      explicit GrafoP(size_t n): costes(n, vector<tCoste>(n, INFINITO)) {}
      explicit GrafoP(const std::string& nf);
      GrafoP(const Grafo& G);
      size_t numVert() const {return costes.size();}
      const vector<tCoste>& operator [](vertice v) const {return costes[v];}
      vector<tCoste>& operator [](vertice v) {return costes[v];}
      bool esDirigido() const;
   private:
      vector<vector<tCoste>> costes;
};