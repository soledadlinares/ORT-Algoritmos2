#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int max (int a, int b){
    return (a > b) ? a : b;
}

//Moclila 0-1
int mochila01Memo(int c, int fin, int valores [], int pesos [], int ** memo){
    if(c == 0 || fin < 0) return 0;
    if(memo[fin][c] != -1) return memo[fin][c];
    if (pesos[fin] > c) return mochila01Memo(c, fin - 1, valores, pesos, memo);

    int v_usandoObjeto = valores[fin] + mochila01Memo(c - pesos[fin], fin - 1, valores, pesos, memo);
    int v_noUsandoObjeto = mochila01Memo(c, fin - 1, valores, pesos, memo);

    memo[fin][c] = max(v_usandoObjeto, v_noUsandoObjeto);
    return memo[fin][c];
}

int mochila01(int c, int fin, int valores [], int pesos []){
    int ** memo = new int * [fin + 1] ();
    for (int i = 0; i <= fin; i++){
        memo[i] = new int [c + 1] ();
        for (int j = 0; j <= c; j++) memo[i][j] = -1;
    }
    return mochila01Memo(c, fin, valores, pesos, memo);
}


int main (){
    cout << "Ingrese cantidad de elementos: ";
    int cant;
    cin >> cant;

    int valores [cant];
    int pesos [cant];
    int capacidad = 50;

    for (int i = 0; i < cant; i++){
        valores[i] = 1 + rand() % 10;
        pesos[i] = 1 + rand() % 100;
    }

    cout << "El valor de la mochila es: " << mochila01(capacidad, cant - 1, valores, pesos) << endl;
    return 0;
}