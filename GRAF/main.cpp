#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Grafo {
private:
    vector<vector<float>> M;
    vector<string> vertices;
    int numVertices;
    int contadorVertices;

public:
    Grafo(int n) {
        numVertices = n;
        M.resize(n, vector<float>(n, 0));
        vertices.resize(n);
        contadorVertices = 0;
    }

    void agregarVertice(string v) {
        if (contadorVertices < numVertices) {
            vertices[contadorVertices] = v;
            contadorVertices++;
        } else {
            cout << "No se pueden agregar más vértices. Límite alcanzado." << endl;
        }
    }

    void agregarArista(string v1, string v2, float costo) {
        int indice1 = -1, indice2 = -1;

        // Buscar los índices de los vértices
        for (int i = 0; i < contadorVertices; ++i) {
            if (vertices[i] == v1) {
                indice1 = i;
            }
            if (vertices[i] == v2) {
                indice2 = i;
            }
        }

        if (indice1 != -1 && indice2 != -1) {
            M[indice1][indice2] = costo;
            M[indice2][indice1] = costo;
        } else {
            cout << "Uno o ambos vértices no encontrados." << endl;
        }
    }

    void mostrarMatriz() {
        cout << "==========================" << endl;
        cout << "Matriz de Adyacencia:" << endl;
        cout << "  ";
        for (int i = 0; i < contadorVertices; ++i) {
            cout << vertices[i] << "  ";
        }
        cout << endl;

        for (int i = 0; i < contadorVertices; ++i) {
            cout << vertices[i] << " ";
            for (int j = 0; j < contadorVertices; ++j) {
                cout << M[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "==========================" << endl;
    }

    void mostrarVertices() {
        cout << "Vértices:" << endl;
        for (int i = 0; i < contadorVertices; ++i) {
            cout << i << ": " << vertices[i] << endl;
        }
    }
};

int main() {
    // Grafo original
    Grafo g1(9);
    g1.agregarVertice("A");
    g1.agregarVertice("B");
    g1.agregarVertice("C");
    g1.agregarVertice("D");
    g1.agregarVertice("E");
    g1.agregarVertice("F");
    g1.agregarVertice("G");
    g1.agregarVertice("H");
    g1.agregarVertice("I");


    g1.agregarArista("A", "B", 3);
    g1.agregarArista("A", "G", 1);
    g1.agregarArista("A", "z", 1);
    g1.agregarArista("B", "C", 8);
    g1.agregarArista("B", "G", 6);
    g1.agregarArista("C", "H", 7);
    g1.agregarArista("C", "I", 1);
    g1.agregarArista("D", "G", 3);
    g1.agregarArista("D", "E", 10);
    g1.agregarArista("F", "H", 5);
    g1.agregarArista("F", "I", 8);
    g1.agregarArista("E", "G", 9);
    g1.agregarArista("E", "F", 2);

    cout << "Grafo Original:" << endl;
    g1.mostrarMatriz();
    g1.mostrarVertices();

    // Segundo grafo
    Grafo g2(7);
    g2.agregarVertice("A");
    g2.agregarVertice("B");
    g2.agregarVertice("C");
    g2.agregarVertice("D");
    g2.agregarVertice("E");
    g2.agregarVertice("F");
    g2.agregarVertice("G");

    g2.agregarArista("A", "B", 2);
    g2.agregarArista("A", "C", 3);
    g2.agregarArista("B", "D", 1);
    g2.agregarArista("C", "E", 4);
    g2.agregarArista("D", "F", 5);
    g2.agregarArista("E", "G", 2);
    g2.agregarArista("F", "G", 6);

    cout << "\nSegundo Grafo:" << endl;
    g2.mostrarMatriz();
    g2.mostrarVertices();

    // Tercer grafo
    Grafo g3(5);
    g3.agregarVertice("A");
    g3.agregarVertice("B");
    g3.agregarVertice("C");
    g3.agregarVertice("D");
    g3.agregarVertice("E");

    g3.agregarArista("A", "B", 1);
    g3.agregarArista("B", "C", 3);
    g3.agregarArista("C", "D", 4);
    g3.agregarArista("D", "E", 2);
    g3.agregarArista("A", "E", 5);

    cout << "\nTercer Grafo:" << endl;
    g3.mostrarMatriz();
    g3.mostrarVertices();

    return 0;
}