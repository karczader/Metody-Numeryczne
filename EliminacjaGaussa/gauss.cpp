#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "../NumericalMethods.h"

using namespace std;

void show_matrix(int n, double **matrix){
    for (int i=0; i<n; i++){
        for (int j=0; j<=n; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main(){

    ifstream data ("dane.txt");
     if(!data) {
        cout<<"Eror: file doesn't exist";
        return 0;
    }
    int n;
    data>>n;

    double **matrix=new double*[n];
    for (int i=0; i<n; i++) {
        matrix[i]=new double[n+1];
         for (int j=0; j<=n; j++){
            data>>matrix[i][j];
        }
    }

    for (int i=0; i<n; i++){
        if(matrix[i][i]==0) {
            cout<<"Error: zero is on the diagonal";
            for (int i=0; i<n; i++) delete[] matrix[i];
            delete[] matrix;
            return 0;
        }
    }

    cout<<"* * * MACIERZ * * *"<<endl;
    show_matrix(n, matrix);

    double *result=new double[n];
    if(gaussEliminationMethod(n, matrix, result)){
        cout<<"* * * METODA ELIMINACJI GAUSSA * * *"<<endl;
        show_matrix(n, matrix);
        
        cout<<"WYNIKI: "<<endl;
        for(int i=0; i<n; i++ ) cout <<"x"<<i+1<<" = "<<setw(9)<<result[i]<< endl;

        for (int i=0; i<n; i++) delete[] matrix[i];
        delete[] matrix;
        delete[] result;
    }
    else{
        cout<<"Error: zero is on the diagonal";

        for (int i=0; i<n; i++) delete[] matrix[i];
        delete[] matrix;
        delete[] result;
        return 0;
    }
 

   


    return 0;
}
