#include <iostream>

#define MAX_LADO 10

using namespace std;

bool resolver(char** mapa, int posY, int posX, int posFinal[2]); //Resuelve el laberinto por backtraking
inline bool permitir(char** mapa, int posY, int posX);	// Mira si el punto dado por es válido dentro del mapa
inline void imprimir(char** mapa);	// imprime el mapa por pantalla


int main(int argc, char** argv) {
	int posFinal[2] = {0,0};
	char **mapa;
	
	mapa = new char*[MAX_LADO];
	for(int i=0; i<MAX_LADO; i++)
		mapa[i] = new char[MAX_LADO];
	
	for(int i=0; i<MAX_LADO; i++)
		cin >> mapa[i];
	
	if(resolver(mapa, 0,0, posFinal)){
		imprimir(mapa);
		cout << "ENCONTRADO " << posFinal[0] << " " << posFinal[1];
	}else{
		cout << "INALCANZABLE";
	}
	
	for(int i=0; i<MAX_LADO;i++)
		delete[] mapa[i];
	delete[] mapa;
	
	return 0;
}

bool resolver(char** mapa, int posY, int posX, int posFinal[2]){
	
	if(permitir(mapa, posY, posX)){		
		
		if(mapa[posY][posX] == 'T'){
			
			posFinal[0]=posY;
			posFinal[1]=posX;
			return true;
			
		}else if(mapa[posY][posX] == '.'){
			
			mapa[posY][posX] = 'X';
		
			if(resolver(mapa, posY-1, posX, posFinal)) return true;
			if(resolver(mapa, posY, posX+1, posFinal)) return true;
			if(resolver(mapa, posY+1, posX, posFinal)) return true;
			if(resolver(mapa, posY, posX-1, posFinal)) return true;
		
			mapa[posY][posX] = '.';
			
			return false;
		}		
	}
	return false;
}

inline bool permitir(char** mapa, int posY, int posX){
	return (posY > -1 && posY < MAX_LADO && posX > -1 && posX < MAX_LADO);
}

inline void imprimir(char** mapa){
	cout << "\n";
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout << mapa[i][j];
		}
		cout << "\n";
	}
}
