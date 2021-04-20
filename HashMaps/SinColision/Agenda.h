#include<iostream>

class Agenda{
    int capacidad;
    std::string *nombres;
    long *telefonos;
    bool* ocupada;

    public:
    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion(long telefono);
    bool existeContacto(long telefono);
    std::string getContacto(long telefono);
    void introducirContacto(long telefono, std::string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
};