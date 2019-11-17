template <typename tCoste>
tCoste TrabajoDiario(const GrafoP<tCoste>& G, vector<size_t> parte, typename GrafoP<int>::vertice capital){
	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t n = G.numVert();
 	tCoste distancia = 0;
 	//Calculamos los costes de capital a la ciudad:
 	vector<vertice> verDij(n),verDijInv(n);
 	vector<tCoste> vecDij, vecDijInv;
 	vecDij = Dijkstra(G,capital,verDij);
 	vecDijInv = DijkstraInv(G,capital,verDijInv);
 	cout<<"VEC DIJ: "<<vecDij<<endl;
 	cout<<"VEC DIJINV: "<<vecDijInv<<endl;
 	for(vertice i = 0 ; i < n ; i++){
 		distancia+=(parte[i]*vecDij[i]);
 		distancia+=(parte[i]*vecDijInv[i]);
 	}
 	return distancia;
}