#include <iostream>
using namespace std;


class loop
{
private:
public:
};
int main()
{
    int i, N, contador;

    cout << "Introduzca tope: ";
    cin >> N;   // se inicia N

    contador = 0;
    cout << "\ncontador incializado: " << contador;

    for (i=1; i<=N; i=i+1)
    {
        /// i++   es equivalente a i=i+1
        // equivalente a "para" (for)
        // se crea un ciclo de N repeticiones
        contador = contador + 1;
        cout << "\ncontador = " << contador;
    }
    cout << "\ncontador(final) = " << contador;

    return 0;
}