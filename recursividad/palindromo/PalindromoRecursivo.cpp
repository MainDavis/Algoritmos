#include <iostream>
#include <string>
using namespace std;

bool palindromo(string input, int n);

int main(int argc, char** argv) {
	string input;
	cin >> input;
	cout << palindromo(input, input.length());
	
	return 0;
}

bool palindromo(string input, int n){
	int condicion;
	condicion=input.length()/2;
	if((n-1)==condicion){

		return (input[input.length()-n] == input[n-1]);
	}	
	else{
		return (palindromo(input, n-1) && (input[input.length()-n] == input[n-1]));
	} 
}

