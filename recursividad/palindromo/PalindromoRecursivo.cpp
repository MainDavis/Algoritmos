#include <iostream>
#include <string>
using namespace std;

/*Función que mira si el string dado es palíndromo recursivamente.
	Parámetro: String a analizar, logitud del string (Al inicio). 
	Retorno: Boolean, verdadero si la palabra es un palíndromo.
	Precondicion: String.length() > 0.
	Complejidad Temporal T(n): T(1)=1, T(n)=T(n-2)+1
	Complejidad Espacial M(n): M(1)=1, M(n)=M(n-2)+1
	Orden Temporal: O(n)
	Orden Espacial: O(n)
*/

bool palindromo(string input, int n);

int main(int argc, char** argv) {
	string input;
	cin >> input;
	cout << palindromo(input, input.length());
	
	return 0;
}

bool palindromo(string input, int n){
	int condicion;
	condicion=(input.length())/2;
	if((n-1)==condicion){

		return (input[input.length()-n] == input[n-1]);
	}	
	else{
		return (palindromo(input, n-1) && (input[input.length()-n] == input[n-1])) ;
	} 
}

