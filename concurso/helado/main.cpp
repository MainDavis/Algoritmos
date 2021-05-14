#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void escribir(int c, int v);
void permutacion(string arr, int lenN, int lenO, int nC, int nV, string padre);

int main(){
    int nCasos, nC, nV;
    cin >> nCasos;

    for(int i=0; i<nCasos; i++){
        cin >> nC; cin >> nV;
        escribir(nC,nV);
        cout << "\n";
    }

    return 0;
}

void escribir(int c, int v){
    int total = c+v;
    string arr = "";

    for(int i=0; i<c; i++)
        arr.push_back('C');
       
    for(int i=c; i<total; i++)
        arr.push_back('V');
    
    if(c == 0 || v == 0){
        cout << arr;
        return;
    }

    string temp;
    temp = arr;
    temp[c] = 'C'; 

    arr.erase(0,1);
    temp.erase(0,1);

    string padreC="", padreV="";
    padreC.push_back('C');
    padreV.push_back('V');
    permutacion(arr, total-1, total, c-1, v, padreC);
    permutacion(temp, total-1, total, c, v-1, padreV);
    
}

void permutacion(string arr, int lenN, int lenO, int nC, int nV, string padre){
    
    if(lenN == 1 || nC == 0 || nV == 0){
        cout << padre;
        cout << arr << " ";
        return;
    }

    string strC, strV;

    strC = arr;
    strV = arr;
    strV[nC] = 'C';

    string padreC = padre;
    string padreV = padre;
    padreC.push_back('C');
    padreV.push_back('V');

    permutacion(strC.erase(0,1), lenN-1, lenO, nC-1, nV, padreC);

    permutacion(strV.erase(0,1), lenN-1, lenO, nC, nV-1, padreV);
}