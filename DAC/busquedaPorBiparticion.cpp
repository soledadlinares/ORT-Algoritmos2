#include <climits>
#include <string>
#include <iostream>
using namespace std;

bool DACBusquedaBiparticion(int arr [], int elemento, int inicio, int fin){
    if (inicio == fin) return arr[fin] == elemento;

    int mitad = (inicio + fin) / 2;

    if(arr[mitad] == elemento) return true;
    else{
        if(arr[mitad] > elemento) return DACBusquedaBiparticion(arr, elemento, inicio, mitad);
        else return DACBusquedaBiparticion(arr, elemento, mitad+1, fin);
    }
}

int main () {
    int prueba [] = {2, 4, 6, 8, 10, 13, 15, 22, 100, 102, 1000, 2000, 3500};
    bool esta = DACBusquedaBiparticion(prueba, 11, 0, sizeof(prueba));

    if (esta) cout << "Si esta el elemento" << endl;
    else cout << "No esta el elemento" << endl;

    return 0;
}