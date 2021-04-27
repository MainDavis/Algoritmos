#include "ABB.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

void ABB::imprimir()
{
  if(raiz==NULL)
    cout<<"VACIO"<<endl;
  else   
      imprimirRecorrido(raiz);    
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout<<raizSubarbol->contenido<<endl;
  if(raizSubarbol->hijoIzquierdo!=NULL)
    {
      cout<<"I";
      imprimirRecorrido(raizSubarbol->hijoIzquierdo);
      cout<<endl;
    }
  if(raizSubarbol->hijoDerecho!=NULL)
    {
      cout<<"D";
      imprimirRecorrido(raizSubarbol->hijoDerecho);
      cout<<endl;
    }
}

void ABB::leerArbol()
{
  raiz=leerSubarbol(NULL);
}

Nodo * ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin>>contenido;
  if(contenido>=0)
    {
      Nodo *arbol=new Nodo;
      arbol->contenido=contenido;
      arbol->hijoIzquierdo=leerSubarbol(arbol);
      arbol->hijoDerecho=leerSubarbol(arbol);
      arbol->padre=padre;
      return arbol;
    }
  else
    {
      return NULL;
    }
}

/* 
AQUI EMPIEZA MI CÓDIGO
 */

ABB::ABB(){
  this->raiz = NULL;
  this->n = 0;
}

ABB::~ABB(){

}

void ABB::insertar(int nuevoElemento){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->contenido = nuevoElemento;
  nuevoNodo->hijoIzquierdo = NULL;
  nuevoNodo->hijoDerecho = NULL;

  if(n==0){
    nuevoNodo->padre = NULL;
    this->raiz = nuevoNodo;
    
  }else{
    Nodo *temp = buscarHueco(this->raiz, nuevoElemento);
    nuevoNodo->padre = temp;
    (nuevoElemento <= temp->contenido) ? temp->hijoIzquierdo = nuevoNodo : temp->hijoDerecho = nuevoNodo; 
  }

  this->n++;
}

Nodo* ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar){
  if(elementoAInsertar <= raizSubarbol->contenido) //Si el elemento es más pequeño
    return (raizSubarbol->hijoIzquierdo != NULL) ? buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar) : raizSubarbol;
  else // Si el elemento es más grande
    return (raizSubarbol->hijoDerecho != NULL) ? buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar) : raizSubarbol;  
}

void ABB::eliminarSubarbol(Nodo *raizSubarbol){
  if(raizSubarbol->hijoIzquierdo != NULL) eliminarSubarbol(raizSubarbol->hijoIzquierdo);
  if(raizSubarbol->hijoDerecho != NULL) eliminarSubarbol(raizSubarbol->hijoDerecho);
  (raizSubarbol->padre->hijoIzquierdo == raizSubarbol) ? raizSubarbol->padre->hijoIzquierdo = NULL : raizSubarbol->padre->hijoDerecho = NULL;
  delete raizSubarbol;
}

Nodo* ABB::buscar(int elementoABuscar){
  return (n > 0) ? buscarRecursivo(this->raiz, elementoABuscar) : NULL;
}

Nodo* ABB::buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar){
  Nodo *temp;
  if(raizSubarbol->contenido == elementoABuscar) return raizSubarbol;
  if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL) return NULL;
  if(raizSubarbol->hijoIzquierdo != NULL){
    temp = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
    if(temp != NULL) return temp;
  }
  if(raizSubarbol->hijoDerecho != NULL){
    temp = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
    if(temp != NULL) return temp;
  }
  return NULL;
}

Nodo* ABB::buscarMaximo(Nodo *raizSubarbol){
  return (raizSubarbol->hijoDerecho != NULL) ? buscarMaximo(raizSubarbol->hijoDerecho) : raizSubarbol;
}

Nodo* ABB::buscarMinimo(Nodo *raizSubarbol){
  return (raizSubarbol->hijoIzquierdo != NULL) ? buscarMaximo(raizSubarbol->hijoIzquierdo) : raizSubarbol;
}

int ABB::alturaNodo(Nodo *raizSubarbol){
  int alturaIzquierda, alturaDerecha;

    if(raizSubarbol==NULL)
        return -1;
    else{

        alturaIzquierda = alturaNodo(raizSubarbol->hijoIzquierdo);
        alturaDerecha = alturaNodo(raizSubarbol->hijoDerecho);

        return (alturaIzquierda>alturaDerecha) ? alturaIzquierda+1 : alturaDerecha+1;
    } 
}

