#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//EJERCICIO 1
/*
    1) Diferencia entre lo que representa el factor de carga en una tabla de hash abierta y cerrada.
    2) Porque el orden en caso promedio de insertar en un heap no es el mismo que el de eliminar el tope del mismo?
    3) Defina que es un AVL.
    4) En que caso utilizaria la representacion de matriz de adyacencia y en que caso utilizaria la representacion 
    de listas de adyacencia en un grafo.
*/



//EJERCICIO 2
/*
    Explique como podria resolver el problema de la mochila de tres maneras distintas con tactica de Greedy y muetre un
    contraejemplo donde no da una solucion optima para una de ellas.
*/



//EJERCICIO 3
/*
    Tablero de ajedrez 8x8.
    Casillas por las cuales no podemos pasar.
    Casillas por las cuales debemos pasar.
    La entrada sera un objeto de tipo Pos que indica la posicion inicial del caballo, un Set<Pos> indicando las posiciones por
    las que debemos pasar y otro Set<Pos> que indica las posiciones por las cuales no podemos pasar.
    
    Implementar un algoritmo que indique un camino a seguir con la menor cantidad de pasos posibles que debe dar un caballo.

    Lista<Pos> * caminoMasCorto(Pos ini, Set<Pos> * debemos, Set<Pos> * noPodemos);

    struct Pos{
        int x;
        int y;
    };

*/