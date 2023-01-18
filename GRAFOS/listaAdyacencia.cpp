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
        ListaAristas * listaAdyacencia;
        int V;
        int A;
        bool esDirigido;
        bool esPonderado;
    
    public:
        Grafo(int cant_V, bool es_dirigido, bool es_ponderado){
            this->V = cant_V;
            this->A = 0;
            this->esDirigido = es_dirigido;
            this->esPonderado = es_ponderado;
            listaAdyacencia = new ListaAristas [V + 1];
            for (int i = 1; i <= V; i++){
                listaAdyacencia[i] = NULL;
            }
        }

        void agregarArista(int origen, int destino, int peso){
            int pesoArista = this->esPonderado ? peso : 1;
            Arista * nueva = new Arista ();
            nueva->origen = origen;
            nueva->destino = destino;
            nueva->peso = pesoArista;

            NodoLista * nodo = new NodoLista<Arista>();
            nodo->dato = nueva;
            nodo->sig = listaAdyacencia[origen];
            listaAdyacencia[origen] = nueva;
            this->A++;

            if(!esDirigido){
                Arista * simetrica = new Arista();
                simetrica->origen = destino;
                simetrica->destino = origen;
                simetrica->peso = pesoArista;

                NodoLista * simetrico = new NodoLista<Arista>();
                simetrico->dato = simetrica;
                simetrico->sig = listaAdyacencia[destino];
                listaAdyacencia[destino] = simetrico;
            }
        }

        ListaAristas adyacentesA(int vertice){
            ListaAristas retorno = NULL;
            ListaAristas aux = listaAdyacencia[vertice];
            while(aux != NULL){
                Arista arista_aux = aux->dato;
                retorno = new NodoLista<Arista>();
                retorno->dato = arista_aux;
                retorno->sig = retorno;
            }
            return retorno;
        }
};