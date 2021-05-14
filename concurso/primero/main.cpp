#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
    int nNinos, nSalto, pos;
    bool *siguen;
    cin >> nNinos; cin >> nSalto;

    while (nNinos != 0){

        siguen = new bool[nNinos];
        for(int i=0; i<nNinos; i++)
            siguen[i] = true;

        pos=0;
        for(int i=0; i<nNinos-1; i++){
            //Primero me pongo en el siguiente libre
            while(!siguen[pos]){
                pos++;
                if(pos>=nNinos) pos-=nNinos;
            }
            //Ahora hago los saltos
            int j=0;
            while(j<nSalto){
                pos++;
                if(pos>=nNinos) pos-=nNinos;
                if(siguen[pos]) j++;
            }
            siguen[pos] = false;
        }

        int j=0;
        while(!siguen[j]){ j++; };
        cout <<j+1 <<"\n";

        cin >> nNinos; cin >> nSalto;
    }

    return 0;
}

