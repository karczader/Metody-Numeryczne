#include <iostream>
#include "../NumericalMethods.h"
#include <fstream>
#include <string>

using namespace std;

int main(){

    ifstream dane ("daneInterpolacja.txt");
    if(!dane) {
        cout<<"Eror: plik nie istnieje :(";
        return 0;
    }

    int n;
    double valuable;
    dane>>n;
    cout<<"Podaj liczbe dla ktorej chcesz obliczyc interpolacje: ";
    cin>>valuable;
    double **xy=new double*[n];
    for (int i=0; i<n; i++){
        xy[i]=new double[n];
    }    
    
    cout<<"X\tY"<<endl;
    for (int i=0; i<n; i++){
        if (dane.eof()){
            //za malo danych w pliku
            cout<<"Error: blednie przygotowany plik!";
            return 0;
        }
        dane>>xy[i][0];
        dane>>xy[i][1];
        cout<<xy[i][0]<<"\t"<<xy[i][1]<<endl;
    }
    //za duzo danych w pliku
    if (!dane.eof()){
        cout<<"Error: blednie przygotowany plik!";
        return 0;
    }

    if(checkIfOkayLangrange(n, valuable, xy)){
         double result=Langrange(n, valuable, xy);
        cout<<"Wynik: "<<result<<endl;
    }
    else{
        cout<<"Error: bledne dane"<<endl;
    }
   


    return 0;
}
