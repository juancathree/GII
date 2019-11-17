template <typename tCoste>
tCoste CalcularCoste(const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2, typename GrafoP<tCoste>::vertice origen,
 					typename GrafoP<tCoste>::vertice destino){
 	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t n = G1.numVert();
 	vector<vertice> verDij1,verDijInv1,verDij2,verDijInv2;
 	vector<tCoste> vecDij1,vecDijInv1,vecDij2,vecDijInv2;
 	//Calculamos los costes de origen a todas las ciudades (Dijkstra) tanto en medio de transporte 1 como en 2
 	vecDij1 = Dijkstra(G1,origen,verDij1);
 	vecDij2 = Dijkstra(G2,origen,verDij2);
 	//Calculamos los costes de ir desde cualquier ciudad a destino (Dijkstra Inverso) en ambos casos
	vecDijInv1 = DijkstraInv(G1,destino,verDijInv1);
 	vecDijInv2 = DijkstraInv(G2,destino,verDijInv2);
 	//Ahora compruebo todos los posibles transbordos y me quedo con el menor
 	tCoste costemin = min(vecDij1[destino],vecDij2[destino]); //Inicializo costemin al coste mínimo directo
 	//Ahora compruebo si algún transbordo lo mejora
 	for(vertice i = 0 ; i < n ; i++){
 		if(i != origen && i != destino){
 			//Haciendo trasbordo de 1 a 2
 			if(suma(vecDij1[i],vecDijInv2[i]) < costemin) costemin = suma(vecDij1[i],vecDijInv2[i]);
 			//Haciendo transbordo de 2 a 1
 			if(suma(vecDij2[i],vecDijInv1[i]) < costemin) costemin = suma(vecDij2[i],vecDijInv1[i]);
 		}
 	}
 	return costemin;
}