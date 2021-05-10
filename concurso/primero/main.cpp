#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
    int nNinos, nSalto, *arr, pos;
    cin >> nNinos; cin >> nSalto;

    while (nNinos != 0)
    {
        int pos = nSalto;
        arr = new int[nNinos];

        for(int i=0; i<nNinos; i++){
            arr[i] = i+1;
        }
    
        while(nNinos!=1){
            //Elimino
            if(pos>=nNinos) pos = (pos)-nNinos;
            if(pos<nNinos-1)memmove(arr+pos,arr+pos+1, sizeof(int)*nNinos-pos-2);
            nNinos--;
            pos+=nSalto;
        }
        cout << arr[0] << "\n";
        cin >> nNinos; cin >> nSalto;
        delete [] arr;
    }
}

