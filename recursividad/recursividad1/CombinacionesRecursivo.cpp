#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long factorial(long long n);
long long combinacion(long long n, long long r);

using namespace std;
int main(int argc, char** argv) {
	long long n,r;
	cin >> n >> r;
	
	while(n>-1){
		if(r>-1 && n > r -1	)	cout << combinacion(n,r) << "\n";
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
