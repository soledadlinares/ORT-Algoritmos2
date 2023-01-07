#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    Dado un conjunto de policías y otro de ladrones, se desea saber el máximo de ladrones capturados.
    - Cada policía puede atrapar como máximo a un ladrón.
    - El policía puede capturar a una máxima distancia dada (K).
*/

int indiceAProximoPolicia(string arr[], int tamanio, int indice){
    int resultado = indice;
    while(arr[resultado] != "P" && indice < tamanio){
        resultado++;
    }
    return resultado;
}

int indiceAProximoLadron(string arr[], int tamanio, int indice){
    int resultado = indice;
    while(arr[resultado] != "L" && indice < tamanio){
        resultado++;
    }
    return resultado;
}

int policiasYLadrones(string arr [], int k, int tamanio){
    
    int iPoli = indiceAProximoPolicia(arr, tamanio, 0);
    int iLadr = indiceAProximoLadron(arr, tamanio, 0);
    int atrapados = 0;
    while (iPoli < tamanio && iLadr < tamanio){
        if(iPoli < iLadr){
            while (iLadr - iPoli > k){
                iPoli = indiceAProximoPolicia(arr, tamanio, iPoli + 1);
            }
            if(iLadr - iPoli <= k){
                atrapados++;
            }
        } else {
            while (iPoli - iLadr > k){
                iLadr = indiceAProximoLadron(arr, tamanio, iLadr + 1);
            }
            if(iPoli - iLadr <= k){
                atrapados++;
            }
        }
        iPoli = indiceAProximoPolicia(arr, tamanio, iPoli + 1);
        iLadr = indiceAProximoLadron(arr, tamanio, iLadr + 1);
    }
    return atrapados;

}


int main (){
    string arr [] = {"P", "L", "P", "P", "P", "L", "L", "L", "P", "L", "P", "L", "L", "P", "L", "L", "L", "P", "L", "L"};//20
    int atrapados = policiasYLadrones(arr, 2, 20);
    cout << "Se atraparon "<< atrapados << " ladrones."<< endl;
    
    return 0;
}