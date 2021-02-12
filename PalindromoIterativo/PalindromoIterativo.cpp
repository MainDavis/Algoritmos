#include <iostream>
#include <string>

#define MAX_LENGTH 20

using namespace std;

bool analizarInput(string input){ //Funcion para comprobar si es un palindromo el input o no
	int longuitud = input.size();
	
	for(int i=0; i<longuitud/2; i++){
		if(input[i] != input[longuitud-i-1])
			return 0;
	}
	
	return 1;
}


int main(int argc, char** argv) {
	
	string input;
	
	cin >> input;
	
	if(input.size() < MAX_LENGTH+1)
		cout << analizarInput(input);
	
	return 0;
}
