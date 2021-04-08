#include "ListaContigua.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaContigua::ListaContigua(int incremento = 10){
	this->vector = new int[incremento];
	this->capacidad = incremento;
	this->incremento = incremento;
	this->n = 0;	
}
		
ListaContigua::~ListaContigua(){
	delete [] vector;
}
		
int ListaContigua::getValor(int posicion){
	assertdomjudge(n>posicion);
	return vector[posicion];	
}
		
void ListaContigua::setValor(int posicion, int nuevoValor){
		assertdomjudge(n>posicion);
		vector[posicion] = nuevoValor;
}
		
int ListaContigua::getN(){
	return n;
}
		
int ListaContigua::getCapacidad(){
	return capacidad;
}		
		
void ListaContigua::insertar(int posicion, int nuevoValor){
	assertdomjudge(posicion<=n);
	n++;

	if(n > capacidad || posicion+1 > capacidad){
		capacidad += incremento;
		this->vector = (int*) realloc (vector, sizeof(int) * capacidad);
	}	
	
	if(posicion+1>n) n=posicion+1;
	
	memmove(vector+posicion+1, vector+posicion , sizeof(int)*(n-posicion-1));

	vector[posicion] = nuevoValor;
}
		
void ListaContigua::eliminar(int posicion){
	assertdomjudge(posicion < n);
	this->n--;
	
	memmove(vector+posicion, vector+posicion+1, sizeof(int)*(n-posicion));
			
	if(n <= (capacidad - 2*incremento)){
		capacidad -= incremento;
		this->vector = (int*) realloc (vector, sizeof(int)*capacidad);
	}
}
		
void ListaContigua::concatenar(ListaContigua *lista){
	if(this->n + lista->n > this->capacidad){
	
		this->capacidad += lista->capacidad;
		this->vector = (int*) realloc (vector, sizeof(int)*this->capacidad);
		
		memmove(vector+n, lista->vector,sizeof(int)*lista->n);
		
		this->n += lista->n;
		
	}else{
		memmove(this->vector+n, lista->vector, sizeof(int)*lista->n );
	}
	
}

int ListaContigua::buscar(int elementoABuscar){
	assertdomjudge(n>0);

	for(int i=0; i<n; i++)
		if( *(this->vector+i) == elementoABuscar) return i;
	return -1;

}




