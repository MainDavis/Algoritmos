#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
	int posA=0,posB=0;
  	for(int i=0; i<(len_a+len_b); i++){
  		
  		if(posA == len_a){
  			c[i]=b[posB];
  			posB++;
		}else if(posB == len_b){
			c[i]=a[posA];
			posA++;
		}else if(a[posA] < b[posB]){
			c[i]=a[posA];
			posA++;	
		}else{
			c[i]=b[posB];
			posB++;	
		}

	}
}


void ordenarMergeSort (int x[], int len)
{
	int temp[len];
	int mitad = len/2;
	if(len == 1) {
		return;
	}else{
    	/*Ordenar dos mitades */    	
		ordenarMergeSort(x, mitad);
		ordenarMergeSort(x+mitad, len-mitad);
    			    	
      	/*Combinar ambas mitades y guar;darlo en temp */
		combinar(x, mitad, x+(mitad), (len-mitad), temp);
      	/*Copiar del array temporal al array resultado */
      	for (int k = 0; k < len; k++){
	  		x[k] = temp[k];
	  		cout<<x[k]<<" ";
		}
      cout<<endl;
    }
}



int main(){
	int n;
	cin>>n;
	int *x=new int[n];
	for(int i=0;i<n;i++)
		cin>>x[i];
	if(n>0) ordenarMergeSort(x,n);
}

