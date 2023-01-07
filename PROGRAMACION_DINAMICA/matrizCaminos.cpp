#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    Dada una matriz de nxm se desea saber cuántos caminos existen desde (0,0) hasta (n-1, m-1). 
    Solo se puede avanzar hacia la derecha o hacia abajo.

    f(0, 0) = 0
    Casos borde:
        i == 0 -> f(i, j) = f(i, j-1)
        j == 0 -> f(i, j) = f(i - 1, j)

    f(i,j) = f(i-1,j) + f(i, j-1)
*/

int cantidadCaminos(int n, int m){
    int ** matriz = new int * [n]();
    for(int i = 0; i < n; i++) matriz[i] = new int [m]();

    matriz[0][0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i != 0 || j != 0){
                if(i == 0) matriz[i][j] = matriz[i][j-1];
                else if (j == 0) matriz[i][j] = matriz[i][j] = matriz[i-1][j];
                else matriz[i][j] = matriz[i-1][j] + matriz[i][j-1];
            }
        }
    }
    return matriz[n-1][m-1];
}

int main (){
    cout << "Inserte n: ";
    int n;
    cin >> n;

    cout << "Inserte m: ";
    int m;
    cin >> m;

    cout << "La cantidad de caminos desde (0, 0) a (" << n-1 << ","<< m-1 << ") en la matriz es "<< cantidadCaminos(n, m) << endl; 


    return 0;
}