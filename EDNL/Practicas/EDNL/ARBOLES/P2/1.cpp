bool similares(const Abin<T>& A, const Abin<T>& B){
	return similares_rec(A.raizB(),A,B.raizB(),B);
}

bool similares_rec(typename Abin<T>::nodo n, const Abin<T>& A, typename Abin<T>::nodo m, const Abin<T>& B){
	if(n==NODO_NULO && m==NODO_NULO) return true;
	else{
		if(n==NODO_NULO && m!=NODO_NULO || n!=NODO_NULO && m==NODO_NULO) return false;
		else return similares_rec(A.hijoIzqdoB(n),A,B.hijoIzqdoB(n),B) && similares_rec(A.hijoDrchoB(n),A,B.hijoDrchoB(n),B);
	}
}