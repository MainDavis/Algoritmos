#include "Agenda.h"
#include "assertdomjudge.h"
#include <string>

Agenda::Agenda(int capacidad){
    this->capacidad = capacidad;
    this->n = 0;
    this->nombres = new std::string[capacidad];
    this->telefonos = new long[capacidad];
    this->vacias = new bool[capacidad];
    this->borradas = new bool[capacidad];

    for(int i=0; i<capacidad; i++){
        nombres[i] = "";
        telefonos[i] = 0;
        vacias[i] = true;
        borradas[i] = false;
    }
}

Agenda::~Agenda(){
    delete [] nombres;
    delete [] telefonos;
    delete [] vacias;
    delete [] borradas;
}

int Agenda::obtenerPosicion(long telefono){
    return telefono%capacidad;
}

int Agenda::buscarContacto(long telefono){
    assertdomjudge(this->existeContacto(telefono));
    for(int i = this->obtenerPosicion(telefono); i<capacidad && (!vacias[i] || borradas[i]); i++)
        if(telefonos[i]==telefono) return i;
    return -1;
}

int Agenda::buscarHueco(long telefono){
    int i = this->obtenerPosicion(telefono);
    while(!vacias[i] && i<capacidad+1) i++;
    return i;
}

bool Agenda::isLlena(){
    return (n==capacidad) ? true : false;
}

bool Agenda::existeContacto(long telefono){
    for(int i = this->obtenerPosicion(telefono); i<capacidad && (!vacias[i] || borradas[i]); i++)
        if(telefonos[i]==telefono && !vacias[i]) return true;
    return false;
}

std::string Agenda::getContacto(long telefono){
    assertdomjudge(this->existeContacto(telefono));
    for(int i = this->obtenerPosicion(telefono); i<capacidad && (!vacias[i] || borradas[i]); i++)
        if(telefonos[i]==telefono && !vacias[i]) return nombres[i];
    return "default";
}

void Agenda::introducirContacto(long telefono, std::string contacto){
    int index = this->buscarHueco(telefono);
    assertdomjudge(!this->isLlena() && index!=-1);
    
    this->nombres[index] = contacto;
    this->telefonos[index] = telefono;
    this->vacias[index] = false;
    this->borradas[index] = false;

    this->n++;
}

void Agenda::eliminarContacto(long telefono){
    int index = buscarContacto(telefono);
    assertdomjudge(index != capacidad); //Si devuelve capacidad es que no hay hueco

    this->vacias[index] = true;
    this->borradas[index] = true;

    this->n--;
}

