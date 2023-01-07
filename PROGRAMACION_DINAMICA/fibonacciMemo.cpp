#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//Usamos memoizacion - que es una herramienta utilizada en programacion dinamica

int fibonacciMemoizacion(int n, int * res){
    if(n == 0 || n == 1) return n;
    if (res[n] == -1) {
        res[n] = fibonacciMemoizacion(n-1, res) + fibonacciMemoizacion(n-2, res);
    }
    return res[n];
}

int fibonacci(int n){
    int * res = new int [n + 1]();
    for (int i = 0; i < n + 1; i++) res[i] = -1;
    return fibonacciMemoizacion(n, res);
}


int main (){
    cout << "Ingrese un numero: ";
    int n;
    cin >> n;
    cout << "El fibonacci de " << n << " es: " << fibonacci(n) << endl;


    return 0;
}