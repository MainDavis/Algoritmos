#include"ListaCircular.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

ListaCircular::ListaCircular(){
    this->lista = NULL;
    this->n = 0;
}

ListaCircular::~ListaCircular(){

}

Nodo *ListaCircular::getNodo(int posicion){
    
    Nodo *temp = new Nodo();
    temp = lista;
    for(int i=0; i<posicion; i++){
        temp = temp->siguienteNodo;
    }
    return temp;
}

void ListaCircular::insertar(int posicion, string nuevoValor){
    assertdomjudge(posicion==0 || posicion==n);
    Nodo *temp = new Nodo();
    temp->elemento = nuevoValor;
    

    if(posicion==0){
        if(n==0){
            temp->siguienteNodo = temp;
            temp->anteriorNodo = temp;
            lista = temp;
        }else{
            temp->siguienteNodo = lista;
            temp->anteriorNodo = lista->anteriorNodo;
            lista->anteriorNodo = temp;
            lista = temp;
        }
    }else if(posicion==n-1){
        temp->anteriorNodo = lista->anteriorNodo;
        temp->siguienteNodo = lista;
        lista->anteriorNodo = temp;
        temp->anteriorNodo->siguienteNodo = temp;

    }else{
        temp->anteriorNodo = getNodo(posicion-1);
        temp->siguienteNodo = temp->anteriorNodo->siguienteNodo;
        temp->anteriorNodo->siguienteNodo = temp;
        temp->siguienteNodo->anteriorNodo = temp;
    }
    n++;
}

void ListaCircular::setValor(int posicion, string nuevoValor){
    getNodo(posicion)->elemento = nuevoValor;
}

int ListaCircular::getN(){
    return this->n;
}

void ListaCircular::girar(int p){
    assertdomjudge(n>0);
    Nodo *temp = new Nodo();
    temp = lista;
    if(p>0){
        for(int i=0; i<p; i++)
            temp = temp->siguienteNodo;
    }else if(p<0){
        for(int i=0; i>p; i--)
            temp = temp->anteriorNodo;
    }
    lista = temp;
}

string ListaCircular::getValor(int posicion){
    assertdomjudge(n>0);
    string valor;
    valor = getNodo(posicion)->elemento;

    //this->eliminar(0);

    return valor;
}

void ListaCircular::eliminar(int posicion){

    if(posicion==0){
        lista->anteriorNodo->siguienteNodo = lista->siguienteNodo;
        lista->siguienteNodo->anteriorNodo = lista->anteriorNodo;
        lista = lista->siguienteNodo;
    }
    n--;

}



/* 
void ListaCircular::imprimir(){
    Nodo *temp = new Nodo();
    temp = lista;
    for(int i=0; i<n; i++){
        cout << temp->elemento << "-";
        temp = temp->siguienteNodo;
    }
} */

