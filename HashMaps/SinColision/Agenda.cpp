#include <iostream>
#include "Agenda.h"
#include "assertdomjudge.h"

Agenda::Agenda(int capacidad){
    this->capacidad = capacidad;
    this->nombres = new std::string[capacidad];
    this->telefonos = new long[capacidad];
    this->ocupada = new bool[capacidad];
    for(int i=0; i<capacidad; i++){
        nombres[i] = "";
        telefonos[i] = 0;
        ocupada[i] = false;
    }
        
}

Agenda::~Agenda(){
    delete [] nombres;
    delete [] telefonos;
    delete [] ocupada;
}

int Agenda::obtenerPosicion(long telefono){
    return telefono%capacidad;
}

bool Agenda::existeContacto(long telefono){
    int index = obtenerPosicion(telefono);
    //return (telefonos[index] == telefono && ocupada[index]) ? true : false;
    return (ocupada[index] && telefonos[index] == telefono) ? true : false;
}

std::string Agenda::getContacto(long telefono){
    assertdomjudge(this->existeContacto(telefono));
    return nombres[this->obtenerPosicion(telefono)];
}

void Agenda::introducirContacto(long telefono, std::string contacto){
    assertdomjudge(telefono < 700000000 && telefono > 599999999);
    int index = this->obtenerPosicion(telefono);
    telefonos[index] = telefono;
    nombres[index] = contacto;
    ocupada[index] = true;
}

void Agenda::eliminarContacto(long telefono){
    assertdomjudge(this->existeContacto(telefono));
    ocupada[this->obtenerPosicion(telefono)] = false;
}