#include<iostream>
#include "../NumericalMethods.h"

using namespace std;


int main()
{
    double x0 = 0;
    double y0 = 0.1;
    double b=0.3;
    double h=0.1;

    cout<<"Dane poczatkowe: "<<endl
    <<"x0 = "<<x0<<endl
    <<"y0 = "<<y0<<endl
    <<"b = "<<b<<endl
    <<"h = "<<h<<endl<<endl;

    cout << "Rozwiazanie rownania obliczone metoda Eulera wynosi: " << 
    Euler(x0, y0, b, h, f) << endl;

    return 0;
}