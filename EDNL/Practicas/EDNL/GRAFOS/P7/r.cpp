template <typename tCoste>
tCoste distribucion(GrafoP<tCoste>& G,
					typename GrafoP<tCoste>::vertice origen,
					size_t cant,
					const vector<size_t>& capacidades,
					const vector<double>& subvenciones,
					vector<size_t>& envios){
	size_t n = G.numVert();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(G[i][j]!=INFINITO) G[i][j] = G[i][j] * (1-subvenciones[j]);
		}
	}
	matriz<typename GrafoP<tCoste>::vertice> vert;
	matriz<tCoste> costes = Dijkstra(G,origen,ver);
	tCoste acum = 0;
	while(cant>0){
		tCoste minimo = GrafoP<tCoste>::INFINITO;
		vertice v;
		for(int i=0; i<n; i++){
			if(costes[i]<minimo && i!=origen && envio[i]==0){
				minimo = i;
				v = i;
			}
		}
		if(capacidades[v]>cant){
			envio[v] = cant;
			acum += cant*costes[v];
			cant =0;
		}
		else{
			envio[v] = capacidades[v];
			acum += costes[v]*capacidades[v];
			cant -= capacidades[v];
		}
	}
	return acum;
}