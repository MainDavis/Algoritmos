#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Metodos de la matriz

Matriz::Matriz(int filas, int columnas){
	this->n_filas = filas;
	this->n_columnas = columnas;

	if(filas==0 || columnas==0){
		this->matriz=NULL;
	}else{
		this->matriz = new double*[n_filas];
		for(int i=0; i<n_filas; i++)
   		matriz[i] = new double[n_columnas];
	}	
}

Matriz::Matriz(const Matriz &m){
	//Hay que crear una nueva matriz, como estoy igualando el puntero, si cambio uno se cambian los dos
	this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;
	this->matriz = m.matriz;
}
			
Matriz::~Matriz(){
	for(int i=0; i<n_filas;i++)
		delete[] this->matriz[i];
	delete[] this->matriz;
}

Matriz Matriz::operator + (const Matriz &m2){
    assertdomjudge( (this->n_filas == m2.n_filas) && (this->n_columnas == m2.n_columnas) );

	Matriz m3(this->n_filas, this->n_columnas);
					
	for(int i=0; i<this->n_filas; i++){
		for(int j=0; j<this->n_columnas; j++)
			m3.matriz[i][j] = this->matriz[i][j] + m2.matriz[i][j];
		}				
	return m3;
}

Matriz Matriz::operator - (const Matriz &m2){
    assertdomjudge( (this->n_filas == m2.n_filas) && (this->n_columnas == m2.n_columnas) );

	Matriz m3;
	m3.n_filas = this->n_filas;
	m3.n_columnas = this->n_columnas;
	m3.matriz = this->matriz;
				
	for(int i=0; i<this->n_filas; i++){
		for(int j=0; j<this->n_columnas; j++)
			m3.matriz[i][j] = this->matriz[i][j] - m2.matriz[i][j];
	}				
	return m3;
}

Matriz Matriz::operator * (const Matriz &m2){
	assertdomjudge(this->n_columnas == m2.n_filas);
	Matriz m3(this->n_filas, m2.n_columnas);

	double suma=0;
	
	for(int i=0; i<this->n_filas; i++){
		for(int j=0; j<m2.n_columnas; j++){

			for(int k=0; k<this->n_columnas; k++){
				suma += matriz[i][k] * m2.matriz[k][j];
			}

			m3.matriz[i][j] = suma;
			suma=0;
		}
	}
	
	return m3;
}
			
Matriz Matriz::operator * (double number){
	Matriz m3;
	m3.n_filas = this->n_filas;
	m3.n_columnas = this->n_columnas;
	m3.matriz = this->matriz;
				
	for(int i=0; i<this->n_filas; i++){
		for(int j=0; j<this->n_columnas; j++)
			m3.matriz[i][j] = this->matriz[i][j] * number;
	}				
	return m3;							
}
		
			
double Matriz::obtenerMaximo(){
	double maximo=0;
	
	for(int i=0; i<this->n_filas; i++){
		for(int j=0; j<this->n_columnas; j++){
			if(this->matriz[i][j] > maximo)
				maximo = this->matriz[i][j];
		}
	}
	
	return maximo;	
}

double Matriz::obtenerMinimo(){
	double minimo=this->matriz[0][0];
	
	for(int i=0; i<this->n_filas; i++){
		for(int j=0; j<this->n_columnas; j++){
			if(this->matriz[i][j] < minimo)
				minimo = this->matriz[i][j];
		}
	}
	
	return minimo;
}

Matriz Matriz::calcularTraspuesta(){
	Matriz m3(this->n_columnas, this->n_filas);

	for(int i=0; i<this->n_columnas; i++){
		for(int j=0; j<this->n_filas; j++){
			m3.matriz[i][j] = this->matriz[j][i];
		}
	}

	return m3;
}

bool Matriz::esSimetrica(){
	assertdomjudge(this->n_filas == this->n_columnas);
	
	for(int i=this->n_filas-1; i>0; i--){
		for(int j=(this->n_columnas-2); j>-1; j--){
			if(this->matriz[i][j] != this->matriz[j][i]){
				return false;
			}
		}
	}

	return true;
}


//Asignacion de matrices

Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL)
    {
      for (int i = 0; i < n_filas; i++)
	delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
    }

  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0)
    {
      matriz= new double *[n_filas];
  
      for (int i = 0; i < n_filas; i++)
	{
	  matriz[i] = new double[n_columnas];  
	  for(int j=0; j <n_columnas; j++)
	    matriz[i][j]=m.matriz[i][j];
	}
    }
  
    return(*this); 
}


// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
    {
      cout << "Fila " << i << endl;
      for (int j = 0; j < n_columnas; j++)
	{
	  cout << "Elemento " << j  << endl;
	  cin >> elemento;
	  matriz[i][j] = elemento;
        }
      cout << endl;
    }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
      {
	for (int j = 0; j < n_columnas; j++)
	  cout << matriz[i][j] << " ";       
        cout << endl;
    }
}

