#include "Agenda.h"
#include "assertdomjudge.h"


Agenda::Agenda(int cantidad){
    this->capacidad = cantidad;
    this->n = 0;
    this->tabla = new ListaEnlazada[cantidad];
    for(int i=0; i<capacidad; i++)
        tabla[i] = ListaEnlazada();
}

Agenda::~Agenda(){

}

int Agenda::obtenerPosicion(long telefono){
    return telefono%capacidad;
}

bool Agenda::existeContacto(long telefono){
    int index = obtenerPosicion(telefono);
    int nNodos = tabla[index].getN();

    for(int i=0; i<nNodos; i++)
        if( tabla[index].getValor(i).telefono == telefono ) return true;
    return false;
}

string Agenda::getContacto(long telefono){
    int index = obtenerPosicion(telefono);
    int nNodos = tabla[index].getN();
    Contacto temp;

    for(int i=0; i<nNodos; i++){
        temp = tabla[index].getValor(i);
        if(temp.telefono == telefono) return temp.nombre;
    }

    return "";
}

void Agenda::introducirContacto(long telefono, string contacto){
    int index = obtenerPosicion(telefono);
    int nNodos = tabla[index].getN();

    Contacto nuevoContacto;
    nuevoContacto.nombre = contacto;
    nuevoContacto.telefono = telefono;
    tabla[index].insertar(0, nuevoContacto);

    this->n++;
}

void Agenda::eliminarContacto(long telefono){
    assertdomjudge(this->existeContacto(telefono))

    int index = obtenerPosicion(telefono);
    int nNodos = tabla[index].getN();

    Contacto contactoElim;

    for(int i=0; i<nNodos; i++){
        contactoElim = tabla[index].getValor(i);
        if(contactoElim.telefono == telefono){
            tabla[index].eliminar(i);
            return;
        }    
    }

}
