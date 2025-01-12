#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Definición de una clase genérica Nodo que funciona con cualquier tipo de dato
template <typename T>
class Nodo {
public:
    T dato; // Dato genérico del nodo
    vector<Nodo*> hijos; // Vector de hijos

    Nodo(T valor) : dato(valor) {}

    ~Nodo() {
        for (Nodo* hijo : hijos) {
            delete hijo;
        }
    }
};

// Definición de una clase genérica ArbolN que funciona con cualquier tipo de dato
template <typename T>
class ArbolN {
private:
    Nodo<T>* raiz; // Nodo raíz del árbol

    // Función recursiva para recorrido en preorden
    void preOrdenRecursivo(Nodo<T>* nodo) {
        if (!nodo) return;
        cout << nodo->dato << " ";
        for (Nodo<T>* hijo : nodo->hijos) {
            preOrdenRecursivo(hijo);
        }
    }

    // Función recursiva para recorrido en posorden
    void posOrdenRecursivo(Nodo<T>* nodo) {
        if (!nodo) return;
        for (Nodo<T>* hijo : nodo->hijos) {
            posOrdenRecursivo(hijo);
        }
        cout << nodo->dato << " ";
    }

public:
    ArbolN() : raiz(nullptr) {}

    ~ArbolN() {
        delete raiz;
    }

    // Insertar la raíz
    void insertarRaiz(T valor) {
        if (!raiz) {
            raiz = new Nodo<T>(valor);
        } else {
            cout << "La raíz ya existe." << endl;
        }
    }

    // Buscar nodo por valor
    Nodo<T>* buscarNodo(Nodo<T>* nodo, T valor) {
        if (!nodo) return nullptr;
        if (nodo->dato == valor) return nodo;
        for (Nodo<T>* hijo : nodo->hijos) {
            Nodo<T>* resultado = buscarNodo(hijo, valor);
            if (resultado) return resultado;
        }
        return nullptr;
    }

    // Insertar nodo hijo
    void insertar(T valorPadre, T valorHijo) {
        Nodo<T>* padre = buscarNodo(raiz, valorPadre);
        if (padre) {
            padre->hijos.push_back(new Nodo<T>(valorHijo));
        } else {
            cout << "Nodo padre " << valorPadre << " no encontrado." << endl;
        }
    }

    // Recorrido en preorden
    void preOrden() {
        preOrdenRecursivo(raiz);
        cout << endl;
    }

    // Recorrido en posorden
    void posOrden() {
        posOrdenRecursivo(raiz);
        cout << endl;
    }

    // Recorrido por niveles
    void niveles() {
        if (!raiz) return;
        queue<Nodo<T>*> q;
        q.push(raiz);
        while (!q.empty()) {
            Nodo<T>* nodo = q.front();
            q.pop();
            cout << nodo->dato << " ";
            for (Nodo<T>* hijo : nodo->hijos) {
                q.push(hijo);
            }
        }
        cout << endl;
    }
};

int main() {
    // Árbol para números
    ArbolN<float>* arbolNumeros = new ArbolN<float>();
    arbolNumeros->insertarRaiz(0.0f);      // Inserta la raíz
    arbolNumeros->insertar(0.0f, 1.0f);
    arbolNumeros->insertar(0.0f, 2.0f);
    arbolNumeros->insertar(0.0f, 3.0f);
    arbolNumeros->insertar(1.0f, 1.1f);
    arbolNumeros->insertar(1.0f, 1.2f);
    arbolNumeros->insertar(3.0f, 3.1f);
    arbolNumeros->insertar(3.0f, 3.2f);
    arbolNumeros->insertar(3.0f, 3.3f);
    arbolNumeros->insertar(3.0f, 3.4f);

    cout << "Recorrido en Preorden (Números):" << endl;
    arbolNumeros->preOrden();

    cout << "Recorrido en Posorden (Números):" << endl;
    arbolNumeros->posOrden();

    cout << "Recorrido por niveles (Números):" << endl;
    arbolNumeros->niveles();

    delete arbolNumeros;

    // Árbol para letras
    ArbolN<string>* arbolLetras = new ArbolN<string>();
    arbolLetras->insertarRaiz("A");      // Inserta la raíz
    arbolLetras->insertar("A", "B");
    arbolLetras->insertar("A", "C");
    arbolLetras->insertar("B", "E");
    arbolLetras->insertar("B", "F");
    arbolLetras->insertar("C", "G");
    arbolLetras->insertar("C", "H");
    arbolLetras->insertar("E", "J");
    arbolLetras->insertar("J", "R");
    arbolLetras->insertar("J", "S");
    arbolLetras->insertar("F", "L");
    arbolLetras->insertar("F", "K");
    arbolLetras->insertar("H", "N");
    arbolLetras->insertar("H", "O");
    arbolLetras->insertar("O", "P");
    arbolLetras->insertar("O", "Q");









    cout << "Recorrido en Preorden (Letras):" << endl;
    arbolLetras->preOrden();

    cout << "Recorrido en Posorden (Letras):" << endl;
    arbolLetras->posOrden();

    cout << "Recorrido por niveles (Letras):" << endl;
    arbolLetras->niveles();

    delete arbolLetras;

    return 0;
}