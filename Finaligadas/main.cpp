#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo *sig;
};

Nodo* crearNodo(int dato) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->sig = NULL;
    return nuevo;
}

void mostrarLista(Nodo* cabeza) {
    Nodo* aux = cabeza;
    if (cabeza == NULL)
        cout << "Lista vacía\n";
    else {
        cout << "Elementos de la lista: " << endl;
        while (aux != NULL) {
            cout << aux->dato << " -> ";
            aux = aux->sig;
        }
        cout << "\n";
    }
}

void insertarInicio(Nodo** cabeza, int dato) {
    Nodo* aux = crearNodo(dato);
    aux->sig = *cabeza;
    *cabeza = aux;
}

void insertarFinal(Nodo** cabeza, int dato) {
    Nodo* nuevo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* aux = *cabeza;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void insertarDespuesDato(Nodo** cabeza, int datoReferencia, int dato) {
    Nodo* aux = *cabeza;
    while (aux != NULL && aux->dato != datoReferencia) {
        aux = aux->sig;
    }
    if (aux != NULL) {
        Nodo* nuevo = crearNodo(dato);
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    } else {
        cout << "Dato de referencia no encontrado.\n";
    }
}

void insertarAntesDato(Nodo** cabeza, int datoReferencia, int dato) {
    if (*cabeza == NULL) return;

    if ((*cabeza)->dato == datoReferencia) {
        insertarInicio(cabeza, dato);
        return;
    }

    Nodo* aux = *cabeza;
    while (aux->sig != NULL && aux->sig->dato != datoReferencia) {
        aux = aux->sig;
    }

    if (aux->sig != NULL) {
        Nodo* nuevo = crearNodo(dato);
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    } else {
        cout << "Dato de referencia no encontrado.\n";
    }
}

void borrarInicio(Nodo** cabeza) {
    if (*cabeza != NULL) {
        Nodo* aux = *cabeza;
        *cabeza = (*cabeza)->sig;
        delete aux;
    }
}

void borrarUltimo(Nodo** cabeza) {
    if (*cabeza == NULL) return;

    if ((*cabeza)->sig == NULL) {
        delete *cabeza;
        *cabeza = NULL;
    } else {
        Nodo* aux = *cabeza;
        while (aux->sig->sig != NULL) {
            aux = aux->sig;
        }
        delete aux->sig;
        aux->sig = NULL;
    }
}

void borrarDato(Nodo** cabeza, int dato) {
    if (*cabeza == NULL) return;

    if ((*cabeza)->dato == dato) {
        borrarInicio(cabeza);
        return;
    }

    Nodo* aux = *cabeza;
    while (aux->sig != NULL && aux->sig->dato != dato) {
        aux = aux->sig;
    }

    if (aux->sig != NULL) {
        Nodo* aBorrar = aux->sig;
        aux->sig = aux->sig->sig;
        delete aBorrar;
    } else {
        cout << "Dato no encontrado.\n";
    }
}

void borrarDespuesDato(Nodo** cabeza, int datoReferencia) {
    Nodo* aux = *cabeza;
    while (aux != NULL && aux->dato != datoReferencia) {
        aux = aux->sig;
    }
    if (aux != NULL && aux->sig != NULL) {
        Nodo* aBorrar = aux->sig;
        aux->sig = aux->sig->sig;
        delete aBorrar;
    } else {
        cout << "Dato no existe.\n";
    }
}

void borrarAntesDato(Nodo** cabeza, int datoReferencia) {
    if (*cabeza == NULL || (*cabeza)->sig == NULL) return;

    if ((*cabeza)->sig->dato == datoReferencia) {
        borrarInicio(cabeza);
        return;
    }

    Nodo* aux = *cabeza;
    while (aux->sig != NULL && aux->sig->sig != NULL && aux->sig->sig->dato != datoReferencia) {
        aux = aux->sig;
    }

    if (aux->sig != NULL && aux->sig->sig != NULL) {
        Nodo* aBorrar = aux->sig;
        aux->sig = aux->sig->sig;
        delete aBorrar;
    } else {
        cout << "DATO NO ENCONTRADO.\n";
    }
}

int main() {
    Nodo* cabeza = NULL;  // Lista vacía

    cout<< "Mostrar los elementos de la lista: "<<endl;
    mostrarLista(cabeza);

    cout<< "Insertar elemento al inicio: "<<endl;
    insertarInicio(&cabeza, 5);
    mostrarLista(cabeza);

    cout<< "Insertar elemento al inicio: "<<endl;
    insertarInicio(&cabeza, 3);
    mostrarLista(cabeza);

    cout<< "Insertar elemento al final: "<< endl;
    insertarFinal(&cabeza, 7);
    mostrarLista(cabeza);

    cout<< "Insertar elemento al final: "<<endl;
    insertarFinal(&cabeza, 10);
    mostrarLista(cabeza);

    cout<< "Insertar un elemento después del dato 7: "<<endl;
    insertarDespuesDato(&cabeza, 7, 9);
    mostrarLista(cabeza);

    cout<<"insertar un elemento después del dato 3: "<<endl;
    insertarDespuesDato(&cabeza, 3, 4);
    mostrarLista(cabeza);

    cout<< "Insertar un elemento después del dato 18: "<<endl;
    insertarDespuesDato(&cabeza, 18, 20); // Dato no existe, mensaje esperado
    mostrarLista(cabeza);

    cout<< "Insertar un elemento antes del dato 7: "<<endl;
    insertarAntesDato(&cabeza, 7, 6);
    mostrarLista(cabeza);

    cout<< "Insertar un elemento antes del dato 3: "<<endl;
    insertarAntesDato(&cabeza, 3, 2);
    mostrarLista(cabeza);

    cout<< "Insertar un elemento despues del dato 20: "<<endl;
    insertarAntesDato(&cabeza, 20, 19); // Dato no existe, mensaje esperado
    mostrarLista(cabeza);

    cout << "Borrar nodo al inicio de la lista: "<< endl;
    borrarInicio(&cabeza);
    mostrarLista(cabeza);

    cout<< "Borrar nodo al final de la lista: "<<endl;
    borrarUltimo(&cabeza);
    mostrarLista(cabeza);

    // Insertar un elemento al final de la lista
    insertarFinal(&cabeza, 25);
    mostrarLista(cabeza);

    cout<< "Borrar un elemento específico: "<<endl;
    borrarDato(&cabeza, 7);
    mostrarLista(cabeza);

    cout<< "Borrar un elemento específico: "<<endl;
    borrarDato(&cabeza, 3);
    mostrarLista(cabeza);

    cout<< "Borrar un elemento específico que no existe: "<<endl;
    borrarDato(&cabeza, 1); // Dato no existe, mensaje esperado
    mostrarLista(cabeza);

    cout<< "Borrar nodo con dato 3 "<<endl;
    borrarDespuesDato(&cabeza, 6);
    mostrarLista(cabeza);

    cout<< "Borrar nodo con dato 1 "<< endl;
    borrarAntesDato(&cabeza, 10);
    mostrarLista(cabeza);

    return 0;
}