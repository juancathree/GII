struct puente{
 	puente() = default;
 	puente(size_t c1, size_t c2):c1(c1),c2(c2){}
 	size_t c1,c2;
};

template <typename tCoste>
puente CalcularPuenteTercerIntento(const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2,
								vector<typename GrafoP<tCoste>::vertice>& costerasG1,
 								vector<typename GrafoP<tCoste>::vertice>& costerasG2){
 	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t N1 = G1.numVert(), N2 = G2.numVert();
 	matriz<vertice> m1,m2;
 	matriz<tCoste> Mfloyd1,Mfloyd2;
 	Mfloyd1 = Floyd(G1,m1);
 	Mfloyd2 = Floyd(G2,m2);
 	vertice c,c1,c2;
 	tCoste costemin = GrafoP<tCoste>::INFINITO,costeiter;
 	for(int i = 0 ; i < costerasG1.size() ; i++){
 		c = costerasG1[i];
 		costeiter=0;
 		for(int j = 0 ; j < N1 ; j++)costeiter=suma(costeiter,Mfloyd1[c][j]);
 		if(costeiter<costemin){
 			costemin=costeiter;
 			c1=c;
 		}
 	}
 	costemin = GrafoP<tCoste>::INFINITO;
 	for(int i = 0 ; i < costerasG2.size() ; i++){
 		c = costerasG2[i];
 		costeiter=0;
 		for(int j = 0 ; j < N2 ; j++)costeiter=suma(costeiter,Mfloyd2[c][j]);
 		if(costeiter<costemin){
 			costemin=costeiter;
 			c2=c;
 		}
 	}
 	cout<<"Va de "<<c1<<" en arch1 a "<<c2<<" en arch2"<<endl;
 	return puente(c1,c2);
}