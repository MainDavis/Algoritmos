#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
  double **matriz;
  int n_filas;
  int n_columnas;

 public:

	Matriz(int filas=0, int columnas=0);
	Matriz(const Matriz &m2);
	~Matriz();

	Matriz operator + (const Matriz &m2);
	Matriz operator - (const Matriz &m2);
	Matriz operator * (const Matriz &m2);
	Matriz operator * (double number);

	double obtenerMaximo();
	double obtenerMinimo();

	Matriz calcularTraspuesta();

	bool esSimetrica();

/*Calcula el determinante de la matriz.
	Parámetro: Ninguno.
	Retorno: Double, determinante resultado.
	Precondicion: n_filas==n_columnas, n_filas>0, n_columnas>0.
	Complejidad Temporal T(n): T(2)=1, T(n)=n*T(n-1)+1
	Complejidad Espacial M(n): T(2)=1, M(n)=n*M(n-1)+n*2(n-1)+1
	Orden Temporal: O(n!)
	Orden Espacial: O(n^3)
*/


	double calcularDeterminante();

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
