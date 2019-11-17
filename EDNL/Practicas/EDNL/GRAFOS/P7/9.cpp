template <typename tCoste>
tCoste CalcularViajeEj9(const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2, tCoste taxi,
						typename GrafoP<tCoste>::vertice origen,
 						typename GrafoP<tCoste>::vertice destino, 
 						typename GrafoP<tCoste>::tCamino& ruta){
 	size_t n = G1.numVert();
 	size_t len = n+n;
 	typedef typename GrafoP<tCoste>::vertice vertice;
	//Creamos el nuevo grafo
 	GrafoP<tCoste> A(len); //Por defecto todo infinito
 	for(int i = 0 ; i< n ; i++){
 		A[n+i][i] = A[i][n+i] = taxi;
 		for(int j = 0 ; j < n ; j++){
 			A[i][j] = G1[i][j];
 			A[n+i][n+j] = G2[i][j];
 		}
 	}
 	//Ahora tengo que calcular el mínimo de origen1 a destino1, de origen1 a destino2,
 	// de origen2 a destino1 y de origen2 a destino2 (los 1 son los normales, los 2 sumándole n)
 	vector<vertice> verDij1(len), verDij2(len);
 	vector<tCoste> vecDij1(len), vecDij2(len);
 	//Primero, de origen1 a todos(entre ellos destino1 y destino2)
 	vecDij1 = Dijkstra(A,origen,verDij1);
 	//Ahora de origen2 a todos(entre ellos destino1 y destino2)
	vecDij2 = Dijkstra(A,origen+n,verDij2);
	//Busco el mínimo de todos
 	tCoste costemin = min(min(vecDij1[destino],vecDij1[destino+n]),min(vecDij2[destino],vecDij2[destino+2]));
 	//Ahora compruebo a ver de dónde he sacado ese costemin
 	if(vecDij1[destino] == costemin){
 		ruta = camino<tCoste>(origen,destino,verDij1);
 	}
 	else if(vecDij1[destino+n] == costemin){
 		ruta = camino<tCoste>(origen,destino+n,verDij1);
 	}
 	else if(vecDij2[destino] == costemin){
 		cout<<3<<endl;
 		ruta = camino<tCoste>(origen+n,destino,verDij2);
 	}
 	else{ //vecDij2[destino+n] == costemin
 		cout<<4<<endl;
 		ruta = camino<tCoste>(origen+n,destino+n,verDij2);
 	}
 	typename GrafoP<tCoste>::tCamino::posicion p = ruta.primera();
 	//NOTA: SE VA A DEJAR QUE APAREZCA EN LA LISTA 2 VECES SEGUIDAS UN MISMO NODO PARA INDICAR QUE SE
 	//HA HECHO UN TRANSBORDO EN ESA CIUDAD. SI NO SE QUISIERA ASÍ, AL IGUAL QUE SE RECORRE LA LISTA
 	//HACIENDO %n, SE PODRÍA ELIMINAR UN NODO CUANDO APAREZCA 2 VECES SEGUIDO EL MISMO
 	while(p != ruta.fin()){
 		ruta.elemento(p) = ruta.elemento(p) % n; //Para dejar los nodos en su valor original
 		p = ruta.siguiente(p);
 	}
 	return costemin;
}