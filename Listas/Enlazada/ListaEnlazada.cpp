#include "ListaEnlazada.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

using namespace std;

ListaEnlazada::ListaEnlazada(){
	n=0;
	lista = NULL;
}

Nodo* ListaEnlazada::getNodo(int posicion){
	assertdomjudge(posicion < n);
	
	Nodo *temp;
	temp = lista;
	for(int i=0; i<posicion; i++){
			temp = temp->siguienteNodo;
	}
	return temp;

}

ListaEnlazada::~ListaEnlazada(){
	Nodo *actual = lista;
	for(int i=0; actual!=NULL; i++){
		Nodo *siguiente = actual->siguienteNodo;
		delete actual;
		actual = siguiente;
	}
}

int ListaEnlazada::getValor(int posicion){
	assertdomjudge(posicion < n);
	return getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor){
	assertdomjudge(posicion < n);
	getNodo(posicion)->elemento=nuevoValor;
}

int ListaEnlazada::getN(){
	return n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor){
	
	assertdomjudge(posicion <= n);

	Nodo *temp = new Nodo;
	temp->elemento = nuevoValor;
	
	this->n++;
	
	if(lista==NULL){
		temp->siguienteNodo = NULL;
		this->lista = temp;
	}else if(posicion==n-1){
		temp->siguienteNodo = NULL;
		getNodo(posicion-1)->siguienteNodo = temp;
	}else{
		if(posicion==0){
			temp->siguienteNodo = lista;
			lista = temp;
		}else{
			Nodo *uso = getNodo(posicion-1);
			temp->siguienteNodo = uso->siguienteNodo;
			uso->siguienteNodo = temp;
		}
	}

}


void ListaEnlazada::eliminar(int posicion){
	assertdomjudge(posicion < n && posicion >= 0);
	n--;
	if(posicion == 0){
		lista = lista->siguienteNodo;
	}else if(posicion == n){
		Nodo *temp = getNodo(posicion-1);

		delete temp->siguienteNodo;

		temp->siguienteNodo = NULL;

	}else{
		Nodo *temp = getNodo(posicion-1);
		Nodo *temp2 = (temp->siguienteNodo)->siguienteNodo;

		delete temp->siguienteNodo;
	
		temp->siguienteNodo = temp2;

	}

}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){
	assertdomjudge(listaAConcatenar->n > 0);

	Nodo *temp;
	temp=lista;

	for(int i=0; i<n-1; i++)
		temp=temp->siguienteNodo;

	temp->siguienteNodo = listaAConcatenar->lista;

	n+=listaAConcatenar->n;
}

int ListaEnlazada::buscar(int elementoABuscar){ //Cambiar
	assertdomjudge( n > 0 );

	Nodo *actual = lista;
	
	for(int i=0; i<n; i++){
		if(actual->elemento == elementoABuscar) return i;
		actual = actual->siguienteNodo;
	}

	return -1;
}
