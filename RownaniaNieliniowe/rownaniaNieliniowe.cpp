#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "../NumericalMethods.h"

using namespace std;

double EPS= 1e-14;
//pobawic sie innymi dokladnosciami

int main()
{

    //double a=-1.0, b=-1.1;
    double a=1, b=2;
    
   
    double x1;
    double *wsk_x=&x1;
    if(bisectionMethod(a,b, EPS, wsk_x)){
        cout <<"* * * METODA BISEKCJI * * *"<<endl
        << "Wartosc pierwiastka: " << x1 << endl
        <<"Dokladnosc: "<<EPS<<endl<<endl;
    }
   

    if(newtonRaphsonMethod(a, b, EPS, wsk_x)){
        cout <<"* * * METODA NEWTONA-RAPSHODA * * *"<<endl
        << "Wartosc pierwiastka: " << x1 << endl
        <<"Dokladnosc: EPS: "<<EPS<<endl;
    }
    
    
    return 0;
}
