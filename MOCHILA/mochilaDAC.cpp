#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;



//Vamos a hacer una mochila 0-1 --> retornando el valor en la mochila
int DACMochila01 (int capacidad, int fin, int valores [], int pesos []){
    if (capacidad == 0 || fin < 0) return 0; 
    if (pesos[fin] > capacidad) return DACMochila01(capacidad, fin - 1, valores, pesos);

    int valorMochilaUsandoObjeto = valores[fin] + DACMochila01(capacidad - pesos[fin], fin - 1, valores, pesos);
    int valorMochilaSinObjeto = DACMochila01(capacidad, fin - 1, valores, pesos);

    return max(valorMochilaUsandoObjeto, valorMochilaSinObjeto);
}



int main (){
    int valores [] = {60, 100, 120};
    int pesos [] = {10, 20, 30};
    int capacidad = 50;
    int cantidadElementos = sizeof(valores)/sizeof(int);

    cout << DACMochila01(capacidad, cantidadElementos - 1, valores, pesos) << endl;

    return 0;
}