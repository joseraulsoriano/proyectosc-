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
Nodo::Nodo(int dato)
{
    this->dato = dato;
    this ->ant =nullptr;
    this ->next = nullptr;
}

Nodo *crearNodo(int dato)
{
    Nodo *nuevo = new    Nodo(dato);
    return nuevo;
}
void agregarDato(Nodo *&cabeza, int dato)
{
    Nodo *nuevo = new Nodo(dato);
    if( cabeza== nullptr)
    {
        cabeza = nuevo;
    }
    else
    {
        nuevo->next = cabeza;
        cabeza->ant = nuevo;
        cabeza = nuevo;
    }
}
void mostrarlista(Nodo *cabeza)
{
    Nodo *aux = cabeza;

    while(aux != NULL)
    {
        cout<< aux ->dato<< "->";
        aux = aux->next;
    }
    cout<<endl;
}

void eliminarDuplicados(Nodo *cabeza)
{
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* siguiente = actual->next;
        while (siguiente) {
            if (actual->dato == siguiente->dato) {
                Nodo* temp = siguiente;
                siguiente = siguiente->next;
                if (temp->ant != nullptr) {
                    temp->ant->next= temp->next;
                } else {
                    temp->ant->next = temp->next;
                    temp->next->ant = temp->next;
                }
                delete temp;
            } else {
                siguiente = siguiente->next;
            }
        }
        actual = actual->next;
    }

}

int main()
{
    Nodo *cabeza= nullptr;
    cabeza=crearNodo(12);
    agregarDato(cabeza, 12);
    agregarDato(cabeza, 9);
    agregarDato(cabeza, 8);
    agregarDato(cabeza, 8);
    agregarDato(cabeza, 3);
    agregarDato(cabeza, 3);
    mostrarlista(cabeza);
    eliminarDuplicados(cabeza);
    mostrarlista(cabeza);


    return 0;
}
