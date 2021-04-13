#include <iostream>
#include <cmath>
#include "../NumericalMethods.h"
using namespace std;

int main(){
    srand(time(NULL));
    int n=4;
    double xp=1;
    double xk=5;
    
    double resultOfMethodSimpson=methodSimspon(n, xp, xk);
    cout<<"Wynik uzyskany za pomocą metody Simspona: "<<resultOfMethodSimpson<<endl;

   
    double resultOfMethodMonteCarlo=methodMonteCarlo(n, xp, xk);
    cout<<"Wynik uzyskany za pomocą metody Monte Carlo: "<<resultOfMethodMonteCarlo<<endl;



    return 0;
}