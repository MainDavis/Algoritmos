#include<iostream>
using namespace std;

void imprimir(int arr[]);

int main(){
    int n[10] = {1,2,3,4,5,6,7,8,9,0};
    imprimir(n+1);
return 0;
}

void imprimir(int arr[]){
	cout << arr[0];
}
