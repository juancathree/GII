Abin<T>& reflejado(const Abin<T>& A){
	Abin<T> B;
	if(A.raizB()!=NODO_NULO){
		B.insertarRaizB(A.elemento(A.raizB()));
		reflejado_rec(A.raizB(),A,B.raizB(),B);
	}
	return B;
}

void reflejado_rec(typename Abin<T>::nodo n, const Abin<T>& A, typename Abin<T>::nodo m, const Abin<T>& B){
	if(A.hijoIzqdoB(n)!=NODO_NULO){
		B.insertarHijoDrchoB(m,A.elemento(A.hijoIzqdoB(n)));
		reflejado_rec(A.hijoIzqdoB(n),A,B.hijoDrchoB(m),B);
	}
	if(A.hijoDrchoB(n)!=NODO_NULO){
		B.insertarHijoIzqdoB(m,A.elemento(A.hijoDrchoB(n)));
		reflejado_rec(A.hijoDrchoB(n),A,B.hijoIzqdoB(m),B);
	}
}