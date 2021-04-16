#include "Cola.h"
#include<iostream>

Cola::Cola(){
    this->principio = NULL;
    this->final = NULL;    
}

void Cola::encolar(int num){
    Nodo *cliente = new Nodo(num);

    if(principio == NULL){
        this->principio = cliente;
        this->final = cliente;
    }else{
        this->final->siguiente = cliente;
        this->final = cliente;
    }
}

int Cola::desencolar(){
    Nodo *cliente = this->principio;
    int valor = cliente->valor;

    if(cliente->siguiente == NULL){
        this->principio = NULL;
        this->final = NULL;
    }else{
        this->principio = cliente->siguiente;
    }
    delete cliente;
    return valor;

}

bool Cola::estaVacia(){
    return (this->principio==NULL);
}


int Cola::getPrincipio(){
    return this->principio->valor;
}
