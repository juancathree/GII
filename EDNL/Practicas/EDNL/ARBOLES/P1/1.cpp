int numNodos(const Abin<T>& A){
	return numNodos_rec(A.raizB(),A);
}

int  numNodos_rec(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n==Abin<T>::NODO_NULO) return 0;
	else return 1+numNodos_rec(A.hijoIzqdoB(n),A)+numNodos_rec(A.hijoDrchoB(n),A);
}