template <typename tCoste>
tCoste CalcularViaje(const GrafoP<tCoste>&G1, const GrafoP<tCoste>&G2, typename GrafoP<int>::vertice origen,
 					typename GrafoP<int>::vertice destino, typename GrafoP<int>::vertice cambio1,
 					typename GrafoP<int>::vertice cambio2, typename GrafoP<tCoste>::tCamino& ruta){
 	size_t n = G1.numVert();
 	typedef typename GrafoP<tCoste>::vertice vertice;
 	matriz<vertice> mvert1(n),mvert2(n);
 	matriz<tCoste> mfloyd1(n),mfloyd2(n);
 	mfloyd1 = Floyd(G1,mvert1);
 	mfloyd2 = Floyd(G2,mvert2);
 	tCoste costemin;
 	if(suma(mfloyd1[origen][cambio1], mfloyd2[cambio1][destino]) < suma(mfloyd1[origen][cambio2],mfloyd2[cambio2][destino])){
 		costemin = suma(mfloyd1[origen][cambio1], mfloyd2[cambio1][destino]);
 		ruta = camino<tCoste>(origen,cambio1,mvert1)+=camino<tCoste>(cambio1,destino,mvert2);
 	}
 	else{
 		costemin = suma(mfloyd1[origen][cambio2], mfloyd2[cambio2][destino]);
 		ruta = camino<tCoste>(origen,cambio2,mvert1) += camino<tCoste>(cambio2,destino,mvert2);
 	}
}