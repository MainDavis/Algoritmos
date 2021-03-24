#include <iostream>

using namespace std;

void devolverCambio(int *lista,  int input){
	const int cambio[] = {500, 200, 100, 50, 25, 10, 5, 1};	
	int cantidad;
	
	for(int i=0; i<8; i++){
		cantidad = input/cambio[i];
		lista[i] = cantidad;
		input -= cambio[i]*cantidad;
	}
}

int main(int argc, char** argv) {
	int lista[] = {0,0,0,0,0,0,0,0};
	int input; cin >> input;	
	
	while(input > -1){
		devolverCambio(lista, input);
		
		for(int i=0; i<8; i++){
			cout << lista[i] << " ";
			lista[i]=0; 				//Tambien la reseteo para el siguiente cambio
		}
		
		cout << "\n";
		
		cin >> input;
	}
		
	return 0;
}
