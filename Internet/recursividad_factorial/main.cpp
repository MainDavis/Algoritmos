#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

long long factorial(int n);

int main(int argc, char** argv) {
	
	int n;
	cout << "Inserte el numero: ";
	cin >> n;
	
	cout << factorial(n);
	
	return 0;
}

long long factorial(int n){
	if(n==1) return 1;
	else return n*factorial(n-1);	
}

