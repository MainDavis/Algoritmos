#include <iostream>
#include <string>

using namespace std;

bool verificar(int **mapa, int posX, int posY);

void recursive(int **mapa, int posX, int posY, int ntablero);

int main(){
    int ntablero; cin >> ntablero;
    int **mapa;  
    char *temp;  

    while(ntablero != 0){
        temp = new char[ntablero];
        mapa = new int*[ntablero];
        for(int i=0; i<ntablero; i++){
            mapa[i] = new int[ntablero];
            cin >> temp;
            for(int j=0; j<ntablero; j++){
                mapa[i][j] = (temp[j]=='.') ? 0 : -1;
            }
        }

        recursive(mapa, 0, ntablero-1, ntablero);
        
        cout << mapa[ntablero-1][0] << "\n";

        delete [] mapa;
        delete [] temp;
        cin >> ntablero;
    }  
   
    return 0;
}

void recursive(int **mapa, int posX, int posY, int ntablero){
    if( !(posX == ntablero || posY == -1) && mapa[posX][posY]!=-1){ 
        mapa[posX][posY]++;
        recursive(mapa, posX+1, posY, ntablero);
        recursive(mapa, posX, posY-1, ntablero);
    }
}