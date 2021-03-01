#include <iostream>
#include <cmath>

using namespace std;

float raiz(float n, float tempMin, float tempMax);

float num, aprox;

int main(int argc, char** argv) {
	
	cin >> num >> aprox;
	if(num>-1 && aprox>0) raiz(num/2, 0, num);
	else cout << "ERROR";
	
	return 0;
}

float raiz(float n, float tempMin, float tempMax){	
	float prop = pow(n,2)/num;

	cout << n << "\n";
	
	if( prop > 1-aprox && prop < aprox+1){	
		return n;
	}else if(prop > 1){
		return raiz( n - ((n-tempMin)/2) , tempMin, n);
	}else{
		return raiz( n + ((tempMax-n)/2), n, tempMax);
	}
	
}
