#include<iostream>
#include<cmath>
#include "./NumericalMethods.h"
using namespace std;

int main()
{
    double b= 0.3, h= 0.1, x0 = 0, y0 = 2;
    cout<<"Rozwiazanie rownan rozniczkowych metoda Heuna (RK2)"<<endl;
    double result=RK2(b, x0, y0, h, f);
    cout<<"Wynik koncowy: "<<result;

  
    return 0;
}

