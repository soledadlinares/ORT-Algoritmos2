#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//PROBLEMA DE PARCIAL
/*Algoritmo que reciba un array y retorne la posicion del mayor elemento multiplo de 3.
Si no hay multiplos de 3 se retorna -1
Si el mayor multiplo se repite se podra retornar la posicion de cualquiera de sus ocurrencias.
SE DEBE DIVIDIR EL PROBLEMA DE FORMA BALANCEADA.*/

bool esMultiploDeTres(int a){
    return a % 3 == 0;
}

int pisicionDelMayorMultiploDeTres(int arr [], int inicio, int fin){
    if(inicio == fin)
    {
        if(esMultiploDeTres(arr[inicio])) return inicio;
        else return -1;
    }
    
    int mitad = (inicio + fin)/2;

    int posIzq = pisicionDelMayorMultiploDeTres(arr, inicio, mitad);
    int posDer = pisicionDelMayorMultiploDeTres(arr, mitad + 1, fin);

    if (posIzq == -1) return posDer;
    if (posDer == -1) return posIzq;
    if (arr[posIzq] > arr[posDer]) return posIzq;
    else return posDer;
}


int main (){
    int valores [] = {3, -15, 100, 27, 49, 9, 27, 200, 8};
    cout << pisicionDelMayorMultiploDeTres(valores, 0, 8); << endl;
    return 0;
}