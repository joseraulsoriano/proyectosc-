#include <iostream>
using namespace std;

class ClaveDuplicadaException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Clave duplicada.";
    }
};

class ClaveNoEncontradaException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Clave no encontrada.";
    }
};

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(T valor) : dato(valor), izquierda(nullptr), derecha(nullptr), altura(1) {}
};

template <typename T>
class AVL
{
private:
    Nodo<T>* raiz;

    int alturaDeNodo(Nodo<T>* nodo) {
        if (!nodo) return 0;
        return nodo->altura;
    }

    int factorDeBalance(Nodo<T>* nodo) {
        if (!nodo) return 0;
        return alturaDeNodo(nodo->izquierda) - alturaDeNodo(nodo->derecha);
    }

    Nodo<T>* rotacionSimpleIzquierda(Nodo<T>* nodo) {
        Nodo<T>* hijo = nodo->derecha;
        nodo->derecha = hijo->izquierda;
        hijo->izquierda = nodo;

        nodo->altura = max(alturaDeNodo(nodo->izquierda), alturaDeNodo(nodo->derecha)) + 1;
        hijo->altura = max(alturaDeNodo(hijo->izquierda), alturaDeNodo(hijo->derecha)) + 1;

        return hijo;
    }

    Nodo<T>* rotacionSimpleDerecha(Nodo<T>* nodo) {
        Nodo<T>* hijo = nodo->izquierda;
        nodo->izquierda = hijo->derecha;
        hijo->derecha = nodo;

        nodo->altura = max(alturaDeNodo(nodo->izquierda), alturaDeNodo(nodo->derecha)) + 1;
        hijo->altura = max(alturaDeNodo(hijo->izquierda), alturaDeNodo(hijo->derecha)) + 1;

        return hijo;
    }

    Nodo<T>* rotacionDobleIzquierda(Nodo<T>* nodo) {
        nodo->derecha = rotacionSimpleDerecha(nodo->derecha);
        return rotacionSimpleIzquierda(nodo);
    }

    Nodo<T>* rotacionDobleDerecha(Nodo<T>* nodo) {
        nodo->izquierda = rotacionSimpleIzquierda(nodo->izquierda);
        return rotacionSimpleDerecha(nodo);
    }

    Nodo<T>* insertarRecursivo(Nodo<T>* nodo, T valor) {
        if (!nodo) return new Nodo<T>(valor);

        if (valor < nodo->dato) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        } else {
            throw ClaveDuplicadaException();
        }

        nodo->altura = 1 + max(alturaDeNodo(nodo->izquierda), alturaDeNodo(nodo->derecha));
        int balance = factorDeBalance(nodo);

        if (balance > 1 && valor < nodo->izquierda->dato)
            return rotacionSimpleDerecha(nodo);
        if (balance < -1 && valor > nodo->derecha->dato)
            return rotacionSimpleIzquierda(nodo);
        if (balance > 1 && valor > nodo->izquierda->dato)
            return rotacionDobleDerecha(nodo);
        if (balance < -1 && valor < nodo->derecha->dato)
            return rotacionDobleIzquierda(nodo);

        return nodo;
    }



    Nodo<T>* obtenerSucesor(Nodo<T>* nodo) {
        Nodo<T>* actual = nodo;
        while (actual->izquierda) {
            actual = actual->izquierda;
        }
        return actual;
    }

    void inOrdenRecursivo(Nodo<T>* nodo) {
        if (!nodo) return;
        inOrdenRecursivo(nodo->izquierda);
        cout << nodo->dato << " ";
        inOrdenRecursivo(nodo->derecha);
    }
public:
    AVL() : raiz(nullptr) {}

    void insertar(T valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void inOrden() {
        inOrdenRecursivo(raiz);
        cout << endl;
    }
};


int main() {
    AVL<int> arbol;

    try
    {
        cout << "Insertando valores iniciales del grafo AVl:" <<endl;
        arbol.insertar(43);
        arbol.insertar(21);
        arbol.insertar(77);
        arbol.insertar(58);
        arbol.inOrden();
        cout << "Insertando valores: 63, 15" << endl;
        arbol.insertar(63);
        arbol.insertar(15);
        arbol.inOrden();
        cout << "Insertando valores: 37, 41" << endl;
        arbol.insertar(37);
        arbol.insertar(41);
        arbol.inOrden();
        cout << "Insertando valores: 83, 50" << endl;
        arbol.insertar(83);
        arbol.insertar(50);
        arbol.inOrden();
        cout << "Insertando valores: 7" << endl;
        arbol.insertar(7);
        arbol.inOrden();
        cout << "Insertando valores: 10" << endl;
        arbol.insertar(10);
        arbol.inOrden();
        cout << "Insertando valores: 40,90,18" << endl;
        arbol.insertar(40);
        arbol.insertar(90);
        arbol.insertar(18);
        arbol.inOrden();
        cout << "Insertando valores: 12" << endl;
        arbol.insertar(12);
        arbol.inOrden();
        cout << "Recorrido en InOrden después de ingresar todos los valores: " << endl;
        arbol.inOrden();
    } catch (ClaveDuplicadaException& e) {
        cout << e.what() << endl;
    } catch (ClaveNoEncontradaException& e) {
        cout << e.what() << endl;
    }

    return 0;
}