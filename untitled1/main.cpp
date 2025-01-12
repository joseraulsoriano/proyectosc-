#include <iostream>
using namespace std;

class Contador {
private:
    int* contador; // Usamos un puntero para la memoria dinámica
    int tope;

public:
    Contador(int N, int valorInicial = 0) {
        contador = new int(valorInicial); // Inicializamos contador con memoria dinámica
        tope = N;
        cout << "contador inicializado: " << *contador << endl;
    }

    ~Contador() {
        delete contador; // Liberamos la memoria dinámica
    }

    void incrementar() {
        while (*contador < tope) {
            (*contador)++;
            cout << *contador << endl;
        }
    }

    void opuesto() {
        while (*contador > tope) {
            (*contador)--;
            cout << *contador << endl;
        }
    }
};

int main() {
    int N, valorInicial;
    cout << "Introduzca tope: ";
    cin >> N;
    cout << "Introduzca valor inicial (opcional, por defecto 0): ";
    cin >> valorInicial;

    Contador miContador(N, valorInicial);

    cout << "\nIncrementando contador:" << endl;
    miContador.incrementar();

    cout << "\nDecrementando contador:" << endl;
    Contador miContadorInverso(0, N); // Asumiendo que queremos contar hacia atrás hasta 0
    miContadorInverso.opuesto();

    return 0;
}
