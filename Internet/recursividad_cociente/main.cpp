#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int cociente(int n, int m);

int main(int argc, char** argv) {
	
	int n,m;
	
	cout << "Inserta el dividendo: ";
	cin >> n;
	cout << "Inserta el divisor: ";
	cin >> m;
	
	cout << "El resultado es: " << cociente(n,m);
	
	return 0;
}

int cociente(int a, int b){

 if(a<b)
    return 0;
 else
    return 1+cociente(a-b,b);
    
}

