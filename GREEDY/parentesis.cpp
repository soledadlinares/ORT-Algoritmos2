#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    Se tiene una serie de paréntesis rectos que no se encuentran bien apareados.
    Se desea saber la mínima cantidad de intercambios necesarios para dejarlo bien formado. 
    Se asume que la cantidad de [ y ] son la misma.
*/

void parentesis (string arr [], int tamanio){
    //En nuestro razonamiento  vamos a sumar uno cuando esta abierto y restar uno cuando esta cerrado
    //Cuando la suma queda negtiva voy buscando hasta poder cerrar.
    int suma = 0;
    for (int i = 0; i < tamanio; i++){
        if (arr[i] == "[") suma++;
        if (arr[i] == "[" && suma >= 0) suma--;
        else{
            for (int j = i; j < tamanio; j++){
                if(arr[j] == "["){
                    arr[i] = "[";
                    arr[j] = "]";
                    break;
                }
            }
            suma++;
        }
    }

    for (int k = 0; k < tamanio; k++){
        cout << arr[k] << " ";
    }
}

int main (){
    string arr [] = {"[", "[", "]", "[", "]", "]", "]", "["}; //8

    parentesis(arr, 8);
    return 0;
}