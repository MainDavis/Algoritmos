#include<iostream>
using namespace std;

void c(int **array){ 
    //cout << "HOLA " << endl;

    //cout << "HOLA " << endl;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
        	if(i==0 || i==j) array[i][j]=1;
        	else  array[i][j] = array[i-1][j-1] + array[i-1][j];
        }
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<=i; j++){
            cout << array[i][j] << " ";
        }     
        cout << endl;
    }

    cout << "HOLA " << endl;
    //cout << n << r << endl;
    //cout << array[n][r] << endl;
    //return array[n][r];

}


int main(){
 int n , r;
 //int array[10][10];
 int **array;
	array = new int*[10];
	
	for(int i=0; i<10; i++){
        array[i] = new int[10];
    }
 c(array);

 while(true){
    cin >> n >> r;
    if((n < 0) || (r < 0)){
        break;
    }else if(n < r){
        cout << "ERROR" << endl;    
        continue;    
    }
    cout <<  array[n-r][r] << endl;
 }
 return 0;
}
