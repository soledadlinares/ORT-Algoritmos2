#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    EJERCICIO 2:
    Dado un tablero 8x8 y dos posiciones (inicial y final), se desea saber la CANTIDAD DE FORMAS POSIBLES diferentes que tiene
    el caballo para llegar desde la pos inicial a la final en MENOS DE K pasos.
    - Como máximo se puede pasar dos veces por el mismo casillero
    - Existe una matriz bool del mismo tamaño que el tablero donde indica las posiciones que deben estar si o si en el camino.

    Se pide implementar con BACKTRACKING
    - El algoritmo debe estar optimizado de forma de no intentar de hacer más de K pasos.
    - Un paso se cuenta cuando pasa de una casilla a la otra.
    - Las coordenadas/posiciones estan en base 0.
*/


// Es un problema de ENUMERACIÓN porque queremos saber la CANTIDAD DE FORMAS DIFERENTES que tiene el caballo de llegar de una pos a otra.





int caballo(int xi, int yi, int xf, int yf, int K, bool ** debePasar){
    int soluciones = 0;
    //Genero un tablero de int inicializado en 0 que me indica cuantas veces pase por un casillero
    int ** pase = new int * [8]();
    for(int i = 0; i < 8; i++){
        pase[i] = new int [8] ();
        for (int j = 0; j < 8; j++) {
            pase[i][j] = 0;
        }
    }

    caballoEnumeracion(xi, yi, xf, yf, K, 0, soluciones, debePasar, pase);

    return soluciones;
}

bool masDeKmMovimientos(int movimiento, int K){
    return movimiento > K;
}

bool coordenadasValidas(int x, int y){
    return x < 8 && y < 8 && x >= 0 && y >= 0;
}

bool paseDosVeces(int x, int y, bool ** pase){
    return pase[x][y] > 2;
}

void hacerMovimiento(int x, int y, int ** & pase, bool ** & debemosPasar){
    if(debemosPasar[x][y]) debemosPasar[x][y] = false;
    pase[x][y]++;
}

void desHacerMovimiento(int x, int y, int ** & pase){
    pase[x][y]--;
}

bool esSolucion(int xi, int yi, int xf, int yf, bool ** debemosPasar){
    bool pasePorTodos = true;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(debemosPasar[i][j]) pasePorTodos = false;
        }
    }
    return xi == xf && yi == yf && pasePorTodos;
}

void caballoEnumeracion(int xi, int yi, int xf, int yf, int K, int movimiento, int & soluciones, bool ** & debePasar, bool ** & pase){
    if(!masDeKMovimientos(movimiento, K)){

        if(coordenadasValidas(xi, yi) && !paseDosVeces(xi, yi, pase)){

            hacerMovimiento(xi, yi, movimiento, pase, debePasar);

            if(esSolucion(xi, yi, xf, yf, debePasar)){
                soluciones++;
            } else {
                int d_filas [8] = {-2, -2, -1, 1, 2, 2, 1, -1};
                int d_columnas [8] = {-1, 1, 2, 2, 1, -1, -2, -2};
                for (int = 0; i < 8; i++) caballoEnumeracion(xi + d_filas[i], yi + d_columnas[i], xf, yf, K, movimiento + 1, soluciones, debePasar, pase);
            }

            desHacerMovimiento(xi, yi, pase);
        }
    }
}


int main (){


    return 0;
}