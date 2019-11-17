int altura(const Abin<T>& A){
	return altura_rec(A.raizB(),A);
}

int altura_rec(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n==NODO_NULO) return -1;
	else return 1+max(altura_rec(A.hijoIzqdoB(n),A)+altura_rec(A.hijoDrchoB(n),A));
}

int max(int x, int y){
	return (x > y) ? x : y;
}