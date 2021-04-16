#include"Pila.h"
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}


Pila::Pila(string name)
{
  this->name = name;
  this->cima = NULL;
}

std::string Pila::nombrePila()
{
  return this->name;
}

void Pila::apilar(int num)
{
  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;

  Nodo *nuevo = new Nodo(num, cima);

  cima = nuevo;

}
  
int Pila::desapilar()
{
  assertdomjudge(this->cima!=NULL);
  
  int valor = cima->valor;
  cout<<"Desapilando disco "<< valor <<" del poste "<<name<<endl;
  Nodo *temp;
  temp = cima;
  cima = cima->siguiente;
  delete temp;
  return valor;
}

bool Pila::estaVacia()
{
  return (cima == NULL) ? 1 : 0;
}