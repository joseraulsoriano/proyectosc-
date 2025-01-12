#include <iostream>
using namespace std;
class Nodo
{
public:
    Nodo(int dato);
    int dato;
    Nodo *next;
    Nodo *ant;
};
Nodo::Nodo(int d)
{
    dato=d;
}

Nodo::nodo()
{

}
Nodo * crearNodo(int dato)
{
    Nodo *nuevo = new    Nodo(dato);
    nuevo  ->dato = dato;
    nuevo ->next = NULL;
    return nuevo;
}
void mostarlista(Nodo *cabeza)
{
    Nodo *aux = cabeza;
    cout<<"Elementos del nodo"<<endl;
    while(aux != NULL)
    {
        cout<< aux ->dato<< "->";
        aux = aux->next;
    }
}
void insertarInicio(Nodo **cabeza, int dato)
{
    Nodo *p = new Nodo(dato);
    if( cabeza== NULL)
    {
        *cabeza=p;
    }
    else
    {
        p->next=*cabeza;
        *cabeza=p;
    }
}
void insertarFinal(Nodo**cabeza, int dato)
{
    Nodo *aux= *cabeza;
    while(*cabeza!=NULL)
    {
        *cabeza = (*cabeza)->next;
    }
    Nodo *n= new Nodo(dato);
    (*cabeza)->next=n;
    n=*cabeza;

}
void borrarDuplicado()
{
    while()
    {

    }

}
int main()
{
    Nodo*inicio;
    inicio=crearNodo(5);
    insertarInicio(&inicio,6);
    mostarlista(inicio);
    insertarFinal(&inicio, 8);
    mostarlista(inicio);
    borrarDuplicado(inicio);
    mostarlista(inicio);

    return 0;
}