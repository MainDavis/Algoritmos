#include <iostream>
#include <cstdlib>


using namespace std;

struct Nodo
{
	int elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
};


class intento{
	Nodo *lista;
	int n;
	
	public:
		intento(int x=0){
			lista=NULL;
			n=0;
		}
		
		void crear(int x){
			
			if(lista==NULL){
				Nodo *temp = new Nodo;
				temp->elemento = x;
				temp->siguienteNodo = NULL;
				lista = temp;
			}
		
		}
		
		void imprimir(){
			cout << lista->elemento;
		}		
	
	
};

int main(int argc, char** argv) {
	
	intento *ye = new intento(3);
	ye->crear(10);
	ye->imprimir();
	
	return 0;
}

