#include <iostream>
using namespace std;
 
int mayor(int a, int b, int c){ //Retorna el mayor de los tres
	int numero = a;
	
	if(b > numero)
		numero = b;
	if(c > numero)
		numero = c;
		
	return numero;
	
}
 
int main() 
{
    int input1=20, input2=5, input3=53;
    int maximo;
    int i;

 	i = mayor(input1, input2, input3);
    
    while ((i % input1 != 0) || (i % input2 != 0) || (i % input3 != 0))
        i++;
 
    cout << i;
 
    return 0;
}
