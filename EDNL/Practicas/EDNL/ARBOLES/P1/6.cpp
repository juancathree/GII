int desequilibrio(const Abin<T>& A){
	return desequilibrio_rec(A.raizB(),A);
}

int desequilibrio_rec(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n==NODO_NULO) return -1;
	else{
		int d = abs(altura_rec(A.hijoIzqdoB(n),A)-altura_rec(A.hijoDrchoB(n),A));
		return max(d, desequilibrio_rec(A.hijoDrchoB(n),A), desequilibrio_rec(A.hijoIzqdoB(n),A));
	}
}

int altura_rec(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n==NODO_NULO) return -1;
	else return 1+max(altura_rec(A.hijoIzqdoB(n),A)+altura_rec(A.hijoDrchoB(n),A));
}

int max(int x, int y){
	return (x > y) ? x : y;
}

int max(int x, int y, int z){
	int res;
	res = (x > y) ? x : y;
	res = (res > z) ? res : z;
	return res;
}