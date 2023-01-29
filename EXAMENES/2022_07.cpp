#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/*
    Cantidad D de dinero
    //N cantidad de objetos
    int preferencias [N] = {5, 2, 12, 3, 8, 8, ...}
    int costos [N] = {100, 500, 800, 200, 350, ...}

    Mochila 0-1 y Mochila 0-INF
*/

int max (int a, int b){
    return a > b ? a : b;
}

//Incluyo la variable global dentro de la firma del metodo en este caso
void jugueteria(int N, int * preferencias, int * costos, int D, bool puedoTomarSoloUno){
    int ** matriz = new int * [N + 1] ();
    for (int i = 0; i <= N; i++) matriz[i] = new int [D + 1] ();
    for (int i = 0; i <= D; i++) matriz[0][i] = 0;

    for (int objeto_hasta = 1; objeto_hasta <= N; objeto_hasta++){
        for(int D_hasta = 0; D_hasta <= D; D_hasta++){
            //Si el juguete es mas caro de lo que se puede meter
            if(costos[objeto_hasta - 1] > D_hasta){
                matriz[objeto_hasta][D_hasta] = matriz[objeto_hasta - 1][D_hasta];
            } else {
                // En el caso de que el juguete este dentro del presupuesto
                int v_no_comprar = matriz[objeto_hasta - 1] [D_hasta];
                int v_comprar;
                if (puedoTomarSoloUno){
                    v_comprar = preferencias[objeto_hasta - 1] + matriz[objeto_hasta - 1] [D_hasta - preferencias[objeto_hasta - 1]];
                } else {
                    v_comprar = preferencias[objeto_hasta - 1] + matriz[objeto_hasta] [D_hasta - preferencias[objeto_hasta - 1]];
                }            
                matriz[objeto_hasta][D_hasta] = max(v_no_comprar, v_comprar);
            }
        }                 
    }
    cout << "El valor de la compra es: " << matriz[N][D] << endl;
    //Imprimo los objetos que compré
    int D_index = D;
    int objetoIndex = N;
    while(objetoIndex > 0){
        //Si use el objeto
        if(matriz[objetoIndex][D_index] != matriz[objetoIndex - 1][D_index]){
            cout << "Use el objeto " << objetoIndex << " de preferencia " << preferencias[objetoIndex - 1] << " y costo " << costos[objetoIndex - 1] << endl;
            D_index-= costos[objetoIndex - 1];
        } else {
            if(!puedoTomarSoloUno) objetoIndex--;
        }
        if(puedoTomarSoloUno) objetoIndex--;
    }    
}







int main (){

    int preferencias [6] = {5, 2, 12, 3, 8, 8};
    int costos [6] = {100, 500, 800, 200, 350, 400};
    int N = 6;
    int D = 1000;

    jugueteria(N, preferencias, costos, D, true); 



    return 0;
}