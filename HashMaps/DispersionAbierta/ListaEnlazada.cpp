#include "ListaEnlazada.h"
#include "assertdomjudge.h"


Nodo* ListaEnlazada::getNodo(int posicion){
    assertdomjudge(posicion > -1 && posicion < this->n);
    Nodo *temp;
    temp = lista;

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
    this->posicionUltimoNodoAccedido = 0;
}

ListaEnlazada::~ListaEnlazada(){
    Nodo *temp;
    
    while(lista!=NULL){
        temp = lista;
        lista = lista->siguienteNodo;
        delete temp;
    }

}

Contacto ListaEnlazada::getValor(int posicion){
    assertdomjudge(posicion > -1 && posicion < this->n);
    if(this->posicionUltimoNodoAccedido == posicion) return punteroUltimoNodoAccedido->elemento;
    else if(this->posicionUltimoNodoAccedido+1 == posicion){
        posicionUltimoNodoAccedido++;
        punteroUltimoNodoAccedido = punteroUltimoNodoAccedido->siguienteNodo;
        return punteroUltimoNodoAccedido->elemento;
    }else if(this->posicionUltimoNodoAccedido-1 == posicion){
        posicionUltimoNodoAccedido--;
        punteroUltimoNodoAccedido = punteroUltimoNodoAccedido->anteriorNodo;
        return punteroUltimoNodoAccedido->elemento;
    }
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

    if(n==0){
        lista = nuevoContacto;
        nuevoContacto->siguienteNodo = nuevoContacto;
        nuevoContacto->anteriorNodo = nuevoContacto;
        punteroUltimoNodoAccedido = nuevoContacto;
    }else{
            nuevoContacto->siguienteNodo = getNodo(posicion);
            nuevoContacto->anteriorNodo = punteroUltimoNodoAccedido->anteriorNodo;
            punteroUltimoNodoAccedido->anteriorNodo = nuevoContacto;
            nuevoContacto->anteriorNodo->siguienteNodo = nuevoContacto;

            if(posicion == 0) lista = nuevoContacto;
            if(posicion == this->posicionUltimoNodoAccedido) punteroUltimoNodoAccedido = nuevoContacto;
    }

    this->n++;
}

void ListaEnlazada::eliminar(int posicion){ //Rehacer
    assertdomjudge(posicion > -1 && posicion < this->n);
    Nodo *temp = getNodo(posicion);

    temp->anteriorNodo->siguienteNodo = temp->siguienteNodo;
    temp->siguienteNodo->anteriorNodo = temp->anteriorNodo;

    if(posicion == 0) lista = temp->siguienteNodo;

    delete temp;

    this->n--;
}

int ListaEnlazada::buscar(Contacto elementoABuscar){
    Nodo *tempNodo;
    tempNodo = lista;
    Contacto tempContacto;

    for(int i=0; i<n; i++){
        tempContacto = tempNodo->elemento;
        if(tempContacto.telefono == elementoABuscar.telefono && tempContacto.nombre == elementoABuscar.nombre) return i;
        tempNodo = tempNodo->siguienteNodo;
    }
    return -1;

}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar){

}