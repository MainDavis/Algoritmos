#include <iostream>
#include <cmath>

using namespace std;

/*Calcula una aproximación de la raiz cuadrada del número dado
	Parámetro: Num->Número dado, Aprox->Margen de error, tempMin->Minimo valor del intérvalo donde se puede encontrar la solución, tempMax->Máximo valor del intérvalo donde se puede encontrar la solución.
	Retorno: Float, solución aproximada de la raiz.
	Precondicion: num>=0, aprox>0.
	Complejidad Temporal T(n): T(0)=1, T(1)=1, T(n)=T(n/2)+1
	Complejidad Espacial M(n): M(0)=1, M(1)=1, M(n)=M(n/2)+1
	Orden Temporal: O(log n)
	Orden Espacial: O(log n)
*/

float raiz(float num, float aprox, float tempMin, float tempMax);

int main(int argc, char** argv) {
	float num, aprox;
	cin >> num >> aprox;
	
	if(num>-1 && aprox>0) raiz(num, aprox, 0, num);
	else cout << "ERROR\n";
	
	return 0;
}


float raiz(float num, float aprox, float tempMin, float tempMax){
	
	float mid = (tempMin + tempMax)/2;
	float mid2 = pow(mid, 2);
	cout << mid <<  "\n";

	if(mid2>num-aprox && mid2<num+aprox ) return mid;
	else if(mid2 > num-aprox) return raiz(num, aprox, tempMin, mid);
	return raiz(num, aprox, mid, tempMax);
	
}
