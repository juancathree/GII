template <typename T> 
class GrafoP {
   public:
      typedef T tCoste;
      typedef size_t vertice;
      typedef Lista<vertice> tCamino;
      static const tCoste INFINITO;
      struct vertice_coste {
         vertice v;
         tCoste c;
         bool operator ==(const vertice_coste& vc) const {return v == vc.v;}
      };
      GrafoP(size_t n): ady(n) {}
      GrafoP(const std::string& nf);
      size_t numVert() const {return ady.size();}
      const Lista<vertice_coste>& adyacentes(vertice v) const {return ady[v];}
      Lista<vertice_coste>& adyacentes(vertice v) {return ady[v];}
   private:
      vector<Lista<vertice_coste>> ady;
};