#include<iostream>
#include<cmath>
#include "../NumericalMethods.h"
using namespace std;


int main()
{
    double b= 0.2, h= 0.1, x0 = 0, y0 = 1;
    cout<<"Rozwiazanie rownan rozniczkowych metoda RK4:"<<endl;
    double result=RK4(b, x0, y0, h, f);
    cout<<"Wynik koncowy: "<<result;

    return 0;
}

