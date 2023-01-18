#ifndef COLA
#define COLA
#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//IMPLEMENTACION DE COLA FIFO - first in - first out

template <class T>

struct NodoLista{
    T dato;
    NodoLista * sig;
    NodoLista() : dato(NULL), sig(NULL) {};
};

struct ImplementacionCola{
    unsigned int cantidad_elementos;
    NodoLista * principio;
    NodoLista * final;
};

typedef ImplementacionCola * Cola;

class Cola{
    private:
        Cola cola;

    public:
        Cola(){
            this->cola.cantidad_elementos = 0;
            this->cola.principio = NULL;
            this->cola.final = NULL;
        }

        ~Cola(){
            while(this->cola.principio != NULL){
                NodoLista * borrar = this->desencolar();
                delete borrar;
                borrar = NULL;
            }
        }

        void encolar(T elemento){
            NodoLista * nuevo = new NodoLista<T>();
            nuevo->dato = elemento;
            nuevo->sig = this->cola.final;
            this->cola.final = nuevo;
            this->cola.cantidad_elementos++;
        }

        bool esVacia(){
            return this->cola.cantidad_elementos == 0;
        }

        T desencolar(){
            NodoLista * desencolar = this->cola.principio;
            this->cola.principio = desencolar->sig;
            this->cola.cantidad_elementos--;
            return desencolar;
        }


};
