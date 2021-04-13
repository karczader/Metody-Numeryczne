#include<iostream>
#include <cmath>
using namespace std;


//INTERPOLACJA LANGRANGE
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


//INTERPOLACJA NEWTONA
double *IlorazyRoznicowedlaNewtona(int n, double **xy){
    double **tab=new double*[n];
    for (int i=0; i<n; i++){
        tab[i]=new double[i+1];
        tab[i][0]=xy[i][1];
    }
    for (int i=1; i<n; i++){
        for (int j=1; j<=i; j++) tab[i][j]=(tab[i][j-1]-tab[i-1][j-1])/(xy[i][0]-xy[i-j][0]);
    }

    double *w=new double[n];
    for (int i=0; i<n; i++){
        w[i]=tab[i][i];
    }

    return w;
}


double InterpolacjaNewtona(int n, double **xy, double *w, int valuable){

    int y=w[n-1];
    for (int i=n-2; i>=0; i--){
        y=y*(valuable-xy[i][0])+w[i];
    }
    return y;

}


//CAŁKOWANIE NUMERYCZNE

double function(int n, double j, double x[]){
    double result=0;
    for (int i=0; i<=n; i++) {
        result+=pow(j, i)*x[i];
    }
    return result;
}

double this_function(double x){
    return x*x*x+2;
}

double methodRectangle(int n, double xp, double xk, double x[]){
    double result=0;
    for (int i=xp+1; i<=xk; i++) result+=function(n, i, x);
    double dx=(xk-xp)/(n);
    result*=dx;
    return result;
}

double methodTrapezoidal(int n, double xp, double xk, double x[]){
    double result=0;
    for (int i=xp; i<xk; i++) result+=(function(n, i, x)+function(n, i+1, x))/2;
    double dx=(xk-xp)/(n);
    result*=dx;
    return result;
}

double methodSimspon(int n, double xp, double xk){
    double h=(xk-xp)/n;
    double result=0;
    for (int i=0; i<n; i+=2) 
        result+=this_function(xp+i)+4*this_function(xp+i+1)+this_function(xp+i+2);
    result*=h/3;
    return result;
}

double methodMonteCarlo(int n, double xp, double xk){
    double valuable;
    int nextStep=((xk-xp)/n);
    double result=0;
    for (int i=xp; i<=n; i+=nextStep){
        valuable=rand()%(((i+1)*10)-(i*10))+(i*10);
        valuable/=10;
        result+=(this_function(valuable)/n);
    }
    result*=abs(xk-xp);
    return result;
}