#include <climits>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

/*
    PARA EL PROBLEMA DEL CABALLO SE RESUELVE:
    1) DECISION: Una forma de llegar de A a B (coordenadas del tablero)
    2) ENUMERACION: Todas las formas de llegar de A a B
    3) OPTIMIZACION: La manera mas corta de llegar de A a B
    4) Mejor solucion + restricciones
*/

bool coordenadasValidas(int fila, int columna, int N){
    return fila < N && columna < N && fila >= 0 && columna >= 0;
}

bool paseAntes(int fila, int columna, int ** tablero){
    return tablero[fila][columna] != 0;
}

void realizarMovimiento(int fila, int columna, int movimiento, int ** tablero){
    tablero[fila][columna] = movimiento;
}

void deshacerMovimiento(int fila, int columna, int ** tablero){
    tablero[fila][columna] = 0;
}

bool esSolucion(int filaCandidata, int columnaCandidata, int filaDestino, int columnaDestino){
    return filaCandidata == filaDestino && columnaCandidata == columnaDestino;
}

void imprimir(int N, int ** tablero){
    for (int f = 0; f < N; f++)
    {
        for (int c = 0; c < N; c++)
        {
            cout << "[";
            //si hay paso por ahi
            if(tablero[f][c] < 10) cout << " ";
            cout << tablero[f][c];
            cout << "]";
        }
        cout << endl;
    }
    cout << endl;
}

void caballoDecision(int filaCandidata, int columnaCandidata, int filaDestino, int columnaDestino, int N, int movimiento, int ** tablero, bool & exito){
    if (!exito){

        if(coordenadasValidas(filaCandidata, columnaCandidata, N) && !paseAntes(filaCandidata, columnaCandidata, tablero)){

            realizarMovimiento(filaCandidata, columnaCandidata, movimiento, tablero);

            if(esSolucion(filaCandidata, columnaCandidata, filaDestino, columnaDestino)){

                imprimir(N, tablero);
                exito = true;

            } else {

                //movimientos posibles
                int d_filas [8] = {-2, -2, -1, 1, 2, 2, 1, -1};
                int d_columnas [8] = {-1, 1, 2, 2, 1, -1, -2, -2};
                for (int i = 0; i < 8; i++)
                {
                    caballoDecision(filaCandidata + d_filas[i], columnaCandidata + d_columnas[i], filaDestino, columnaDestino, N, movimiento + 1, tablero, exito);
                }
                
            }

            deshacerMovimiento(filaCandidata, columnaCandidata, tablero);

        }

    }
}



int main (){
    int N = 8;
    int ** tablero = new int * [N];
    for (int i = 0; i < N; i++) {
        tablero[i] = new int [N];
        for (int j = 0; j < N; j ++){
            tablero[i][j] = 0;
        }
    }
    bool exito = false;

    caballoDecision(0, 0, 7, 7, N, 1, tablero, exito);

    return 0;
}