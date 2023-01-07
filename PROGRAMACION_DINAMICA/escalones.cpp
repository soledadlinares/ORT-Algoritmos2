#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    Hay N escalones, una persona parada al principio de la escalera(debajo) quiere alcanzar el final de la esta. 
    La persona puede subir de a 1 escalón o de a dos (saltito) a la vez. 
    Se quiere saber la cantidad de formas que se puede subir.

    ES UN PROBLEMA DE COMBINATORIA -> Indicio de que es un problema de programacion dinamica
*/

/*
   Podemos pensarlo en "cuantas formas tengo de llegar al ultimo escalon" y pensarlo como una funcion recursiva:
   f(0) = 0
   f(1) = 1 
   f(2) = 2

   f(n) = f(n-1) + f(n-2) -->Es fibonacci 
*/

//MEMOIZACION
int escalonesMemoizacion(int n, int * res){
    if(n == 0 || n == 1 || n == 2) return n;
    if (res[n] == -1) {
        res[n] = escalonesMemoizacion(n-1, res) + escalonesMemoizacion(n-2, res);
    }
    return res[n];
}

int escalones_v1(int n){
    int * res = new int [n + 1]();
    for (int i = 0; i < n + 1; i++) res[i] = -1;
    return escalonesMemoizacion(n, res);
}

//TABULACION
long escalonesTabulacion(int n){
    int * tab = new int[n+1]();
    tab[0] = 1;
    tab[1] = 1;
    tab[2] = 2;
    for (int i = 3; i <= n; i++){
        tab[i] = tab[i-1] + tab[i-2];
    }
    return tab[n];
}

int main (){
    cout << "Ingrese cantidad de escalones: ";
    int n;
    cin >> n;
    cout << "La cantidad de formas de subir los " << n << " escalones con memoizacion es: " << escalones_v1(n) << endl;
    cout << "La cantidad de formas de subir los " << n << " escalones con tabulacion es: " << escalonesTabulacion(n) << endl;


    return 0;
}