#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int problemaDelCambio(int resto){
    int * res = new int [resto+1]();
    int monedas [] = {1, 2, 5, 10, 50};
    res[0] = 0;
    for (int i = 0; i <= resto; i++){
        int menor;
        menor = res[i - 1]; //Uso moneda de 1
        if (i >= 2) menor = min(menor, res[i-1]); //Trato de usar la de dos
        if (i >= 5) menor = min(menor, res[i-5]);
        if (i >= 10) menor = min (menor, res[i-10]);
        if (i >= 50) menor = min (menor, res[i-50]);
        res[i] = 1 + menor;
    }
    return res[resto];
}

void problemaDelCambioGuardandoMonedas(int resto){
    int * res = new int [resto+1]();
    int * use = new int [resto+1]();
    int monedas [] = {1, 2, 5, 10, 50};
    res[0] = 0;
    use[0] = 0;
    for (int i = 1; i <= resto; i++){
        int menor = res[i - 1]; //Uso moneda de 1
        int monedaUsada = 1;
        if (i >= 2){
            if (menor >= res[i - 2]){
                menor = res[i - 2];
                monedaUsada = 2;
            }
        } 
        if (i >= 5){
            if (menor >= res[i - 5]){
                menor = res[i - 5];
                monedaUsada = 5;
            }
        }
        if (i >= 10){
            if (menor >= res[i - 10]){
                menor = res[i - 10];
                monedaUsada = 10;
            }
        }
        if (i >= 50){
            if (menor >= res[i - 50]){
                menor = res[i - 50];
                monedaUsada = 50;
            }
        };
        res[i] = 1 + menor;
        use[i] = monedaUsada;
    }
    cout << "La cantidad minima de monedas es " << res[resto] << endl;
    int index = resto;
    while (index != 0)
    {
        cout << "Usé la moneda de " << use[index] << endl;
        index -= use[index];
    }
    
}

void problemaDelCambioV2(int cambio, int monedas [], int cantTiposMonedas){
    int * tab = new int [cambio + 1] ();
    int * use = new int [cambio + 1] ();
    tab[0] = 0;
    use[0] = 0;
    for (int i = 1; i <= cambio; i++){
        int menor = INT_MAX;
        int monedaUsada = INT_MAX;
        for (int j = 0; j < cantTiposMonedas; j++)
        {
            //si el valor de la moneda es menor que el cambio a dar
            if (monedas[j] <= i)
            {
                //si es posible de usar la moneda
                if (tab[i - monedas[j]] != INT_MAX)
                {
                    if (menor > tab[i - monedas[j]])
                    {
                        menor = tab[i - monedas[j]];
                        monedaUsada = monedas[j];
                    }  
                } 
            }
        }
        //pude dar cambio
        if(menor < INT_MAX){
            tab[i] = 1 + menor;
            use[i] = monedaUsada;
        } else{
            //no pude dar cambio
            tab[i] = menor;
            use[i] = monedaUsada;
        }
    }
    if(tab[cambio] == INT_MAX) cout << "No pude dar el cambio" << endl;
    else cout << "La cantidad minima de monedas es " << tab[cambio] << endl;
}


int main (){
    int monedas [] = {5, 3, 10};
    cout << "Introduzca un monto: ";
    int n;
    cin >> n;

    //problemaDelCambioGuardandoMonedas(n);
    problemaDelCambioV2(n, monedas, 3);

    return 0;
}