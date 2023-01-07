#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int problemaDelCambio(int resto){
    int * res = new int [resto+1]();
    int monedas [] = {1, 2, 5, 10, 50};
    res[0] = 0;
    for (int i = 0; i <= resto; i++){
        int menor;
        menor = res[i - 1]; //Uso moneda de 1
        if (i >= 2) menor = min(menor, res[i-1]); //Trato de usar la de dos
        if (i >= 5) menor = min(menor, res[i-5]);
        if (i >= 10) menor = min (menor, res[i-10]);
        if (i >= 50) menor = min (menor, res[i-50]);
        res[i] = 1 + menor;
    }
    return res[resto];
}



int main (){



    return 0;
}