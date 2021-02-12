#include <iostream>

using namespace std;

int sumaTotal(int input){ //Suma todos los numeros anteriores al dado por el input
	int suma=0;
	for(int i=0; i<input+1; i++){
		suma+=i;
	}
	return suma;
}



int main(int argc, char** argv) {
	int input;
	
	cin >> input;
	
	cout << sumaTotal(input);
	
	
	return 0;
}
