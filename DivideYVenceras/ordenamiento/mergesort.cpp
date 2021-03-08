#include<iostream>
using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ])
{
	cout << "["<< a[0] << ", " << a[1] << "]  ";
	cout << "["<< b[0] << ", " << b[1] << "]";
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
		cout << "(" << c[i] << ")";
	}
	cout << "\n";
}


void ordenarMergeSort (int x[], int len)
{
	int temp[len];
	if(len == 1) return;
	else{
    	/*Ordenar dos mitades */
    	ordenarMergeSort(x, len/2);
		ordenarMergeSort(x+(len/2), len/2);      	
      	/*Combinar ambas mitades y guar;darlo en temp */
		combinar(x, len, x+(len/2)+1, len, temp);
      	/*Copiar del array temporal al array resultado */
      	for (int k = 0; k < len; k++){
	  		x[k] = temp[k];
	  		cout<<x[k]<<" ";
		}
      cout<<endl;
    }
}



int main()
{
 int n;
 cin>>n;
 int *x=new int[n];
 for(int i=0;i<n;i++)
   cin>>x[i];
 ordenarMergeSort(x,n);
}

