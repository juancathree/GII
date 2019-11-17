template <typename tCoste>
matriz<tCoste> CalcularCostesZuelandia(GrafoP<tCoste> B, 
										vector<typename GrafoP<tCoste>::vertice> ciudades, 
										vector<pair<typename GrafoP<tCoste>::vertice, typename GrafoP<tCoste>::vertice>> carreteras,
 										typename GrafoP<tCoste>::vertice capital){
	size_t n = B.numVert();
 	typename vector<typename GrafoP<tCoste>::vertice>::iterator it = ciudades.begin();
 	while(it != ciudades.end()){
 		B[*it] = vector<tCoste>(n,GrafoP<tCoste>::INFINITO);
 		it++;
 	}
 	typename vector<pair<typename GrafoP<tCoste>::vertice, typename GrafoP<tCoste>::vertice>>::iterator it2 = carreteras.begin();
	while(it2 != carreteras.end()){
 		B[it2->first][it2->second] = GrafoP<tCoste>::INFINITO;
 		it2++;
 	}
 	//Una vez tenemos el grafo actualizado según la situación de guerra, calculamos los costes minimos desde
 	//cualquier ciudad a la capital y de la capital a cualquier ciudad
 	vector<typename GrafoP<tCoste>::vertice> vCamino1, vCamino2;
 	vector<tCoste> costesCamino1,costesCamino2;
 	costesCamino1 = DijkstraInv(B,capital,vCamino1);
 	costesCamino2 = Dijkstra(B,capital,vCamino2);
 	matriz<tCoste> costes(n);
 	for(int i = 0 ; i < n ; i++){
 		for(int j = 0 ; j < n ; j++){
 			costes[i][j] = costesCamino1[i]+costesCamino2[j]; //Coste minimo de i a capital y de capital a j
 		}
 	}
 	//Como supongo que no tiene mucho sentido que para ir de i a i haya que pasar por la capital, pongo la diagonal principal a 0
 	for(int i = 0 ; i < n ; i++){
 		costes[i][i] = 0;
 	}
 	return costes;
}