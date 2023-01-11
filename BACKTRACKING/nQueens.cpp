#include <climits>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

void colocoReina(int fila, int columna, bool ** tablero){
    tablero[fila][columna] = true;
}

void quitoReina(int fila, int columna, bool ** tablero){
    tablero[fila][columna] = false;
}

//si estoy en la ultima columna
bool esSolucion(int columna, int N){
    return columna == N - 1;
}

void imprimirTablero(int N, bool ** tablero){
    for (int fila = 0; fila < N; fila ++){
        for (int columna = 0; columna < N; columna++)
        {
            cout << "[";
            if (tablero[fila][columna]) cout << "Q";
            else cout << " ";
            cout << "]";
        }
        cout << endl;
    }
    cout << endl;
}

bool dentroDelTablero(int fila, int columna, int N){
    return fila < N && columna < N && fila >= 0 && columna >= 0;
}

bool esSeguraDeColocar(int fila, int columna, bool ** tablero, int N){
    //chequeo hacial a izquierda
    for (int f = fila, c = columna; dentroDelTablero(f, c, N); c--)
    {
        if(tablero[f][c]) return false;
    }
    //chequeo hacia arriba a la izquierda
    for (int f = fila, c = columna; dentroDelTablero(f, c, N); c--, f--)
    {
        if(tablero[f][c]) return false;
    }
    //chequeo hacia abajo a la izquierda
    for (int f = fila, c = columna; dentroDelTablero(f, c, N); c--, f++)
    {
        if(tablero[f][c]) return false;
    }
    return true;
}

void nQueensEnumeracion(int N, int colActual, bool ** tablero, int & cantidadSoluciones){

    //movimientos posibles
    for (int filaCandidata = 0; filaCandidata < N; filaCandidata++){

        //valido si la reina no esta amenazada al colocar
        if(esSeguraDeColocar(filaCandidata, colActual, tablero, N)){

            colocoReina(filaCandidata, colActual, tablero);

            //aca es donde resuelvo el problema (dependiendo que problema es)
            if(esSolucion(colActual, N)){
                cout << "Encontre solucion!" << endl;
                imprimirTablero(N, tablero);
                cantidadSoluciones++;
            } else {
                nQueensEnumeracion(N, colActual + 1, tablero, cantidadSoluciones);
            }
            //---------------------------------------------------------------

            quitoReina(filaCandidata, colActual, tablero); // esto es el back del backtracking
        }
    }
}

void nQueensDecision(int N, int colActual, bool ** tablero, bool & exito){
    if (!exito){
        //movimientos posibles
        for (int filaCandidata = 0; filaCandidata < N; filaCandidata++){

            //valido si la reina no esta amenazada al colocar
            if(esSeguraDeColocar(filaCandidata, colActual, tablero, N)){

                colocoReina(filaCandidata, colActual, tablero);

                //aca es donde resuelvo el problema (dependiendo que problema es)
                if(esSolucion(colActual, N)){
                    cout << "Encontre solucion!" << endl;
                    imprimirTablero(N, tablero);
                    exito = true;
                } else {
                    nQueensDecision(N, colActual + 1, tablero, exito);
                }
                //---------------------------------------------------------------

                quitoReina(filaCandidata, colActual, tablero); // esto es el back del backtracking
            }
        }       
    }
}

int main(){
    int N;
    cout << "Inserte N " << endl;
    cin >> N;

    bool ** tablero = new bool * [N];
    for (int i = 0; i < N; i++) {
        tablero[i] = new bool [N];
        for (int j = 0; j < N; j ++){
            tablero[i][j] = false;
        }
    }
    int cantidadSoluciones = 0;
    bool exito = false;
    /*
    nQueensEnumeracion(N, 0, tablero, cantidadSoluciones);
    cout << "Existen " << cantidadSoluciones << " soluciones." << endl;
    */
    nQueensDecision(N, 0, tablero, exito);

    return 0;
}