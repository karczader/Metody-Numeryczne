#include <iostream>
#include <cmath>
#include <iomanip>
#include "../NumericalMethods.h"

using namespace std;

int main()
{
    double x0;
    double a = -1.1;  
    double b = -1.0;  
    bool result = falsi(a, b, x0);
   

    if (result) cout << "Pierwiastek x0 = "  << x0 << endl
        << "Wartosc funkcji f(x0) = " << f(x0) << endl
        << "Dokladnosc dla y epsy = "  << EPS << endl;

    return 0;
}