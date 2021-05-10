#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void escribir(int c, int v);
void permutar(string str, int posMitad, int posFinal);

int main(){
    int nCasos, nC, nV;
    cin >> nCasos;

    for(int i=0; i<nCasos; i++){
        cin >> nC; cin >> nV;
        escribir(nC,nV);
    }

    return 0;
}

void escribir(int c, int v){
    int total = c+v;
    char arr[total];
    
    for(int i=0; i<c; i++)
        arr[i] = 'C';
    for(int i=c; i<total; i++){
        arr[i] = 'V';
    }
    permutar(arr, total/2, total-1);
}

void permutar(string str, int posMitad, int posFinal) {
    static int count;
    if (posMitad == posFinal) { 
        cout << " " << str;
        return ;
    } else {
        for (int i = posMitad; i <= posFinal; i++) {
            cout << "[" << posMitad << ", " << i << "]"; 
            swap(str[posMitad], str[i]);
            permutar(str, posMitad + 1, posFinal);
            swap(str[posFinal], str[i]);
            cout << "[" << posMitad << ", " << i << "]"; 
        }
    }
}

