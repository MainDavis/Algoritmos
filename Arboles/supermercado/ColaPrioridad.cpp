#include "ColaPrioridad.h"
#include "assertdomjudge.h"


void ColaPrioridad::encolar(int nuevoElemento){
    vector.insertarAlFinal(nuevoElemento); // n
    int index = vector.getN()-1;
    bool continuar=true;

    //Hay que poner que mientras tenga padre lo hago
    while( index > 0 && continuar){ //n

        if(index & 1){ //Si es impar
            int temp = vector.getValor( (index-1)/2 );  //1
            if(nuevoElemento < temp){
                vector.setValor(index, temp);
                index = (index-1)/2;
                vector.setValor(index, nuevoElemento);
            }else continuar=false;

        }else{ // Si es par
            int temp = vector.getValor( (index/2)-1 ); //1
            if(nuevoElemento < temp){
                vector.setValor(index, temp);
                index = (index/2)-1;
                vector.setValor(index, nuevoElemento);
            }else continuar=false;
        }   
    }
}

int ColaPrioridad::desencolar(){ //O(log n) M(1)
    assertdomjudge(!this->estaVacia());

    int valor = vector.getValor(0); //1
    vector.setValor(0, vector.getValor( vector.getN()-1 )); //1
    vector.eliminarAlFinal(); // 1
    if(vector.getN() != 0) this->reestructurar(); //Log n + 1

    return valor;
}

bool ColaPrioridad::estaVacia(){
    return (vector.getN() == 0) ? true : false; 
}

void ColaPrioridad::reestructurar(){ // M(0) T(n) = Log n +1
    int index = 0;
    int valor = vector.getValor(0);
    bool continuar = (vector.getN()!=1) ? true : false;
    
    int posicionHijoIzquierda = 1;
    int posicionHijoDerecha = 2;

    int vectorN = vector.getN();

    while(continuar){ //Log N
        if(posicionHijoIzquierda < vectorN){
            if(posicionHijoDerecha < vectorN){ //Si tiene los dos hijos
                if(vector.getValor(posicionHijoIzquierda) <= vector.getValor(posicionHijoDerecha)){ //Si el de la izquierda es menor que el de la derecha
                    if(vector.getValor(posicionHijoIzquierda) < valor){
                        vector.setValor(index, vector.getValor(posicionHijoIzquierda));
                        index = (2*index)+1;
                        vector.setValor(index, valor);
                    }else continuar = false;
                }else{  //Si el de la derecha es menor que el de la izquierda
                    if(vector.getValor(posicionHijoDerecha) < valor){
                        vector.setValor(index, vector.getValor(posicionHijoDerecha));
                        index = (2*index)+2;
                        vector.setValor(index, valor);
                    }else continuar = false;
                }
                posicionHijoIzquierda = (2*index)+1;
                posicionHijoDerecha = posicionHijoIzquierda + 1;
            }else{  //Si solo tiene el hijo de la izquierda
                if(vector.getValor(posicionHijoIzquierda) < valor){
                        vector.setValor(index, vector.getValor(posicionHijoIzquierda));
                        index = (2*index)+1;
                        vector.setValor(index, valor);
                }
                continuar = false;
            }
        }else continuar = false;    //Si no tiene ningún hijo
    }
}