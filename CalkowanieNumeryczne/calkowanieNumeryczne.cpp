#include <iostream>
#include <fstream>
#include "../NumericalMethods.h"

using namespace std;


int main(){

    ifstream data ("dataIntegration.txt");
     if(!data) {
        cout<<"Eror: plik nie istnieje :(";
        return 0;
    }

    int size; //stopien wielomianu
    data>>size;
    double x[size+1]; //wspolczynniki wielomianu od najmniejszego
    for (int i=0; i<=size; i++){
        data>>x[i];
    }
    int n; //ilosc przedzialow
    data>>n;
    double xp, xk; //x poczatkowe i x koncowe
    data>>xp;
    data>>xk;

    double resultOfmethodRectangle=methodRectangle(n, xp, xk, x);
    cout<<"Wynik metody prostokatow: "<<resultOfmethodRectangle<<endl;
    double resultOfmethodTrapezoidal=methodTrapezoidal(n, xp, xk, x);
    cout<<"Wynik metody trapezow: "<<resultOfmethodTrapezoidal<<endl;


    return 0;
}