#include "ListaEnlazada.h"

class Agenda{
	int capacidad;
	int n;
	ListaEnlazada *tabla;

	public:

	Agenda(int cantidad);
	~Agenda();
	int obtenerPosicion(long telefono);
	bool existeContacto(long telefono);
	string getContacto(long telefono);
	void introducirContacto(long telefono, string contacto);
	void eliminarContacto(long telefono);
	void imprimir();
};