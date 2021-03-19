#include <iostream>
#include "../NumericalMethods.h"
#include <fstream>
using namespace std;


double **createTableFromFile(int n){
    fstream dane ("daneNewton.txt");
    if(!dane) {
        cout<<"Eror: plik nie istnieje :("<<endl;
        return 0;
    }

    double **xy=new double*[n];
    for (int i=0; i<n; i++){
        xy[i]=new double[n];
        dane>>xy[i][0];
        dane>>xy[i][1];
    }
    return xy;
}

int main()
{
    //zczytanie z pliku ilosci wierszy
    fstream dane ("daneNewton.txt");
    string line;
    int n=0;
    while(!dane.eof()){
        getline(dane, line);
        n++;
    }
    double **xy=createTableFromFile(n);
    double valuable;
    cout<<"Podaj liczbe dla ktorej chcesz obliczyc interpolacje: ";
    cin>>valuable;
   
    if(xy!=0){

        cout<<"WYPISANIE DANYCH"<<endl;
        cout<<"X \t Y"<<endl;
        for (int i=0; i<n; i++){
            cout<<xy[i][0]<<"\t"<<xy[i][1]<<endl;
        }
        if(checkIfOkayLangrange(n, valuable, xy)){
            double *w=IlorazyRoznicowedlaNewtona(n, xy);
            double results=InterpolacjaNewtona(n, xy, w, valuable);
            cout<<"Wynik: "<<results<<endl;
        }
        else cout<<"Error: bledne dane"<<endl;
       
        
        
    }
   
    return 0;
}