#include <iostream>
using namespace std;

int main () {

int numero, cont;

    cin >> numero;



    if(numero % 2 ==0){
   
        cont = numero;

        while(numero != 0){
            numero = numero -2;
            cont = cont + numero;
        }
        cout << cont;
    }

    else{
   
        cont = numero;

        while(numero != 0){
            numero = numero -2;
            cont =  cont + numero;
        }
        cout << cont;
    }


    return 0;
}
