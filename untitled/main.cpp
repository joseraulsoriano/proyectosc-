#include <iostream>
#include <memory>// Para std::unique_ptr

using namespace std;

// Clase template para División
template <typename T>
class Division {
public:
    Division(T numerator, T divisor) : numerator(numerator), divisor(divisor) {}

    // Método para realizar la división
    void calculate() {
        result = 0;
        remainder = numerator;
        while (remainder >= divisor) {
            remainder -= divisor;
            result++;
        }
    }

    // Método para mostrar el resultado
    void displayResult() const {
        cout << "\nEl resultado es: " << result;
        cout << "\nEl residuo es: " << remainder << endl;
    }

private:
    T numerator;
    T divisor;
    T result;
    T remainder;
};

int main() {
    // Uso de memoria dinámica y apuntadores inteligentes
    int num, div;
    cout << "\nIntroduce un valor para dividir: ";
    cin >> num;

    cout << "\nIngrese su divisor: ";
    cin >> div;

    // Crear un objeto de la clase Division usando un apuntador inteligente
    auto division = make_unique<Division<int>>(num, div);
    division->calculate();
    division->displayResult();

    return 0;
}
