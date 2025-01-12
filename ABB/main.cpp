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

    Nodo(T valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

template <typename T>
class ABB {
private:
    Nodo<T>* raiz;

    Nodo<T>* borrarRecursivo(Nodo<T>* nodo, T valor) {
        if (!nodo) throw ClaveNoEncontradaException();

        if (valor < nodo->dato) {
            nodo->izquierda = borrarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = borrarRecursivo(nodo->derecha, valor);
        } else {
            if (!nodo->izquierda && !nodo->derecha) {
                delete nodo;
                return nullptr;
            } else if (!nodo->izquierda) {
                Nodo<T>* temp = nodo;
                nodo = nodo->derecha;
                delete temp;
            } else if (!nodo->derecha) { // Nodo con un hijo a la izquierda
                Nodo<T>* temp = nodo;
                nodo = nodo->izquierda;
                delete temp;
            } else { // Nodo con dos hijos
                Nodo<T>* sucesor = obtenerSucesor(nodo->derecha);
                nodo->dato = sucesor->dato;
                nodo->derecha = borrarRecursivo(nodo->derecha, sucesor->dato);
            }
        }
        return nodo;
    }

    Nodo<T>* obtenerSucesor(Nodo<T>* nodo) {
        Nodo<T>* actual = nodo;
        while (actual->izquierda) {
            actual = actual->izquierda;
        }
        return actual;
    }

    void preOrdenRecursivo(Nodo<T>* nodo) {
        if (!nodo) return;
        cout << nodo->dato << " ";
        preOrdenRecursivo(nodo->izquierda);
        preOrdenRecursivo(nodo->derecha);
    }

    void inOrdenRecursivo(Nodo<T>* nodo) {
        if (!nodo) return;
        inOrdenRecursivo(nodo->izquierda);
        cout << nodo->dato << " ";
        inOrdenRecursivo(nodo->derecha);
    }

    void posOrdenRecursivo(Nodo<T>* nodo) {
        if (!nodo) return;
        posOrdenRecursivo(nodo->izquierda);
        posOrdenRecursivo(nodo->derecha);
        cout << nodo->dato << " ";
    }

    int alturaRecursiva(Nodo<T>* nodo) {
        if (!nodo) return -1;
        int alturaIzquierda = alturaRecursiva(nodo->izquierda);
        int alturaDerecha = alturaRecursiva(nodo->derecha);
        return max(alturaIzquierda, alturaDerecha) + 1;
    }

    int profundidadRecursiva(Nodo<T>* nodo, T valor, int profundidad) {
        if (!nodo) throw ClaveNoEncontradaException();
        if (nodo->dato == valor) return profundidad;
        if (valor < nodo->dato) return profundidadRecursiva(nodo->izquierda, valor, profundidad + 1);
        return profundidadRecursiva(nodo->derecha, valor, profundidad + 1);
    }

    int contarNodos(Nodo<T>* nodo) {
        if (!nodo) return 0;
        return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
    }

public:
    ABB() : raiz(nullptr) {}

    void insertar(T valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    Nodo<T>* insertarRecursivo(Nodo<T>* nodo, T valor) {
        if (!nodo) {
            return new Nodo<T>(valor);
        }
        if (valor < nodo->dato) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        } else {
            throw ClaveDuplicadaException();
        }
        return nodo;
    }

    void borrar(T valor) {
        raiz = borrarRecursivo(raiz, valor);
    }

    void preOrden() {
        preOrdenRecursivo(raiz);
        cout << endl;
    }

    void inOrden() {
        inOrdenRecursivo(raiz);
        cout << endl;
    }

    void posOrden() {
        posOrdenRecursivo(raiz);
        cout << endl;
    }

    int altura() {
        return alturaRecursiva(raiz);
    }

    int profundidad(T valor) {
        return profundidadRecursiva(raiz, valor, 0);
    }

    int numNodos() {
        return contarNodos(raiz);
    }
};

int main() {
    ABB<int> arbol;

    try {
        arbol.insertar(A);
        arbol.insertar(3);
        arbol.insertar(6);
        arbol.insertar(1);
        arbol.insertar(4);
        arbol.insertar(7);
        arbol.insertar(13);
        arbol.insertar(10);
        arbol.insertar(14);

        cout << "Recorrido en InOrden:" << endl;
        arbol.inOrden();
        cout << "Recorrido en PosOrden: " << endl;
        arbol.posOrden();
        cout << "Recorrido en PreOrden: " << endl;
        arbol.preOrden();
        arbol.borrar(3);
        arbol.borrar(13);
        arbol.borrar(8);
        cout << "Recorrido en InOrden después de borrar: " << endl;
        arbol.inOrden();
        cout << "La altura del árbol es: " << arbol.altura() << endl;
        cout << "La profundidad de 30 es: " << arbol.profundidad(30) << endl;
        cout << "La profundidad de 120 es: " << arbol.profundidad(120) << endl;
        cout << "Número de nodos del árbol: " << arbol.numNodos() << endl;
    } catch (ClaveDuplicadaException& e) {
        cout << e.what() << endl;
    } catch (ClaveNoEncontradaException& e) {
        cout << e.what() << endl;
    }

    return 0;
}