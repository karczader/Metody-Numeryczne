#include<iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return sin(x * x - x + 1 / 3.0) + 0.5 * x;
}

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


//x*x*x+2;
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
        result+=f(xp+i)+4*f(xp+i+1)+f(xp+i+2);
    result*=h/3;
    return result;
}

double methodMonteCarlo(int n, double xp, double xk){
    double valuable;
    int nextStep=((xk-xp)/n);
    double result=0;
    cout<<"Wylosowane wartości x: "<<endl;
    for (int i=xp; i<=n; i+=nextStep){
        valuable=rand()%(((i+1)*10)-(i*10))+(i*10);
        valuable/=10;
        cout<<valuable<<endl;
        result+=(f(valuable)/n);
    }
    result*=abs(xk-xp);
    return result;
}

//ROWNANIA LINIOWE
bool gaussEliminationMethod(int n, double **matrix, double *X){
    
  double temp;

    //eliminacja współczynników
    for(int i=0; i<n-1; i++) 
    {
        for(int j =i+1; j<n; j++)
        {
            temp=matrix[j][i]/matrix[i][i];
            for(int k=0; k<= n; k++) matrix[j][k]-=temp*matrix[i][k];
        }
    }

    for (int i=0; i<n; i++){
        if(matrix[i][i]==0) {
            cout<<"Error: zero is on the diagonal";
            return false;
        }
    }

    //obliczenie niewiadomych
    for(int i=n-1; i>= 0; i--)
    {
        temp=matrix[i][n];
        for(int j=n-1; j>=i+1; j--) temp-=matrix[i][j]*X[j];
        X[i]=temp/matrix[i][i];
    }

    return true;
}

//ROWNANIA NIELINIOWE

double fp(double x)
{
  return x * x * (2 * x * x * cos(x * x - 1) + 3 * sin(x * x - 1) + 4 * x - 3);
}

//sin(x*x-x+1/3.0)+0.5*x;
//x*x*x-3*x*x-2*x+5;
//x * x * x * (x + sin(x * x - 1) - 1) - 1;
bool bisectionMethod(double a, double b, double EPS, double *x){

    if(f(a)*f(b)>0) {
        cout << "Error: wartosci funkcji na krancach przedzialu maja te same znaki";
        return false;
    }

    double x1;
    while(true) {
        x1 = (a + b) / 2;
        if(fabs(f(x1))<EPS) break;
        if(f(a) *f(x1)<0) b=x1;
        else a = x1;
    }
    *x=x1;
    return true;
}

bool newtonRaphsonMethod(double a, double b, double EPS, double *x){

    if(f(a)*f(b)>0) {
        cout << "Error: wartosci funkcji na krancach przedzialu maja te same znaki";
        return false;
    }

    double x0, x1;
    x0=a;
    x1 = x0-1; 
    while ((fabs(x1-x0)>EPS) && (fabs(f(x0))>EPS))
    {
        if(fabs(fp(x0))<EPS)
        {
            cout<<"Error: zly punkt startowy"<<endl;
            break;
        }
        x1=x0;
        x0=x0-f(x0)/fp(x0);
    }
    *x=x0;
    return true;
}

//KWADRATURY GAUSSA
double area(double wspX[], double wspY[]){
    
    double waga[2] = {1.0, 1.0};
    double punkt[2] = {-0.5773502692, 0.5773502692};
    double fKsztalt[2][2][4];
    double pochKsi[2][4], pochNi[2][4], funDetJ[2][2];
    double dxdKsi, dydKsi, dxdNi, dydNi;

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 2; i++){
            fKsztalt[i][j][0] = 0.25*(1.0-punkt[i])*(1.0-punkt[j]);
            fKsztalt[i][j][1] = 0.25*(1.0+punkt[i])*(1.0-punkt[j]);
            fKsztalt[i][j][2] = 0.25*(1.0+punkt[i])*(1.0+punkt[j]);
            fKsztalt[i][j][3] = 0.25*(1.0-punkt[i])*(1.0+punkt[j]);

            pochKsi[j][0] = -0.25*(1.0-punkt[j]);
            pochKsi[j][1] = 0.25*(1.0-punkt[j]);
            pochKsi[j][2] = 0.25*(1.0+punkt[j]);
            pochKsi[j][3] = -0.25*(1.0+punkt[j]);
            pochNi[i][0] = -0.25*(1.0-punkt[i]);
            pochNi[i][1] = -0.25*(1.0+punkt[i]);
            pochNi[i][2] = 0.25*(1.0+punkt[i]);
            pochNi[i][3] = 0.25*(1.0-punkt[i]);
        }
    }

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 2; i++){
            dxdKsi = pochKsi[j][0]*wspX[0] + pochKsi[j][1]*wspX[1] + pochKsi[j][2]*wspX[2] + pochKsi[j][3]*wspX[3];
            dydKsi = pochKsi[j][0]*wspY[0] + pochKsi[j][1]*wspY[1] + pochKsi[j][2]*wspY[2] + pochKsi[j][3]*wspY[3];
            dxdNi = pochNi[i][0]*wspX[0] + pochNi[i][1]*wspX[1] + pochNi[i][2]*wspX[2] + pochNi[i][3]*wspX[3];
            dydNi = pochNi[i][0]*wspY[0] + pochNi[i][1]*wspY[1] + pochNi[i][2]*wspY[2] + pochNi[i][3]*wspY[3];
            funDetJ[i][j] = dxdKsi*dydNi - dxdNi*dydKsi;
        }
    }

    double area = 0.0;

    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 2; i++){
            area += abs(funDetJ[i][j])*waga[i]*waga[j];
        }
    }

    return area;

}

//METODA ZLOTEGO ŚRODKA

//x*x-3;
double optymalizacja(double a, double b, double GOLD_NUMBER, double EPS){
    double xl, xp;
    while((b-a)>EPS){

        xl=b-GOLD_NUMBER*(b-a);
        xp=a+GOLD_NUMBER*(b-a);
        if (f(xl)>f(xp)) a=xl;
        else b=xp;
    }
    return xl;
}


//METODA FAŁSZYWEJ PROSTEJ
double EPS = 1e-14;

bool falsi(double a, double b, double &x0){
    if (f(a) * f(b) > 0) {
        cout << "Blad";
        return false;
    }

    else
    {
        while (true)
        {
            x0 = (f(a) * b - f(b) * a) / (f(a) - f(b));
            if (fabs(f(x0)) < EPS) break;
            if (f(a) * f(x0) < 0) b = x0;
            else a = x0;
        }
        return true;
    }
}

//METODA EULERA
double f(double x, double y)
{
    return x*x+y;
};

double Euler(double x0, double y0, double b, double h, double f(double, double))
{
    double n = (b-x0)/h;

    double x1, y1;
    for (int i = 0; i < n; ++i)
    {
        x1 = x0 + h;
        y1 = y0 + h * f(x0, y0);
        x0 = x1;
        y0 = y1;
    }
    return y1;
}