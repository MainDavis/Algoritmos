#include <iostream>
#include <cstdio>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition (int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
	int n, temp, *arr, cont, contLast, max, last;
	bool igual=true;
	cin >> n;
	while(n>0){
		cont=0;
		contLast=-1;
		last=-1;
		max=-1;
		arr = new int[sizeof(int)*n];
		
		for(int i=0; i<n; i++){
			cin>>temp;
			temp = temp%10;
			arr[i] = temp;
		}
		
		quickSort(arr, 0, n-1);

		for(int i=0; i<n; i++){
			if(arr[i]!=last){
				cont=0;
			}
			else{
				cont++;

				if(cont>contLast){
					igual=false;
					max=arr[i];
					contLast=cont;
				}else if(cont==contLast){
					igual=true;
				}
			}
			last=arr[i];
			//cout << "[" << arr[i] << ", " << cont << ", " << contLast << ", " << igual << "]\n";
		}
		if(igual || max==-1) cout << "VARIAS\n";
		else  cout << max << "\n";

		delete [] arr;

		cin >> n;
	}

	return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}