int profundidad(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n==NODO_NULO) return -1;
	else return 1+profundidad(A.padreB(n),A);
}