#include <iostream>
using namespace std;
class Nodo
{
public:
    Nodo(int dato);
    int dato;
    Nodo *next;
};
Nodo::Nodo(int d)
{
    dato=d;
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
void insertarInicio(Nodo *cabeza, int dato)
{
    Nodo *p = new Nodo(dato);
    if( cabeza== NULL)
    {
        cabeza=p;
    }
    else
    {
        p->next=cabeza;
        cabeza=p;
    }
}

//Considerar lista vacia//

int main()
{
    Nodo *cabeza, *dos, *tres, *nuevo;
    cabeza = NULL;
    cabeza = crearNodo(1);
    dos = crearNodo(2);
    tres = crearNodo(3);
    nuevo = crearNodo(4);
    cabeza->next=dos;
    dos->next = tres;

    mostarlista(cabeza);
    nuevo->next= cabeza;
    cabeza = nuevo;
    mostarlista(cabeza);
    insertarInicio(cabeza, 6);
    mostarlista(cabeza);
    return 0;
}

