#include<iostream>
using namespace std;

double Langrange(int n, double valuable, double **xy){

    double *l=new double[n];
    for (int i=0; i<n; i++){
        l[i]=1.0;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (j!=i) l[i]*=(valuable-xy[j][0])/(xy[i][0]-xy[j][0]);
        }
    }

    double result=0;
    for (int i=0; i<n; i++){
        result+=l[i]*xy[i][1];
    }

    return result;
}

bool checkIfOkayLangrange(int n, double valuable, double **xy){
    double max=xy[0][0];
    double min=xy[0][0];
    for (int i=0; i<n; i++){
        if(xy[i][0]<min) min=xy[i][0];
        if(xy[i][0]>max) max=xy[i][0];

        for (int j=i+1; j<n; j++){
            //x nie moga sie powtarzac
            if (xy[i][0]==xy[j][0]) return false;
        }
    }
    //przekroczono przedzial x
    if (valuable<min || valuable> max) return false;
    
    return true;

} 
