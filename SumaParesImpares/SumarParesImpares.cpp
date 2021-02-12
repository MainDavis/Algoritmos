#include <iostream>

using namespace std;

int sumaPares(int input){
	int sumaTotal=0;
	for(int i=2; i<input+2; i+=2){
		sumaTotal+=i;
	}
	return sumaTotal;
}

int sumaImpares(int input){
	int sumaTotal=0;
	for(int i=1; i<input+2; i+=2){
		sumaTotal+=i;
	}
	return sumaTotal;
}

int main(int argc, char** argv) {
	int input;
	
	cin >> input;

	if((input%2)==0){
		cout << sumaPares(input);
	}else{
		cout << sumaImpares(input);
	}
	
	return 0;
}
