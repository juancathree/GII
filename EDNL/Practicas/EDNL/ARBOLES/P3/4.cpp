Agen<T>::nodo buscar(const T& e, const Agen<T>& A){
	return buscar_rec(e,A.raiz(),A);
}

Agen<T>::nodo buscar_rec(const T& e,typename Agen<T>::nodo n, const Agen<T>& A){
	if(n == NODO_NULO) return n;
	else if(A.elemento(n)==e) return n;
	else{
		typename Agen<T>::nodo h = A.hijoIzqdo(n);
		typename Agen<T>::nodo maximo,resultado;
		maximo = buscar_rec(e,h,A);
		if(h!=NODO_NULO) h = A.hermDrcho(h);
		while(h != NODO_NULO && maximo == NODO_NULO){
			resultado = buscar_rec(e,h,A);
			if(resultado != NODO_NULO) maximo = resultado;
			h = A.hermDrcho(h);
		}
		return maximo;
	}
}

viud eliminardes(typename Agen<T>::nodo n, Agen<T>& A){
	if(n != NODO_NULO){
		typename Agen<T>::nodo h = A.hijoIzqdo(n);
		while(h!=NODO_NULO){
			eliminardes(h,A);
			h=A.hermDrcho(h);
			A.eliminarHijoIzqdo(n);
		}
	}
}

void Poda(const T& x, Agen<T>& A){
 	typename Agen<T>::nodo n = buscar(x,A);
 	typename Agen<T>::nodo p, h;
 	//Suponemos que siempre se encuentra el elemento x.
 	eliminardes(n,A);
 	if(n == A.raiz()) A.eliminarRaiz();
 	else{
 		p = A.padre(n);
 		h = A.hijoIzqdo(p);
 		if(h == n) A.eliminarHijoIzqdo(n);
 		else{
 			while(A.hermDrcho(h) != n){
 				h = A.hermDrcho(n);
 			}
			A.eliminarHermDrcho(h);
		}
	}
}