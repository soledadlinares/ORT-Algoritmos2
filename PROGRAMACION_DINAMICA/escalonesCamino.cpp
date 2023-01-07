#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// f(n) = p(n) + min(f(n-1), f(n-1))

int min (int a, int b){
    return (a < b) ? a : b;
}

void escalonesPonderadosCaminoCalculado(int n, int pesos []){
    int * tab = new int[n+1]();
    tab[0] = 0;
    tab[1] = pesos[1];
    tab[2] = pesos[2];
    for (int i = 3; i <= n; i++){
        tab[i] = pesos[i] + min(tab[i-1],tab[i-2]);
    }
    cout << "Costo: " << tab[n] << endl;

    int index = n;
    while (index != 0){
        cout << "Vengo de: " << index << endl;
        index = tab[index - 1] < tab[index - 2] ? index - 1 : index - 2;
    }
    cout << "Vengo de: 0" << endl;
}

int main (){
    int n = 8;
    int pesos [9] = {0, 3, 2, 4, 6, 1, 1, 5, 3};
    
    escalonesPonderadosCaminoCalculado(n, pesos);


    return 0;
}