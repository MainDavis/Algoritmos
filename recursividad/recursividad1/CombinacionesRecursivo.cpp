#include <iostream>

/*Calcular el factorial.
	Parámetro: n-> número a calcular el factorial.
	Retorno: long long, resultado de n!.
	Precondicion: n>=0, r>=0, n>r.
	Complejidad Temporal T(n): T(0)=1, T(n)=T(n-1)+1
	Complejidad Espacial M(n): M(0)=1, M(n)=T(n-1)+1
	Orden Temporal: O(n)
	Orden Espacial: O(n)
*/

long long factorial(long long n);

/*Calcula una combinacion
	Parámetro: n y r -> nCr.
	Retorno: long long, resultado de la combinacion de nCr.
	Precondicion: n>=0, r>=0, n>r.
	Complejidad Temporal T(n): T(1)=1, T(n)=2T(n-1)+1
	Complejidad Espacial M(n): M(1)=1, M(n)=2T(n-1)+1
	Orden Temporal: O(n)
	Orden Espacial: O(n)
*/

long long combinacion(long long n, long long r);

using namespace std;
int main(int argc, char** argv) {
	long long n,r;
	cin >> n >> r;
	
	while(n>-1){
		if(r>-1 && n > r-1)	cout << combinacion(n,r) << "\n";
		else cout << "ERROR\n";	
		
		cin >> n >> r;
	}
	return 0;
}

long long factorial(long long n){
	if(n==0) return 1;
	else return n*factorial(n-1);
}

long long combinacion(long long n, long long r){
	return factorial(n) / (factorial(r)*factorial(n-r));
}
