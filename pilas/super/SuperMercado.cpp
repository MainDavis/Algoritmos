#include "Supermercado.h"
#include<iostream>

Supermercado::Supermercado(int n=1){
    this->cajas = new Cola[n];
    this->n_cajas = n;
}

Supermercado::~Supermercado(){
    delete [] this->cajas;
}

void Supermercado::nuevoUsuario(int n, int id){
    this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){

    for(int i=0; !this->cajas[n].estaVacia(); i++){
        if(i==n_cajas) i=0;
        if(i==n) i++;
        this->cajas[i].encolar(this->cajas[n].desencolar());
    }

}

int Supermercado::atenderUsuario(int n){
    return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
    return this->cajas[n].estaVacia();
}

