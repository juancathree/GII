template <typename tCoste>
tCoste CalcularViajeEj10(const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2, const GrafoP<tCoste>& G3,
 						typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
 						tCoste taxi1_2, tCoste taxi3, typename GrafoP<tCoste>::tCamino& ruta){
 	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t n = G1.numVert();
 	size_t len = 3*n;
 	// Desde G1 se podrá ir a cualquier ciudad por G1, a la estación del medio2 en la ciudad en la que
 	//se esté(oste taxi1_2) y a la estación de medio3 de la ciudad en la que se esté(coste taxi3)
 	//Construimos un Grafo gordo.
 	GrafoP<tCoste> A(len); //Inicializa a infinito todo
 	for(int i = 0 ; i < n ; i++){
 		//Para los costes de transbordo:
 		A[n+i][i] = A[i][n+i] = taxi1_2; //Transbordo entre medios 1 y 2
 		A[2*n+i][i] = A[i][2*n+1] = A[2*n+i][n+i] = A[n+i][2*n+i] = taxi3; //Costes 3-1,1-3,3-2,2-3
 		//Para los costes de cada medio de transporte
 		for(int j = 0 ; j < n ; j++){
 			A[i][j] = G1[i][j];
 			A[n+i][n+j] = G2[i][j];
 			A[2*n+i][2*n+j]= G3[i][j];
 		}
 	}
 	//Ahora que tengo el grafo inicializado, calculo los costes mínimos de ir desde origen1,origen2, origen3 a cualquiera
 	vector<vertice> verDij1(len),verDij2(len),verDij3(len);
 	vector<tCoste> vecDij1(len),vecDij2(len),vecDij3(len);
 	vecDij1 = Dijkstra(A,origen,verDij1);
 	vecDij2 = Dijkstra(A,origen+n,verDij2);
 	vecDij3 = Dijkstra(A,2*n+origen,verDij3);
 	//Busco primero cual es el coste mínimo partiendo de cada origen:
 	tCoste costemin1 = min(vecDij1[destino],min(vecDij1[destino+n],vecDij1[destino+2*n]));
 	tCoste costemin2 = min(vecDij2[destino],min(vecDij2[destino+n],vecDij2[destino+2*n]));
 	tCoste costemin3 = min(vecDij3[destino],min(vecDij3[destino+n],vecDij3[destino+2*n]));
 	//Calculamos el mínimo
 	tCoste costemin = min(costemin1,min(costemin2,costemin3));
 	//Calculamos la ruta con una función auxiliar
 	if(costemin==costemin1) ruta = calcularRuta(costemin, origen, destino, n, vecDij1, verDij1);
 	else if(costemin==costemin2) ruta = calcularRuta(costemin, origen+n, destino, n, vecDij2, verDij2);
 	else ruta = calcularRuta(costemin,origen+2*n, destino, n, vecDij3, verDij3);
 	//Ahora dejamos la ciudad en su valor original. En el tCamino aparecerá 2 veces una misma ciudad si es que se ha hecho transbordo
 	typename GrafoP<tCoste>::tCamino::posicion p = ruta.primera();
 	while(p != ruta.fin()){
 		ruta.elemento(p) = ruta.elemento(p) % n;
 		p = ruta.siguiente(p);
	}
 	return costemin;
}

template <typename tCoste>
typename GrafoP<tCoste>::tCamino calcularRuta(tCoste costemin, typename GrafoP<tCoste>::vertice origen,
 											typename GrafoP<tCoste>::vertice destino, size_t n, vector<tCoste> vecDij,
 											vector<typename GrafoP<tCoste>::vertice> verDij){
 	typename GrafoP<tCoste>::tCamino ruta;
 	if(vecDij[destino] < vecDij[destino+n]){
 		if(vecDij[destino] < vecDij[2*n+destino]){
 			ruta = camino<tCoste>(origen, destino, verDij);
 		}
 		else{
 			ruta = camino<tCoste>(origen, destino+2*n, verDij);
 		}
 	}
 	else{ //vecDij[destino+n] < vecDij[destino]
 		if(vecDij[destino+n] < vecDij[2*n+destino]){
 			ruta = camino<tCoste>(origen, destino+n, verDij);
 		}
 		else{
 			ruta = camino<tCoste>(origen, destino+2*n, verDij);
 		}
 	}
 	return ruta;
}