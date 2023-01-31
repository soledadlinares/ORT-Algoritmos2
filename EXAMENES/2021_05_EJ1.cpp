#include <climits>
#include <string>
#include <iostream>
using namespace std;

template<class T>
struct NodoLista{
    T dato;
    NodoLista * sig;
};

struct Arista{
    int origen;
    int destino;
    int peso;
};

typedef NodoLista<Arista> * ListaAristas;

bool colorear(int origen, Grafo * g, int * colores, int colorAPintar){
    colores[origen] = colorAPintar;
    //recorro los adyacentes para tratar de pintar de forma recursiva (DFS profundidad)
    ListaAristas arista = g->adyacentesA(origen);
    while(aristas != NULL){
        int adyacente = aristas->dato.destino;
        if(colores[adyacente] == colorAPintar){ //si hay un adyacente pintado del mismo color entonces no es bipartita
            return false; 
        } else if (colores[adyacente] == 0){
            int colorSiguiente = colorAPintar == 1 ? 2 : 1;
            bool pudePintar = colorear(adyacente, g, colores, colorSiguiente);
            if(!pudePintar) return false;
        }
        aristas = aristas->sig;
    }
    //pude pintar todos (los conexos a mi)
    return true;
}


bool esBipartita(Grafo * g, int V){
    //0 despintado
    //1 color 1
    //2 color 2
    int * colores = new int [V + 1]();

    //recorro los vertices
    for(int i = 1; i <= V; i++){
        if(colores[i] == 0){
            //si no puedo colorear entonces no es bipartita
            if(!colorear(i, g, colores, 1)) return false;
        }

    }
    return true;
}






int main (){
    return 0;
}