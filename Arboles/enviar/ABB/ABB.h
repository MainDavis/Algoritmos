#pragma once
#include "Nodo.h"

// �rbol binario de b�squeda. 
class ABB
{
	Nodo *raiz; 
	int n; 
public:

	ABB();
	void insertar (int nuevoElemento); // O(log n)
	Nodo *buscar(int elementoABuscar); // O(log n)
	void eliminar (int elementoAEliminar); // O(log n)
	void imprimir();
	bool esABB();
	bool esAVL();
	void leerArbol();
	~ABB();

protected:
	void eliminarSubarbol (Nodo *raizSubarbol);
	Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);
	Nodo *buscarRecursivo (Nodo *raizSubarbol, int elementoABuscar);
	Nodo *buscarMaximo (Nodo *raizSubarbol);
	Nodo *buscarMinimo (Nodo *raizSubarbol);
	void eliminarNodo (Nodo *nodoParaEliminar);
	int alturaNodo(Nodo *raizSubarbol);
	void imprimirRecorrido(Nodo *raizSubarbol);
	bool esSubABB(Nodo *raizSubarbol);
	bool esSubAVL(Nodo *raizSubarbol);
	Nodo * leerSubarbol(Nodo *padre);	
};

