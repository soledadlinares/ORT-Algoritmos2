#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

template <class T>
struct NodoLista{
    T dato;
    NodoLista * sig;
    NodoLista() : dato(NULL), sig(NULL) {};
};

struct Arista{
    int origen;
    int destino;
    int peso;
    Arista() : origen(0), destino(0), peso(0) {};
};

typedef NodoLista<Arista> * ListaAristas;

template <class T>
class Cola{
    private:
        unsigned int cantidad_elementos;
        NodoLista<T> * principio;
        NodoLista<T> * final;

    public:
        Cola(){
            this->cantidad_elementos = 0;
            this->principio = NULL;
            this->final = NULL;
        }

        ~Cola(){
            while(this->principio != NULL){
                NodoLista<T> * borrar = this->desencolar();
                delete borrar;
                borrar = NULL;
            }
        }

        void encolar(T elemento){
            NodoLista<T> * nuevo = new NodoLista();
            nuevo->dato = elemento;
            nuevo->sig = this->final;
            this->final = nuevo;
            this->cantidad_elementos++;
        }

        bool esVacia(){
            return this->cantidad_elementos == 0;
        }

        T desencolar(){
            NodoLista<T> * desencolar = this->principio;
            this->principio = desencolar->sig;
            this->cantidad_elementos--;
            return desencolar;
        }


};

class Grafo{
    private:
        int ** matriz;
        int V;
        int A;
        int esDirigido;
        int esPonderado;
    public:
        Grafo(int cant_vertices, bool es_dirigido, bool es_ponderado){
            this->V = cant_vertices;
            this->A = 0;
            this->esDirigido = es_dirigido;
            this->esPonderado = es_ponderado;
            this->matriz = new int * [V + 1]();
            for(int i = 1; i <= V; i++){
                this->matriz[i] = new int [V + 1]();
                for (int j = 1; j <= V; j++){
                    this->matriz[i][j] = INT_MAX;
                }
            }
        }

        void agregarArista(int origen, int destino, int peso){
            this->matriz[origen][destino] = esPonderado ? peso : 1;
            if (!esDirigido) this->matriz[destino][origen] = esPonderado ? peso : 1;
            this->A++;
        }

        ListaAristas adyacentesA(int vertice){
            int inf = INT_MAX;
            ListaAristas retorno = NULL;
            for(int i = 1; i <= this->V; i++){
                if(this->matriz[vertice][i] != INT_MAX){
                    Arista * aux = new Arista();
                    aux->origen = vertice;
                    aux->destino = i;
                    aux->peso = matriz[vertice][i];
                    retorno = new NodoLista<Arista>();
                    retorno->dato = aux;
                    retorno->sig = retorno;
                }
            }
            return retorno;
        }
};

int * initGradoEntrada(Grafo * g, int vertice){
    int retorno = new int [vertice + 1]();
    for (int i = 1; i <= vertice; i++){
        ListaAristas adyacentes = g->adyacentesA(i);
        while(adyacentes != NULL){
            Arista a = adyacentes->dato;
            retorno[a.destino]++;
            adyacentes = adyacentes->sig;
        }
    }
    return retorno;
}

bool * initVisitados (int vertice){
    bool retorno = new bool [vertice + 1];
    for(int i = 1; i <= vertice; i++){
        retorno[i] = false;
    }
    return retorno;
}


void ordenTopologico (Grafo * g, int origen){
    int * gradoEntrada = initGradoEntrada(g, origen);
    Cola cola = new Cola<int>();
    int vertice = 0;
    int contador = 0;
    for(int i = 1; i <= V ; i++){ //tengo que ver de donde saco ese V
        if(gradoEntrada[i] == 0) cola->encolar(i);
    }
    while (!cola.esVacia()){
        vertice = cola->desencolar();
        contador++;
        cout << vertice << endl;
        ListaAristas adyacentesAV = g->adyacentesA(vertice);
        while(adyacentesAV != NULL){
            int v_aux = adyacentesAV->dato.destino;
            gradoEntrada[v_aux]--;
            if(gradoEntrada[v_aux] == 0){
                cola->encolar(v_aux);
                adyacentesAV = adyacentesAV->sig;
            }
        }
    }
    if (contador < g->V) cout << "Hay ciclo" << endl;
}



int main (){

    Grafo *gDirNoPon = new Grafo(4, true, false);

    gDirNoPon->aniadirArista(1, 3);
    gDirNoPon->aniadirArista(3, 4);
    gDirNoPon->aniadirArista(2, 4);
    gDirNoPon->aniadirArista(2, 3);
    gDirNoPon->aniadirArista(1, 2);

    ordenacionTopologica(gDirNoPon, 4);

    return 0;
}