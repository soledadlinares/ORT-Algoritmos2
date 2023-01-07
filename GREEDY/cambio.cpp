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
            cout << "Se entregan " << cantidad << " billetes de " << billete << endl;
        }
    }
}

int main (){
    int billetes [] = {2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    cambio(billetes, 11, 70, 2020);
    
    return 0;
}