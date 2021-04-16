#include<iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include"ListaCircular.h"
using namespace std;

int main()
{
  srand (time(NULL)); 
  int n_recamaras;
  int giro;
  int pos_bala;
  string disparo;
  cerr<<"Numero de recamaras del tambor de la pistola: ";
  cin>>n_recamaras;
  pos_bala = rand() % n_recamaras;
  
  ListaCircular pistola;
  for(int i=0;i<n_recamaras;i++)
    if(i==pos_bala)
      pistola.insertar(i,"BANG");
    else
      pistola.insertar(i,"CLACK");
  
  do
    {
      cout << "Siguiente ronda!\n";
      system("pause");
      giro = rand() % 7;
      cout << "Se gira " << giro << " veces! -> ";
      pistola.girar(giro);
      disparo=pistola.getValor(0);
      cout<<disparo<<endl;
    }while(disparo!="BANG");

  for(int i=0;i<n_recamaras;i++)
    pistola.eliminar(0);
   
  
  return 0;
  
}
