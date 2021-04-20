#include<iostream>
#include<string>

class Agenda{
    int capacidad;
    int n;
    std::string *nombres;
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
    std::string getContacto(long telefono);
    void introducirContacto(long telefono, std::string contacto);
    void eliminarContacto(long telefono);
    void imprimir();
};