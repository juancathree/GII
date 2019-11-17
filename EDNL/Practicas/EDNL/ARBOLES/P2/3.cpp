int evaluar(const Abin<string>& A){
	return evaluar_rec(A.raizB(),A);
}

int evaluar_rec(typename Abin<string>::nodo n. const Abin<string>& A){
	string actual = A.elemento(n);
	if(actual=="=") return evaluar_rec(A.hijoIzqdoB(n),A) = evaluar_rec(A.hijoDrchoB(n),A);
	else if(actual=="x") return evaluar_rec(A.hijoIzqdoB(n),A) * evaluar_rec(A.hijoDrchoB(n),A);
	else if(actual=="/") return evaluar_rec(A.hijoIzqdoB(n),A) / evaluar_rec(A.hijoDrchoB(n),A);
	else if(actual=="+") return evaluar_rec(A.hijoIzqdoB(n),A) + evaluar_rec(A.hijoDrchoB(n),A);
	else if(actual=="-") return evaluar_rec(A.hijoIzqdoB(n),A) - evaluar_rec(A.hijoDrchoB(n),A);
	else return stoi(actual);
}