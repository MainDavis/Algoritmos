#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
  double **matriz;
  int n_filas;
  int n_columnas;

 public:

	/*Constructor del objeto Matriz.
		Parámetro: Filas y columnas de la matriz que se va a crear.
		Retorno: Ninguno.
		Precondicion: Ninguno.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz(int filas=0, int columnas=0);


	/*Funcion copia del objeto Matriz.
		Parámetro: Objeto que se quiere copiar.
		Retorno: Ninguno.
		Precondicion: Ninguno.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz(const Matriz &m2);


	/*Destructor del objeto Matriz.
		Parámetro: Ninguno.
		Retorno: Ninguno.
		Precondicion: Ninguno.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	~Matriz();


	/* Realiza la operacion entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado.
		Parámetro: Matriz que se quiere sumar.
		Retorno: Matriz resultado de la suma.
		Precondicion: El número de filas y columnas de las dos matrices deben ser iguales.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz operator + (const Matriz &m2);


	/* Realiza la operacion entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado.
		Parámetro: Matriz que se quiere restar.
		Retorno: Matriz resultado de la resta.
		Precondicion: El número de filas y columnas de las dos matrices deben ser iguales.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz operator - (const Matriz &m2);


	/* Realiza la operacion entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado.
		Parámetro: Matriz que se quiere multiplicar.
		Retorno: Matriz resultado de la multiplicación.
		Precondicion: El número de columnas de la matriz principal debe ser igual al número de filas de la dada.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz operator * (const Matriz &m2);


	/* Realiza la operacion un objeto de la clase Matriz y un número de tipo double. Crea una nueva matriz con el resultado.
		Parámetro: Número por el que se quiere multiplicar.
		Retorno: Matriz resultado de la multiplicación.
		Precondicion: Ninguna.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz operator * (double number);


	/* Busca el valor más alto de la matriz y lo retorna.
		Parámetro: Ninguno.
		Retorno: Mayor número de la matriz.
		Precondicion: Ninguna.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	double obtenerMaximo();


	/* Busca el valor más bajo de la matriz y lo retorna.
		Parámetro: Ninguno.
		Retorno: Menor número de la matriz.
		Precondicion: Ninguna.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	double obtenerMinimo();


	/* Calcula la matriz traspuesta. Crea una nueva matriz con el resultado.
		Parámetro: Ninguno.
		Retorno: Matriz traspuesta.
		Precondicion: Ninguna.
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	Matriz calcularTraspuesta();


	/* Mira si la matriz es simétrica.
		Parámetro: Ninguno.
		Retorno: Boolean dependiendo de si es simétrica (true) o no (false).
		Precondicion: Debe ser una matriz cuadrada (n_filas == n_columnas).
		Complejidad Temporal:
		Complejidad Espacial:
	*/


	bool esSimetrica();


	/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)
	*/


    Matriz& operator= (const Matriz &m);


	/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)
	*/
  

  	void rellenarManual();


	/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)
	*/


  	void rellenarAleatorio(long seed);


	/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)
	*/


  	void mostrarMatriz();
  

};

#endif // MATRIZ_H
