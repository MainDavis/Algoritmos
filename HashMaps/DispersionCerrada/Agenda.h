#include<iostream>
#include<string>

class Agenda{
    int capacidad;
    int n;
    string *nombres;
    long *telefonos;
    bool *vacias;
    bool *borradas;

    public:

    Agenda(int capacidad);
    ~Agenda();
    int obtenerPosicion(long telefono);
    int buscarContacto(long telefono);
    int buscarHueco(long telefono);
    bool isLlena();
    bool existeContacto(long telefono);
    string getContacto(long telefono);
    void introducirContacto(long telefono, string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
};