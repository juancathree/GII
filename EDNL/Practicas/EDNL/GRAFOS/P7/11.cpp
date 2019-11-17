//Guarda las coordenadas del puente( conecta c1 con c2 y c2 con c1)
struct puente{
 	puente() = default;
 	puente(size_t c1, size_t c2):c1(c1),c2(c2){}
 	size_t c1,c2;
};

template <typename tCoste>
matriz<tCoste> CalcularCostesEj11(const GrafoP<tCoste>& G1, const GrafoP<tCoste>& G2, 
								const GrafoP<tCoste>& G3,vector<puente> puentes){
 	typedef typename GrafoP<tCoste>::vertice vertice;
 	size_t N1 = G1.numVert(), N2 = G2.numVert(), N3 = G3.numVert();
 	size_t len = N1+N2+N3;
 	//Creamos un grafo que englobe todo
 	GrafoP<tCoste> A(len); //Al principio todo a INFINITO
 	for(int i = 0 ; i < N1 ; i++)
 		for(int j = 0 ; j < N1 ; j++) A[i][j] = G1[i][j];
 		
 	for(int i = 0 ; i < N2 ; i++)
 		for(int j = 0 ; j < N2 ; j++) A[i+N1][j+N1] = G2[i][j];
 	
 	for(int i = 0 ; i < N3 ; i++)
 		for(int j = 0 ; j < N3 ; j++) A[i+N1+N2][j+N1+N2] = G3[i][j];
 				
 	for(int i = 0 ; i < puentes.size() ; i++) 
 		A[puentes[i].c1][puentes[i].c2] = A[puentes[i].c2][puentes[i].c1] = 0; 
 		
 	matriz<vertice> verFloyd;
 	matriz<tCoste> Mfloyd = Floyd(A,verFloyd);
 	return Mfloyd;
}