#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;



void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupada[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}


