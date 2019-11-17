bool pseudocompleto(const Abin<T>& A){
	int alt = altura_rec(A.raizB(),A)
	return pseudocompleto_rec(A.raziB(),A,0,alt-1);
}

bool pseudocompleto_rec(typename Abin<T>::nodo n, const Abin<T>& A, int prof, int pen){
	if(n==NODO_NULO) return true;
	else{
		bool resultado;
		if(prof==pen){
			if(A.hijoIzqdoB(n)==NODO_NULO && A.hijoDrchoB(n)==NODO_NULO ||
				A.hijoIzqdoB(n)!=NODO_NULO && A.hijoDrchoB(n)!=NODO_NULO)
				resultado=true;
			else resultado=false;
		}
		else resultado=true
		return resultado && pseudocompleto_rec(A.hijoDrchoB(n),A,prof+1,pen) && pseudocompleto_rec(A.hijoIzqdoB(n),A,prof+1,pen);
	}
}

int altura_rec(typename Abin<T>::nodo n, const Abin<T>& A){
	if(n==NODO_NULO) return -1;
	else return 1+max(altura_rec(A.hijoIzqdoB(n),A)+altura_rec(A.hijoDrchoB(n),A));
}

int max(int x, int y){
	return (x > y) ? x : y;
}