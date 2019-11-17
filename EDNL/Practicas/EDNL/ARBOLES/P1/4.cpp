int profundidad(typename Abin<T>::nodo n){
	if(n==NODO_NULO) return -1;
	else return 1+profundidad(nodos[n].padre);
}

int altura(typename Abin<T>::nodo n){
	if(n==NODO_NULO) return -1;
	else return 1+max(altura(nodos[n].hizq),altura(nodos[n].hder));
}