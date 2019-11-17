struct Casilla{
 Casilla()=default;
 Casilla(int f, int c):f(f),c(c){}
 int f,c;
};

struct pared{
 pared(bool arriba = false, bool derecha = false):arriba(arriba), derecha(derecha){}
 bool arriba,derecha;
};

int abs(int a){return (a>=0)?a:-a;}

typename GrafoP<int>::vertice CasillatoNodo(Casilla c, size_t N){ return c.f*N+c.c;}

Casilla nodotoCasilla(typename GrafoP<int>::vertice v, size_t N){ return Casilla(v/N,v%N);}

bool adyacente(Casilla c1, Casilla c2){return (abs(c1.f - c2.f) + abs(c1.c - c2.c)) == 1;}

template <typename tCoste>
Lista<Casilla> ResolverLaberinto(size_t N, matriz<pared> muros, Casilla origen, Casilla salida){
	size_t len = N*N;
	GrafoP<tCoste> G(len);
	typedef typename GrafoP<tCoste>::vertice vertice;
	cout<<"FUN"<<endl;
	//Generar el Laberinto:
	for(vertice i = 0 ; i < len ; i++){
		for(vertice j = 0; j < len ; j++){
			if(adyacente(nodotoCasilla(i,N),nodotoCasilla(j,N))){
 				G[i][j] = 1;
 				cout<<i<<" y "<<j<<" son adyacentes"<<endl;
 			}
 			else G[i][j] = GrafoP<tCoste>::INFINITO;
 		}
 		G[i][i] = 0; //El bucle de dentro lo pondrá a infinito, ahora se pone a 0
 	}
 	cout<<"El grafo ahora mismo es:\n"<<G;
 	matriz<vertice> vertices(len);
 	matriz<tCoste> Mfloyd = Floyd(G,vertices);
 	cout<<"FLYOD\n: "<<Mfloyd<<endl;
 	typename GrafoP<tCoste>::tCamino lista =
	camino<tCoste>(CasillatoNodo(origen,N),CasillatoNodo(salida,N),vertices);
 	cout<<"test1"<<endl;
 	typename Lista<vertice>::posicion p = lista.primera();
 	Lista<Casilla> listaC;
 	cout<<"Camino interno: \n"<<endl;
 	while(p != lista.fin()){
 		cout<<" "<<lista.elemento(p);
 		listaC.insertar(nodotoCasilla(lista.elemento(p),N),listaC.fin());
 		p = lista.siguiente(p);
 	}
 	cout<<endl;
 	return listaC;
}