void ABB::eliminar(int elementoAEliminar){
  this->n--;
  Nodo *nodoAEliminar = buscar(elementoAEliminar);
  if(n==0){
      delete nodoAEliminar;
      raiz = NULL;
  }else if(nodoAEliminar->hijoIzquierdo == NULL && nodoAEliminar->hijoDerecho == NULL){ //No tiene hijos
      (nodoAEliminar->padre->hijoIzquierdo == nodoAEliminar) ? nodoAEliminar->padre->hijoIzquierdo = NULL : nodoAEliminar->padre->hijoDerecho = NULL;
      delete nodoAEliminar;
  }
  else
    eliminarNodo(nodoAEliminar);
}

void ABB::eliminarNodo(Nodo *nodoParaEliminar){
  Nodo *temp;
  int valor = nodoParaEliminar->contenido;

  if(nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho == NULL){ //Es una hoja
    (nodoParaEliminar->padre->hijoIzquierdo == nodoParaEliminar) ? nodoParaEliminar->padre->hijoIzquierdo=NULL : nodoParaEliminar->padre->hijoDerecho = NULL;
    delete nodoParaEliminar;
  }else if(nodoParaEliminar->hijoIzquierdo != NULL && nodoParaEliminar->hijoDerecho == NULL){ //Solo tiene un hijo izquierdo
    temp = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
    nodoParaEliminar->contenido = temp->contenido;
    eliminarNodo(temp);
  }else if(nodoParaEliminar->hijoIzquierdo == NULL && nodoParaEliminar->hijoDerecho != NULL){ //Solo tiene un hijo derecho
    temp = buscarMinimo(nodoParaEliminar->hijoDerecho);
    nodoParaEliminar->contenido = temp->contenido;
    eliminarNodo(temp);
  }else{ //Tiene los dos hijos
    int alturaIzquierda, alturaDerecha;
    alturaIzquierda = alturaNodo(nodoParaEliminar->hijoIzquierdo);
    alturaDerecha = alturaNodo(nodoParaEliminar->hijoDerecho);  
    
    if( alturaIzquierda < alturaDerecha){
        temp = buscarMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = temp->contenido;
        eliminarNodo(temp);
    }else{
        temp = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = temp->contenido;
        eliminarNodo(temp);
    }
  }
}

bool ABB::esABB(){
  return (this->raiz != NULL) ? esSubABB(this->raiz) : true;
}

bool ABB::esSubABB(Nodo *raizSubarbol){
  if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho == NULL) return true;
  else if(raizSubarbol->hijoIzquierdo != NULL && raizSubarbol->hijoDerecho == NULL) 
    return (raizSubarbol->contenido >= raizSubarbol->hijoIzquierdo->contenido) && esSubABB(raizSubarbol->hijoIzquierdo);
  else if(raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho != NULL)
    return (raizSubarbol->contenido <= raizSubarbol->hijoDerecho->contenido) && esSubABB(raizSubarbol->hijoDerecho);
  else
    return (raizSubarbol->hijoIzquierdo->contenido <= raizSubarbol->contenido && raizSubarbol->contenido <= raizSubarbol->hijoDerecho->contenido) && esSubABB(raizSubarbol->hijoIzquierdo) && esSubABB(raizSubarbol->hijoDerecho);
  return true; //Para que no de warning
}

bool ABB::esAVL(){
  return (this->raiz != NULL) ? esSubAVL(this->raiz) : true;
}

bool ABB::esSubAVL(Nodo *raizSubarbol){
  if(!esABB()) return false;

  int alturaIzquierda=0, alturaDerecha=0, diferencia;
  bool AVLIzquierda, AVLDerecha;

  if(raizSubarbol->hijoIzquierdo!=NULL){
    alturaIzquierda = alturaNodo(raizSubarbol->hijoIzquierdo)+1;
    AVLIzquierda = esSubAVL(raizSubarbol->hijoIzquierdo);
    if(!AVLIzquierda) return false;
  }

  if(raizSubarbol->hijoDerecho!=NULL){
    alturaDerecha = alturaNodo(raizSubarbol->hijoDerecho)+1;
    AVLDerecha = esSubAVL(raizSubarbol->hijoDerecho);
    if(!AVLDerecha) return false;
  }
  
  diferencia = (alturaIzquierda > alturaDerecha) ? alturaIzquierda-alturaDerecha : alturaDerecha-alturaIzquierda;
  if(diferencia > 1) return false;


  return true;
}

