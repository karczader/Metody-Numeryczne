#include <iostream>
#include <cmath>
#include "../NumericalMethods.h"
using namespace std;

int main(){
    srand(time(NULL));
    int n=4;
    double xp=1;
    double xk=5;
    cout<<"Zakres x: ["<<xp<<","<<xk<<"]"<<endl;
    
    cout<<endl<<"* * * METODA SIMSPONA * * *"<<endl;
    double resultOfMethodSimpson=methodSimspon(n, xp, xk);
    cout<<"Wynik: "<<resultOfMethodSimpson<<endl;

    cout<<endl<<"* * * METODA MONTE CARLO * * *"<<endl;
    double resultOfMethodMonteCarlo=methodMonteCarlo(n, xp, xk);
    cout<<"Wynik: "<<resultOfMethodMonteCarlo<<endl;



    return 0;
}