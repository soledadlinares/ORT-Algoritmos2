#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// f(n) = p(n) + min(f(n-1), f(n-1))

int min (int a, int b){
    return (a < b) ? a : b;
}

int escalonesPonderados(int n, int pesos []){
    int * tab = new int[n+1]();
    tab[0] = 0;
    tab[1] = pesos[1];
    tab[2] = pesos[2];
    for (int i = 3; i <= n; i++){
        tab[i] = pesos[i] + min(tab[i-1],tab[i-2]);
    }
    return tab[n];
}

int main (){
    int n = 8;
    int pesos [9] = {0, 3, 2, 4, 6, 1, 1, 5, 3};
    
    cout << "El costo de subir los escalones es "  << escalonesPonderados(n, pesos) << endl;


    return 0;
}