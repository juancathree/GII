template <typename tCoste>
tCoste DistribuirProducto(GrafoP<tCoste> G, 
						typename GrafoP<tCoste>::vertice origen, 
						size_t cant,
 						const vector<double>& subvenciones, 
 						const vector<size_t>& capacidades, 
 						vector<size_t>& envio){
	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t n = G.numVert();
	//Primero hay que calcular los costes con la subvencion. Se hace en G (para eso se recibe por copia)
 	for(vertice i = 0 ; i < n ; i++){
 		for(vertice j = 0 ; j < n ; j++){
 			if(G[i][j] != GrafoP<tCoste>::INFINITO) G[i][j] = G[i][j] * (1-subvenciones[j]);
 		}
 	}
 	cout<<"Grafo tras subvenciones: "<<G<<endl;
 	//Ahora determinaremos los costes mínimos desde origen hasta las otras ciudades => Dijkstra
 	vector<vertice> verticesDij(n);
 	vector<tCoste> vecDij = Dijkstra(G,origen,verticesDij);
 	cout<<"VEC DIJ: "<<endl;
 	for(vertice i = 0 ; i < n ; i++){
 		cout<<" "<<vecDij[i];
 	}
 	cout<<endl;
 	//A continuación, se determinan cuantas unidades enviar a cada ciudad:
 	tCoste acum = 0;
 	while(cant > 0){
 		tCoste minimo = GrafoP<tCoste>::INFINITO;
 		vertice v;
 		for(vertice i = 0 ; i < n ; i++){
 			if(i != origen && envio[i] == 0 && vecDij[i]<minimo){
 				minimo = i;
 				v = i;
 			}
 		}
		//Una vez seleccionada la ciudad, se le envían todos los que se puedan
		if(capacidades[v] > cant){
 			envio[v]=cant;
 			acum+=(cant*vecDij[v]);
 			cant=0;
 		}
 		else{
 			envio[v] = capacidades[v];
 			acum+=(cant*capacidades[v]);
 			cant-=capacidades[v];
 		}
 	}
 	return acum;
}