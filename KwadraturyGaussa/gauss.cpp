#include <iostream>
#include <fstream>
#include "../NumericalMethods.h"

using namespace std;



int main(){

    ifstream data ("data.txt");
    if(!data) {
        cout<<"Eror: plik nie istnieje :(";
        return 0;
    }
    
    double wspX[4];
    double wspY[4];
    cout<<"WSPX\tWSPY"<<endl;
    for (int i=0; !data.eof(); i++){
        data>>wspX[i];
        data>>wspY[i];
        cout<<wspX[i]<<"\t"<<wspY[i]<<endl;
    }

    double result=area(wspX, wspY);
    cout<<endl<<"Powierzchnia jest rowna "<<result<<endl;

   
   

    return 0;
}
