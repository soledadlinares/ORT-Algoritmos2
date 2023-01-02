#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int maximo_tres(int a, int b, int c){
    if (a > b) return a > c ? a : c;
    return b > c ? b : c;
}

int maxSecInter(int arr [], int mitad, int inicio, int fin){
    int max = arr[mitad];
    int acumulado = arr[mitad];
    //Sumamos hacia la izquierda
    for (int i = mitad -1; i >= inicio; i--){
        acumulado += arr[i];
        if (max < acumulado) max = acumulado;
    }

    acumulado = max;
    //Sumamos hacia la derecha
    for(int i = mitad + 1; i <= fin; i++){
        acumulado += arr[i];
        if (max < acumulado) max = acumulado;
    }

    return max;
}

int DACMaxSecuencia (int arr [], int inicio, int fin){
    if(inicio == fin) return arr[inicio];

    int mitad = (inicio + fin) / 2;

    int max_secIzq = DACMaxSecuencia(arr, inicio, mitad);
    int max_secDer = DACMaxSecuencia(arr, mitad + 1, fin);

    return maximo_tres(max_secIzq, max_secDer, maxSecInter(arr, mitad, inicio, fin));
}

int main (){
    int arr [] = {-2, -5, 4, -2, -3, 1, -5, -6};
    int maxSec = DACMaxSecuencia(arr, 0, sizeof(arr)-1);

    cout << maxSec << endl;
    return 0;
}