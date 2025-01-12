#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    int vertex;
    int weight;
    Node* next;

    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
};

class Graph {
private:
    int V; // Número de vértices
    Node** adjList; // Lista de adyacencia

public:
    Graph(int V) {
        this->V = V;
        adjList = new Node*[V];
        for (int i = 0; i < V; i++) {
            adjList[i] = nullptr;
        }
    }

    // Función para agregar una arista al grafo
    void addEdge(int u, int v, int weight) {
        // Restar 1 para convertir a índices base 0
        u--; v--;

        Node* newNode = new Node(v, weight);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = new Node(u, weight);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    int minKey(vector<int>& key, vector<bool>& inMST) {
        int min = INT_MAX, minIndex = -1;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    void prim() {
        vector<int> parent(V, -1); // Almacena el MST
        vector<int> key(V, INT_MAX); // Valores usados para elegir la arista mínima
        vector<bool> inMST(V, false); // Conjunto de vértices en el MST

        key[0] = 0; // Comenzar con el primer vértice
        parent[0] = -1; // El primer nodo es la raíz del MST

        int minCost = 0; // Costo total del MST

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, inMST); // Obtener el vértice con el valor mínimo
            if (u == -1) {
                cout << "No se puede construir el MST completo." << endl;
                return;
            }

            inMST[u] = true; // Agregar el vértice al MST

            Node* temp = adjList[u];
            while (temp != nullptr) {
                int v = temp->vertex;
                if (!inMST[v] && temp->weight < key[v]) {
                    parent[v] = u;
                    key[v] = temp->weight;
                }
                temp = temp->next;
            }
        }

        // Imprimir el MST en formato {(1,2), (2,3), ...}
        cout << "AEM = {";
        bool firstEdge = true; // Controlar la primera arista para evitar coma inicial
        for (int i = 1; i < V; i++) {
            if (parent[i] != -1) {
                if (!firstEdge) {
                    cout << ", ";
                }
                cout << "(" << parent[i] + 1 << "," << i + 1 << ")"; // Sumar 1 para convertir a notación 1-indexed
                minCost += key[i];
                firstEdge = false;
            }
        }
        cout << "}" << endl;

        // Imprimir el costo total mínimo del MST
        cout << "Costo mínimo del árbol de expansión mínima (MST): " << minCost << endl;
    }
};

int main() {
    int V = 7; // Número de vértices
    Graph g(V);

    // Agregar aristas al grafo
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 4);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 5, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 6, 5);
    g.addEdge(4, 5, 2);
    g.addEdge(4, 6, 8);
    g.addEdge(4, 7, 4);
    g.addEdge(5, 7, 6);
    g.addEdge(6, 7, 1);
    g.prim();


    int V2 = 6; // Número de vértices para el segundo grafo
    Graph g2(V2);
    g2.addEdge(1, 2, 3);
    g2.addEdge(1, 3, 2);
    g2.addEdge(1, 6, 10);
    g2.addEdge(2, 4, 4);
    g2.addEdge(2, 5, 3);
    g2.addEdge(2, 3, 2);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3,5,5);
    g2.addEdge(3,6,3);
    g2.addEdge(4,5,6);
    g2.addEdge(5,6,7);
    g2.prim();

    return 0;
}