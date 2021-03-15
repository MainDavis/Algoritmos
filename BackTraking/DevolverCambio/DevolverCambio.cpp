#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void devolverCambio(int *lista,  int input){
	int cambio[] = {500, 200, 100, 50, 25, 10, 5, 1};
	int restante = input;
	int sum=0;
	int contador=0;
	
	for(int i=0; i<8; i++){
		while(restante/cambio[i]>=1){
			contador++;
			restante -= cambio[i];
		}
		lista[i]=contador;
		contador=0;
	}
	
	
}

int main(int argc, char** argv) {
	int lista[] = {0,0,0,0,0,0,0,0};
	int input; cin >> input;
	
	
	while(input > -1){
		devolverCambio(lista, input);
		for(int i=0; i<8; i++){
			cout << lista[i] << " ";
			//Tambien la reseteo para el siguiente cambio
			lista[i]=0;
		}
		cout << "\n";
		
		cin >> input;
	}
		
	return 0;
}
