#include <cmath>
#include <iostream>
#include <utility> //return two variable for
#include <exception>
using namespace std;
pair<double, double>calcularEcuacion(int a, int b, int c)
{
    if( a==0)
        throw "No se puede dvidir entre 0";
    if((b*b)-4*a*c<0)
        throw "Num iMAGINARIO";
    return make_pair((-b + sqrt((b*b) - 4 * a * c)) / (2 * a), (-b - sqrt((b*b) - 4 * a * c)) / (2 * a));

}

int main()
{
    try
    {
        pair<double,double>solucion=calcularEcuacion(10,5,30);
        cout << "Las soluciones son: x1 = " << solucion.first<< " y x2 = " << solucion.second <<endl;

    }
    catch (const char *z)
    {
    cout<<"Excepcion: " <<z<<endl;
    }
        return 0;
}
