#include <iostream>

using namespace std;

void  combinar (int a[ ] , int len_a , int b[ ] , int len_b , int c[ ]);
void ordenarMergeSort (int x[], int len);
int buscarParejas(int *pilas, int npilas, int objetivo);

int main(){
    int nCasos, nPilas, volNecesarios;
    int *voltPilas;
    cin >> nCasos;

    for(int i=0; i<nCasos; i++){
        cin >> nPilas;
        cin >> volNecesarios;
        voltPilas = new int[nPilas];
        for(int i=0; i<nPilas; i++){
            cin >> voltPilas[i];
        }
        //Los ordeno
        ordenarMergeSort(voltPilas, nPilas);
        cout << buscarParejas(voltPilas, nPilas, volNecesarios);
    }

    return 0;
}

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
	
	int mitad = len/2;
	if(len == 1) {
		return;
	}else{
    	/*Ordenar dos mitades */    	
		ordenarMergeSort(x, mitad);
		ordenarMergeSort(x+mitad, len-mitad);
    	int temp[len]; 	
      	/*Combinar ambas mitades y guar;darlo en temp */
		combinar(x, mitad, x+(mitad), (len-mitad), temp);
      	/*Copiar del array temporal al array resultado */
      	for (int k = 0; k < len; k++){
	  		x[k] = temp[k];
		}
      cout<<endl;
    }
}

int buscarParejas(int *pilas, int npilas, int objetivo){
    int optimo = 0, sum=0;
    bool puerta = true;
    int veces = (npilas & 1) ? (npilas/2)+1 : (npilas/2);
    for(int i=0; i<npilas; i++){
        if(puerta){
            puerta=false;
            sum+=pilas[i];
        }else{
            puerta=true;
            sum+=pilas[npilas-i-1];
        }
        if(sum >= objetivo){
            sum = 0;
            optimo++;
        }
    }
    return optimo;    
}