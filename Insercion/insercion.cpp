#include <iostream>

using namespace std;

/*
	Descripción: Ordena el array de menor a mayor.
	Orden temporal: O().
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
	
	int temp, posMin;
	for(int i=1; i<n; i++){
		posMin=i;
		for(int j=i-1; j>-1; j--){
			if(arr[i]<arr[j]){
				posMin = j;
			}
		}

		//Hago el cambio;
		for(int k=i; k>posMin; k--){
			temp = arr[k];
			arr[k] = arr[k-1];
			arr[k-1] = temp;
		}
		
		for(int k=0;k<n;k++)
			cout<<arr[k]<<" ";
      	cout<<endl;
    }  

}