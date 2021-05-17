#include <iostream>
#include <fstream>
#include "../NumericalMethods.h"

using namespace std;

bool linapr(int n, double *x, double *y, double *a, double *b, double eps)
{
    double sx = 0, sy = 0, sxx = 0, sxy = 0, det;

    for (int k = 0; k < n; k++)
    {
        sx += x[k];
        sy += y[k];
        sxx += x[k] * x[k];
        sxy += x[k] * y[k];
    }
    if ((det = sxx * n - sx * sx) > -eps && det < eps)
        return false;
    *a = (sxy * n - sx * sy) / det;
    *b = (sxx * sy - sx * sxy) / det;
    return true;
}

const double EPS = 0.5e-8;

int main(){

    ifstream data ("dane.txt");
    if(!data) {
        cout<<"Eror: file doesn't exist :(";
        return 0;
    }

    int n;
    data>>n;

    double *x=new double[n];
    double *y=new double[n];
    cout<<"* * * PUNKTY * * * "<<endl;
    cout<<"X\tY"<<endl;
    for (unsigned int i=0; i<n; i++){
        data>>x[i];
        data>>y[i];
        cout<<x[i]<<"\t"<<y[i]<<endl;
    }
    double i, j=0;
    double *a=&i, *b=&j;

    linapr(n, x, y, a, b, EPS);
    cout<<endl<<"Wspolcznnik a: "<<i<<"\nWspolczynnik b: "<<j<<endl;
    if (j<0) cout<<"Funkcja: "<<i<<"x"<<j<<endl;
    else cout<<endl<<"Funkcja: "<<i<<"x+"<<j<<endl;


    



    return 0;
}