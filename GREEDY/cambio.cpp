#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    Se requiere devolver el cambio con la cantidad menor de monedas posible.
    - Par armar el problema tenemos los billetes/monedas ordenadas de mayor a menor.
    - Vamos entregando la mayor cantidad de cambio mayor hasta agotar la posibilidad de entregar ese cambio y asi pasamos
    a un cambio menor.
*/

void cambio (int billetes [], int cantBilletes, int costo, int pago) {

    int entregar = pago - costo;
    
    if (entregar <= 0) cout << "No se retorna cambio" << endl;
    else {
        for (int j = 0; j < cantBilletes; j++){
            int billete = billetes[j];
            int cantidad = entregar/billete;
            entregar = entregar % billete;
            if (cantidad != 0) cout << "Se entregan " << cantidad << " billetes de " << billete << endl;
        }
    }
}

void cambioConDisponibilidad (int billetes [], int disponibles [], int cantBilletes, int costo, int pago) {

    int entregar = pago - costo;
    
    if (entregar <= 0) cout << "No se retorna cambio" << endl;
    else {
        for (int j = 0; j < cantBilletes; j++){
            int billete = billetes[j];
            int cantidad = entregar/billete;

            if (cantidad > disponibles[j]){
                cantidad = disponibles[j];
                entregar -= cantidad * disponibles[j];
            } else {
                entregar = entregar % billete;
            }

            if (cantidad != 0) cout << "Se entregan " << cantidad << " billetes de " << billete << endl;
        }
    }
}

int main (){
    int billetes [] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int disponibles [] = {4, 0, 6, 10, 7, 1, 14, 10, 0, 7, 1};
    cout << "Cambio infinito" << endl;
    cambio(billetes, 11, 23, 10023);
    cout << "Cambio con disponibilidad"<< endl;
    cambioConDisponibilidad(billetes, disponibles, 11, 23, 10023);
    
    return 0;
}