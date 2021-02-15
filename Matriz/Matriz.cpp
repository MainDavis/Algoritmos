#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}

//Metodos de la matriz

Matriz::Matriz(int filas=0, int columnas=0){
		this->n_filas = filas;
		this->n_columnas = columnas;

		this->matriz = new double*[n_filas];
		for(int i=0; i<n_filas; i++)
      matriz[i] = new double[n_columnas];
	}

Matriz::Matriz(const Matriz &m){
				this->n_filas = m.n_filas;
				this->n_columnas = m.n_columnas;
				this->datosMatriz = m.datosMatriz;
			}
			
Matriz::~Matriz(){
				for(int i=0; i<n_filas;i++)
					delete[] this->datosMatriz[i];
				delete[] this->datosMatriz;
			}

Matriz Matriz::operator + (const Matriz &m2){
        assertdomjudge( (this->n_filas == m2.n_filas) && (this->n_columnas == m2.n_columnas) );

				Matrix m3;
				m3.n_filas = this->n_filas;
				m3.n_columnas = this->n_columnas;
				m3.datosMatriz = this->datosMatriz;
				
				for(int i=0; i<this->n_filas; i++){
					for(int j=0; j<this->n_columnas; j++)
						m3.datosMatriz[i][j] = this->datosMatriz[i][j] + m2.datosMatriz[i][j];
				}				
				return m3;
			}

Matriz Matriz::operator - (const Matriz &m2){
        assertdomjudge( (this->n_filas == m2.n_filas) && (this->n_columnas == m2.n_columnas) );

				Matrix m3;
				m3.n_filas = this->n_filas;
				m3.n_columnas = this->n_columnas;
				m3.datosMatriz = this->datosMatriz;
				
				for(int i=0; i<this->n_filas; i++){
					for(int j=0; j<this->n_columnas; j++)
						m3.datosMatriz[i][j] = this->datosMatriz[i][j] - m2.datosMatriz[i][j];
				}				
				return m3;
			}
			
Matriz Matriz::operator * (Matriz m2){
				Matrix m3;
				m3.n_filas = this.n
				
				
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

