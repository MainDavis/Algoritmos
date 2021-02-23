#include <iostream>

using namespace std;

/*
	Descripción: Ordena el array de menor a mayor.
	Complejidad temporal: T( [n^2/2] + [n/2] + 1).
	Orden temporal: O(n^2).
	Orden espacial: O(1).
	Precondición: Ninguna.
*/

void ordenar(int arr[], int n);

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

void ordenar(int arr[], int n){
	int temp, min;
	for(int i=0; i<n; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(arr[min] > arr[j]){
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		
		for(int k=0;k<n;k++)
			cout<<arr[k]<<" ";
      	cout<<endl;  
	}
	
}

