#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int max (int a, int b){
    return a > b ? a : b;
}

int mochila01(int capacidad, int N, int valores [], int pesos []){
    int ** matriz = new int * [N + 1] ();
    for (int i = 0; i <= N; i++)
    {
        matriz[i] = new int [capacidad + 1] ();
    }
    for (int i = 0; i <= capacidad; i++)
    {
        matriz[0][i] = 0;
    }
    for (int objetoHasta = 1; objetoHasta <= N; objetoHasta++)
    {
        for (int capacidadHasta = 0; capacidadHasta <= capacidad; capacidadHasta++)
        {
            //si no entra el objeto
            if(pesos[objetoHasta-1] > capacidadHasta){
                matriz[objetoHasta][capacidadHasta] = matriz[objetoHasta - 1] [capacidadHasta];
            } else {
                // en el caso que pueda usar el objeto
                int v_noUsarObjeto = matriz[objetoHasta - 1][capacidadHasta];
                int v_usarObjeto = valores[objetoHasta - 1] + matriz[objetoHasta - 1][capacidadHasta - pesos[objetoHasta - 1]];

                matriz[objetoHasta][capacidadHasta] = max(v_noUsarObjeto, v_usarObjeto);
            }
        }  
    }
    return matriz[N][capacidad];
}

int mochila0INF(int capacidad, int N, int valores [], int pesos []){
    int ** matriz = new int * [N + 1] ();
    for (int i = 0; i <= N; i++)
    {
        matriz[i] = new int [capacidad + 1] ();
    }
    for (int i = 0; i <= capacidad; i++)
    {
        matriz[0][i] = 0;
    }
    for (int objetoHasta = 1; objetoHasta <= N; objetoHasta++)
    {
        for (int capacidadHasta = 0; capacidadHasta <= capacidad; capacidadHasta++)
        {
            //si no entra el objeto
            if(pesos[objetoHasta-1] > capacidadHasta){
                matriz[objetoHasta][capacidadHasta] = matriz[objetoHasta - 1] [capacidadHasta];
            } else {
                // en el caso que pueda usar el objeto
                int v_noUsarObjeto = matriz[objetoHasta - 1][capacidadHasta];
                int v_usarObjeto = valores[objetoHasta - 1] + matriz[objetoHasta][capacidadHasta - pesos[objetoHasta - 1]];

                matriz[objetoHasta][capacidadHasta] = max(v_noUsarObjeto, v_usarObjeto);
            }
        }  
    }
    return matriz[N][capacidad];
}

void mochila01imprimiendoObjetos(int capacidad, int N, int valores [], int pesos []){
    int ** matriz = new int * [N + 1] ();
    for (int i = 0; i <= N; i++)
    {
        matriz[i] = new int [capacidad + 1] ();
    }
    for (int i = 0; i <= capacidad; i++)
    {
        matriz[0][i] = 0;
    }
    for (int objetoHasta = 1; objetoHasta <= N; objetoHasta++)
    {
        for (int capacidadHasta = 0; capacidadHasta <= capacidad; capacidadHasta++)
        {
            //si no entra el objeto
            if(pesos[objetoHasta-1] > capacidadHasta){
                matriz[objetoHasta][capacidadHasta] = matriz[objetoHasta - 1] [capacidadHasta];
            } else {
                // en el caso que pueda usar el objeto
                int v_noUsarObjeto = matriz[objetoHasta - 1][capacidadHasta];
                int v_usarObjeto = valores[objetoHasta - 1] + matriz[objetoHasta - 1][capacidadHasta - pesos[objetoHasta - 1]];

                matriz[objetoHasta][capacidadHasta] = max(v_noUsarObjeto, v_usarObjeto);
            }
        }  
    }
    cout << "El valor de la mochila 0-1 es : " << matriz[N][capacidad] << endl;
    //vamos a imprimir los objetos que colocamos en la mochila
    int capacidadIndex = capacidad;
    int objetoIndex = N;
    while (objetoIndex > 0)
    {
        //si use el objeto
        if(matriz[objetoIndex][capacidadIndex] != matriz[objetoIndex - 1][capacidadIndex]){
            cout << "Use el objeto " << objetoIndex << " con peso " << pesos[objetoIndex - 1] << " y valor " << valores[objetoIndex - 1] << endl;
            capacidadIndex-= pesos[objetoIndex - 1];
        }
        objetoIndex--;
    }
    
}

void mochila0INFimprimiendoObjetos(int capacidad, int N, int valores [], int pesos []){
    int ** matriz = new int * [N + 1] ();
    for (int i = 0; i <= N; i++)
    {
        matriz[i] = new int [capacidad + 1] ();
    }
    for (int i = 0; i <= capacidad; i++)
    {
        matriz[0][i] = 0;
    }
    for (int objetoHasta = 1; objetoHasta <= N; objetoHasta++)
    {
        for (int capacidadHasta = 0; capacidadHasta <= capacidad; capacidadHasta++)
        {
            //si no entra el objeto
            if(pesos[objetoHasta-1] > capacidadHasta){
                matriz[objetoHasta][capacidadHasta] = matriz[objetoHasta - 1] [capacidadHasta];
            } else {
                // en el caso que pueda usar el objeto
                int v_noUsarObjeto = matriz[objetoHasta - 1][capacidadHasta];
                int v_usarObjeto = valores[objetoHasta - 1] + matriz[objetoHasta][capacidadHasta - pesos[objetoHasta - 1]];

                matriz[objetoHasta][capacidadHasta] = max(v_noUsarObjeto, v_usarObjeto);
            }
        }  
    }
    cout << "El valor de la mochila 0-INF es : " << matriz[N][capacidad] << endl;
    //vamos a imprimir los objetos que colocamos en la mochila
    int capacidadIndex = capacidad;
    int objetoIndex = N;
    while (objetoIndex > 0)
    {
        //si use el objeto
        if(matriz[objetoIndex][capacidadIndex] != matriz[objetoIndex - 1][capacidadIndex]){
            cout << "Use el objeto " << objetoIndex << " con peso " << pesos[objetoIndex - 1] << " y valor " << valores[objetoIndex - 1] << endl;
            capacidadIndex-= pesos[objetoIndex - 1];
        } else {
            objetoIndex--;
        }
        
    }
    
}


int main (){
    int cantidadObjetos = 4;
    int valores [] = {8, 25, 20, 10};
    int pesos [] = {4, 8, 3, 5};
    int capacidad = 13;

    cout << "El valor de la mochila 0-1 es: " << mochila01(capacidad, cantidadObjetos, valores, pesos) << endl;

    cout << "El valor de la mochila 0-INF es: " << mochila0INF(capacidad, cantidadObjetos, valores, pesos) << endl;
    cout << endl;
    mochila01imprimiendoObjetos(capacidad, cantidadObjetos, valores, pesos);
    cout << endl;
    mochila0INFimprimiendoObjetos(capacidad, cantidadObjetos, valores, pesos);

    return 0;
}