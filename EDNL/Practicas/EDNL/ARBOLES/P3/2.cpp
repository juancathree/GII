int profundidad(typename Agen<T>::nodo n, const Agen<T>& A){
	if(n==NODO_NULOS) return -1;
	else return 1+profundidad(A.padre(n),A);
}