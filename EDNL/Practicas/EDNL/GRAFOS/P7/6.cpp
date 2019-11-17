template <typename tCoste>
matriz<tCoste> CalculaCostes(const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2, typename GrafoP<tCoste>::vertice cambio){
 	size_t n = G1.numVert();
 	typedef typename GrafoP<tCoste>::vertice vertice;
 	matriz<tCoste> costesfinales(n), costes(n);
 	matriz<vertice> vertfloyd(n);
 	//Inicializo la matriz con los costes de ir todo con G1 y luego la modifico si es necesario
 	costesfinales= Floyd(G1,vertfloyd);
 	//Ahora veamos si viajando todo en G2, mejora en algo
 	costes = Floyd(G2,vertfloyd);
 	for(vertice i = 0 ; i < n ; i++){
 		for(vertice j = 0 ; j < n ; j++){
 			if(costes[i][j] < costesfinales[i][j]) costesfinales[i][j] = costes[i][j];
 		}
 	}
 	vector<tCoste> Dij(n),DijInv(n);
 	vector<vertice> vertDij;
 	//Veamos el caso de ir en G1 hasta cambio y luego en G2
	DijInv = DijkstraInv(G1,cambio,vertDij);
 	Dij = Dijkstra(G2,cambio, vertDij);
 	for(vertice i = 0 ; i < n ; i++){
 		for(vertice j = 0 ; j < n ; j++){
 			if(costesfinales[i][j] > suma(DijInv[i],Dij[j])) costesfinales[i][j] = suma(DijInv[i],Dij[j]);
 		}
 	}
 	//Primero en G1 hasta cambio y luego en G2
 	DijInv = DijkstraInv(G2,cambio,vertDij);
 	Dij = Dijkstra(G1,cambio, vertDij);
 	for(vertice i = 0 ; i < n ; i++){
 		for(vertice j = 0 ; j < n ; j++){
 			if(costesfinales[i][j] > suma(DijInv[i],Dij[j])) costesfinales[i][j] = suma(DijInv[i],Dij[j]);
 		}
 	}
 	return costesfinales;
}