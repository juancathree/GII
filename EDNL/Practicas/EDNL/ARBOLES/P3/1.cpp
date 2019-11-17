int numhijos(typename Agen<T>::nodo n, const Agen<T>& A){
	if(n==NODO_NULO) return 0;
	else return 1+numhijos(A.hermDrcho(n),A);
}

int grado(const Agen<T>& A){
	return grado_rec(A.raizB(),A);
}

int grado_rec(typename Agen<T>::nodo n, const Agen<T>& A){
	if(n==NODO_NULO) return 0;
	else{
		typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
		int nhijos,resultado;
		int grado = 0;
		while(hijo!=NODO_NULO){
			grado = max(grado,grado_rec(hijo,A));
			hijo = A.hermDrcho(n);
		}
		nhijos = numhijos(n,A);
		return max(grado,nhijos);
	}
}