#include <iostream>
#include <stack>
using namespace std;
class Cola {
private:
    stack<int> pila1, pila2;
    void transfer() {
        while (!pila1.empty()) {
            pila2.push(pila1.top());
            pila1.pop();
        }
    }
public:
    void encolar(int x) {
        pila1.push(x);
    }
    void desencolar() {
        if (pila2.empty()) {
            if (pila1.empty()) {
                cout << "Cola vacía, no se puede desencolar." << endl;
                return;
            }
            transfer();
        }
        pila2.pop();
    }
    void imprimir() {
        if (pila2.empty()) {
            if (pila1.empty()) {
                cout << "Cola vacía." << endl;
                return;
            }
            transfer();
        }
        cout << pila2.top() << endl;
    }
};
int main() {
    Cola *c = new Cola();
    c->encolar(52);
    c->desencolar();
    c->encolar(4);
    c->imprimir();
    c->encolar(8);
    c->imprimir();
    c->encolar(60);
    c->encolar(78);
    c->desencolar();
    c->imprimir();
    return 0;
}
