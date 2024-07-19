#include <iostream> ///inclusión de librería

using namespace std;

int main()
{
    // Definición de variables
    int num;
    int div;
    /* Definición de variables en línea */
    int aux, cont;

    cout << "\nIntroduce un valor para dividir: ";
    cin >> num;

    cout << "\nIngrese su divisor: ";
    cin >> div;

    cont = 0;
    aux = num;

    do {
        aux = aux - div;
        cont = cont + 1;
    } while( aux > 0 );// Si 'aux' NO es menor o igual que 0

    if( aux < 0 )
    {
        cout << "\nEl resultado es: " << cont - 1;
        cout << "\nEl residuo es: " << aux + div;
    }
    else
    {
        cout << "\nEl resultado es: " << cont;
        cout << "\nEl residuo es: " << aux;
    }

    return 0;
}
