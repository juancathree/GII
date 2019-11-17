template <typename tCoste>
bool esAciclico(const GrafoP<tCoste>& G){
 	matriz<tCoste> MfloydMOD = FloydMOD(G);
 	bool hayciclo = false;
 	for(int i = 0 ; i < G.numVert() && !hayciclo ; i++){
 		if(MfloydMOD[i][i] != GrafoP<tCoste>::INFINITO){
 			hayciclo=true;
 		}
 	}
 	return !hayciclo;
}

template <typename tCoste>
matriz<tCoste> FloydMOD(const GrafoP<tCoste>& G){
	size_t n = G.numVert();
	matriz<tCoste> costes(n);
	for(int i = 0 ; i < n ; i++){
 		//Aquí pondría que la posición anterior de i a cada nodo sea i: P[i] =vector<vertice>(n,i)
 		costes[i] = G[i];
 		//Dejamos que costes[i][i] sea infinito. Si al aplicarle floyd no es infinito es que ha encontrado un camino
 		//desde él mismo hasta sí mismo sin usar la autoarista => hay ciclo
 	}
 	for(int k = 0 ; k < n ; k++){
 		for(int i = 0 ; i < n ; i++){
 			for(int j = 0 ; j < n ; j++){
 				tCoste ikj = suma(costes[i][k],costes[k][j]);
 				if(ikj < costes[i][j]){
 					costes[i][j]=ikj;
 					//Aquí actualizaría el vector de posiciones P[i][j] = k
 				}
 			}
 		}
 	}
 	return costes;
}