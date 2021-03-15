#include <iostream>
#include <string>

#define MAX_LADO 10//

using namespace std;

bool resolver(string mapa[MAX_LADO], int posX, int posY, bool &terminado);

int main(int argc, char** argv) {
	string mapa[MAX_LADO];
	bool terminado=false; //SI
	
	for(int i=0; i<MAX_LADO; i++){
		cin >> mapa[i];
	}
	
	resolver(mapa, 0,0, terminado);

	return 0;
}

bool resolver(string mapa[MAX_LADO], int posX, int posY, bool &terminado){
	if( !(posY+1 == MAX_LADO) && mapa[posX][posY+1] != '*'  && mapa[posX][posY+1] != 'X' && !terminado){
		if(mapa[posX][posY+1] == 'T') return true;
		mapa[posX][posY+1]='X';
		if(resolver(mapa, posX, posY+1, terminado)){
			terminado=true;
		}else{
			mapa[posX][posY+1] == '.';
		}
	}
	if( !(posX+1 == MAX_LADO) && mapa[posX+1][posY] != '*' && mapa[posX+1][posY] != 'X' && !terminado){
		cout << "Ye ";
		if(mapa[posX][posY+1] == 'T') return true;
		mapa[posX+1][posY] == 'X';
		if(resolver(mapa, posX+1, posY, terminado)){
			terminado=true;
		}else{
			mapa[posX+1][posY+1]='.';
		}
	}
	if( !(posY-1 == 0) && mapa[posX][posY-1] != '*' && mapa[posX+1][posY] != 'X' && !terminado ){
		return true;
	}	
	return true;
}

