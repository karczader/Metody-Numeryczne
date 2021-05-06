#include <iostream>
#include "../NumericalMethods.h"
using namespace std;

double GOLD_NUMBER=0.61803398;
double EPS=1e-14;

int main(){

    double a=-2;
    double b=2;
    cout<<"Funckja: x^2-3"<<endl;
    cout<<"Przedzial: ["<<a<<"; "<<b<<"]"<<endl;
    
    
    cout<<"Szukane minimum: "<<myFunction(optymalizacja(a,b, GOLD_NUMBER, EPS))<<endl;

    return 0;
}