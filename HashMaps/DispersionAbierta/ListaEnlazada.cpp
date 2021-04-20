#include "ListaEnlazada.h"
#include "assertdomjudge.h"


Nodo* ListaEnlazada::getNodo(int posicion){
    assertdomjudge(posicion > -1 && posicion < this->n);
    Nodo *temp;
    temp = lista;

    if(this->posicionUltimoNodoAccedido == posicion) return this->punteroUltimoNodoAccedido;
    else if(this->posicionUltimoNodoAccedido+1 == posicion) return this->punteroUltimoNodoAccedido->siguienteNodo;
    else if(this->posicionUltimoNodoAccedido-1 == posicion) return this->punteroUltimoNodoAccedido->anteriorNodo;

    if(posicion>n/2){
        for(int i=0; i<n-posicion; i++)
            temp = temp->anteriorNodo;
    }else{
        for(int i=0; i<posicion; i++)
            temp = temp->siguienteNodo;
    }

    this->posicionUltimoNodoAccedido = posicion;
    this->punteroUltimoNodoAccedido = temp;

    return temp;   
}

ListaEnlazada::ListaEnlazada(){
    this->lista = NULL;
    this->n = 0;
    this->punteroUltimoNodoAccedido = NULL;
}

ListaEnlazada::~ListaEnlazada(){

}

Contacto ListaEnlazada::getValor(int posicion){
    assertdomjudge(posicion > -1 && posicion < this->n);
    return getNodo(posicion)->elemento;
}

void ListaEnlazada::setValor(int posicion, Contacto nuevoValor){
    assertdomjudge(posicion > -1 && posicion < this->n);
    getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getN(){
    return this->n;
}

void ListaEnlazada::insertar(int posicion, Contacto nuevoValor){
    assertdomjudge(posicion > -1 && posicion < this->n+1);
    Nodo *nuevoContacto = new Nodo();
    nuevoContacto->elemento = nuevoValor;

    

    if(this->n==0){
        this->lista = nuevoContacto;
        nuevoContacto->anteriorNodo = nuevoContacto;
        nuevoContacto->siguienteNodo = nuevoContacto;

        posicionUltimoNodoAccedido = 0;
        punteroUltimoNodoAccedido = nuevoContacto;
    }else if(posicion==0){
        nuevoContacto->siguienteNodo = getNodo(posicion);
        nuevoContacto->anteriorNodo = this->punteroUltimoNodoAccedido->anteriorNodo;
        this->punteroUltimoNodoAccedido->anteriorNodo->siguienteNodo = nuevoContacto;
        this->punteroUltimoNodoAccedido->anteriorNodo = nuevoContacto;
        this->lista = nuevoContacto;
    }else{
        nuevoContacto->anteriorNodo = getNodo(posicion-1);
        nuevoContacto->siguienteNodo = this->punteroUltimoNodoAccedido->siguienteNodo;
        this->punteroUltimoNodoAccedido->siguienteNodo->anteriorNodo = nuevoContacto;
        this->punteroUltimoNodoAccedido->siguienteNodo = nuevoContacto;
    }

    if(this->posicionUltimoNodoAccedido == posicion){
        //Hago un reset
        this->punteroUltimoNodoAccedido = lista;
        this->posicionUltimoNodoAccedido = 0;
    }

    this->n++;

}

void ListaEnlazada::eliminar(int posicion){
    assertdomjudge(posicion > -1 && posicion < this->n);
    Nodo *temp = getNodo(posicion);

    temp->anteriorNodo->siguienteNodo = temp->siguienteNodo;

    temp->siguienteNodo->anteriorNodo = temp->anteriorNodo;
    
    if(posicion==0) lista = this->punteroUltimoNodoAccedido;

    delete temp;

    this->n--;
}

int ListaEnlazada::buscar(Contacto elementoABuscar){
    Nodo *tempNodo;
    Contacto tempContacto;
    tempNodo = lista;

    for(int i=0; i<n; i++){
        tempContacto = tempNodo->elemento;
        if(tempContacto.telefono == elementoABuscar.telefono && tempContacto.nombre == elementoABuscar.nombre) return i;
        tempNodo = tempNodo->siguienteNodo;
    }
    return -1;

}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){

}