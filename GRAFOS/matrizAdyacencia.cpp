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
                    this->matriz[i][j] = INF;
                }
            }
        }

        void agregarArista(int origen, int destino, int peso){
            this->matriz[origen][destino] = esPonderado ? peso : 1;
            if (!esDirigido) this->matriz[destino][origen] = esPonderado ? peso : 1;
            this->A++;
        }

        ListaAristas adyacentesA(int vertice){
            int inf = INF;
            ListaAristas * retorno = NULL;
            for(int i = 1; i <= this->V; i++){
                if(this->matriz[vertice][i] != INF){
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