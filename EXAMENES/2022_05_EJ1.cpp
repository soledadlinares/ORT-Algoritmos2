#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    EJERCICIO 1:
    Dado un array de enteros y su tamaño, se pide comprobar si es un MaxHeap válido.
    - La raiz empieza en 0
    - Debe resolverse en O(N) peor caso siendo N el tamaño del array.
    - Cualquier TAD/estructura auxiliar hay que implementarla.
*/

bool esMaxHeap(int * arr, int tamanio){
    if(tamanio == 0 || tamanio == 1) return true;
    bool retorno = true;
    for (int i = tamanio - 1; i > 1 && retorno; i--){
        if(arr[i] > arr[i/2]){
            retorno = false;
        }
    }

    return retorno;
}


int main (){
    int arr1 [] = {1, 3, 4, 5, 6};
    int tam1 = 5;
    bool es1 = esMaxHeap(arr1, tam1);
    if(es1) cout << "arr1 es max heap" << endl;
    else cout << "arr1 no es max heap" << endl;

    int arr2 [] = {6, 5, 4, 3, 1};
    int tam2 = 5;
    bool es2 = esMaxHeap(arr2, tam2);
    if(es2) cout << "arr2 es max heap" << endl;
    else cout << "arr2 no es max heap" << endl;

    return 0;
}