#include <iostream>
#define MAX_TABLA 11
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void calcTabla(int **arr, int n); 

int main(int argc, char** argv) {
	int n,r;
	cin>>n>>r;
	
	int **arr;
	arr = new int*[MAX_TABLA];
	
	for(int i=1; i<MAX_TABLA+1; i++)
		arr[i-1] = new int[i];
	
	calcTabla(arr, 0);
	
	while(n>-1){
		if(n>=r){
			cout << arr[n][r] << "\n";
		}else{
			cout << "ERROR\n";
		}
		
		cin >> n >> r;
	}
	
	return 0;
}

void calcTabla(int **arr, int n){
	for(int r=0; r<n+1; r++){
		
		if(r==0) arr[n][r]=1;	
		else if(r==n) arr[n][r]=1;
		else arr[n][r] = arr[n-1][r-1] + arr[n-1][r];

	}
	
	if(n<MAX_TABLA-1) calcTabla(arr, n+1);
}
