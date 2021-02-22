#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

/*
	Descripción: Ordena el array de menor a mayor.
	Orden temporal: T().
	Orden espacial: O(1).
	Precondición: Ninguna.
*/

int* ordenar(int arr[], int n);

int main(int argc, char** argv) {
	int n;
	int *arr;
	
	cin >> n;
	arr = new int[n];
	
	for(int i=0; i<n; i++)
		cin >> arr[i];
		
	ordenar(arr, n);
	
	return 0;
}


int* ordenar(int arr[], int n){
	int temp;
	for(int i=1; i<n;i++){
		for(int j=0; j < n-i; j++){
			if(arr[j] > arr[j+1]){
				temp=arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		for(int k=0;k<n;k++)
			cout<<arr[k]<<" ";
      	cout<<endl;
    } 		
	return arr;
}
