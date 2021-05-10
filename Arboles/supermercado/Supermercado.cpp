#include "Supermercado.h"
#include "assertdomjudge.h"
#include "cstdlib"
#include "cstring"

Supermercado::Supermercado(int n){
    this->n_cajas = n;
    this->cajas = new ColaPrioridad[n];
}

void Supermercado::nuevoUsuario(int n, int id){
    this->cajas[n].encolar(id);
}

void Supermercado::cerrarCaja(int n){
    assertdomjudge(n >= 0 && n < this->n_cajas);

    for(int i=0; !cajas[n].estaVacia(); i++){
        if(i == n) i++;
        if(i == n_cajas) i=0;
        cajas[i].encolar(cajas[n].desencolar());
    }
    
}

int Supermercado::atenderUsuario(int n){
    return this->cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
    return this->cajas[n].estaVacia();
}