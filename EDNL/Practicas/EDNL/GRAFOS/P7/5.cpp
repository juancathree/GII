template <typename tCoste>
vector<bool> CalcularDestinos(size_t alergico, int presupuesto, typename GrafoP<tCoste>::vertice origen,
 								const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2,const GrafoP<tCoste>& G3){
	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t n = G1.numVert();
 	GrafoP<tCoste> A(n);
 	switch(alergico){
 		case 1:{
 			for(vertice i = 0 ; i < n ; i++){
 				for(vertice j = 0 ; j < n ; j++){
 					if(G2[i][j] < G3[i][j]) A[i][j] = G2[i][j];
 					else A[i][j] = G3[i][j];
 				}
 			}
 			};break;
 		case 2:{
 			for(vertice i = 0 ; i < n ; i++){
 				for(vertice j = 0 ; j < n ; j++){
 					if(G1[i][j] < G3[i][j]) A[i][j] = G1[i][j];
 					else A[i][j] = G3[i][j];
 				}
 			}
 			};break;
 		case 3:{
 			for(vertice i = 0 ; i < n ; i++){
 				for(vertice j = 0 ; j < n ; j++){
 					if(G1[i][j] < G2[i][j]) A[i][j] = G1[i][j];
 					else A[i][j] = G2[i][j];
 				}
 			}
 			};break;
 	}
 	cout<<"Grafo resul: "<<A;
 	vector<vertice> vert(n);
 	vector<tCoste> vecDij = Dijkstra(A,origen,vert);
 	vector<bool> viajable(n,false);
 	for(vertice i = 0 ; i < n ; i++){
 		if(vecDij[i] != GrafoP<tCoste>::INFINITO && vecDij[i]<presupuesto){
 			viajable[i]=true;
 		}
 	}
 	return viajable;
}