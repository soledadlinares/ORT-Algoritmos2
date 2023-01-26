#include <climits>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//EJERCICIO 1
/*
    1) Diferencia entre lo que representa el factor de carga en una tabla de hash abierta y cerrada.

        El factor de carga nos indica cuan lleno está nuestro hash. 
        Se calcula N/B siendo N la cantidad de elementos que tiene el hash y B la cantidad de buckets del hash.
        Esta métrica indica lo mismo tanto en un hash abierto como cerrado, por lo tanto no existen diferencias en lo que
        representa para cada tipo de hash.

    2) Porque el orden en caso promedio de insertar en un heap no es el mismo que el de eliminar el tope del mismo?

        El orden de insertar en un heap en el caso promedio es de 1 y el de eliminar el tope es de Log N, siendo N 
        la cantidad de elementos del heap.
        La diferencia en los órdenes se debe a que para eliminar el tope, debemos temporalmente colocar el último
        elemento del heap en la posición del tope y luego relocalizarlo (operación conocida como hundir) hasta que 
        encuentre la posición correcta dentro de la estructura, y esta operación siempre se realiza, por lo tanto tiene
        el mismo órden para el caso promedio que para el peor caso.
        En cambio cuando insertamos un elemento en el heap colocamos temporalmente el elemento en el ultimo lugar libre de la
        estructura y luego lo relocalizamos (operación conocida como flotar), que en el peor de los casos tiene el mismo órden 
        que el de eliminar el tope, pero en el caso promedio ocurre que las posibilidades de tener que flotar el elemento se van
        achicando, es decir, que las posibilidades que tiene ese elemento de estar en el lugar correcto cuando lo insertamos tiende
        a una constante, lo que se puede traducir a un órden constante, es decir órden 1.

    3) Defina que es un AVL.

        Un AVL es un árbol binario donde para cada nodo del mismo se cumple que la altura del subárbol izquierdo y el subárbol
        derecho difieren en 1 como máximo, es decir es un árbol "balanceado".

        Más formalmente:
        - Un árbol vacío es un AVL.
        - Si T es un árbol no vacío y Ti y Td sus subárboles, entonces T es AVL sii Ti es AVL, Td es AVL y |H(Ti) - H(Td)| <= 1.

    4) En que caso utilizaria la representacion de matriz de adyacencia y en que caso utilizaria la representacion 
    de listas de adyacencia en un grafo.

        Utilizaría la representación de matriz de adyacencia para gráficos densos, ya que representarlos con una lista quedaría 
        de una complejidad muy elevada y si representamos de esta forma gráficos mas dispersos quedaría mucho espacio en memoria sin
        utilizar.
        En cambio para grafos mas proporcionados en cuanto a cantidad de aristas y vértices utilizaría una lista de adyacencia ya que
        es una representación bastante simple donde se puede visualizar con claridad con que nodos esta conectado un nodo en particular.

*/



//EJERCICIO 2
/*
    Explique como podria resolver el problema de la mochila de tres maneras distintas con tactica de Greedy y muetre un
    contraejemplo donde no da una solucion optima para una de ellas.
    
        El problema de la mochila consiste en colocar dentro de la mochila (que tiene una capacidad dada), objetos (que tienen un peso y un valor)
        tratando de obtener el máximo valor posible dentro de la misma.

        Para resolver el problema de la mochila con la táctica Greedy existen tres enfoques:
        - Tratar de meter en la mochila primero lo mas valioso.
        - Tratar de meter en la mochila primero lo menos pesado.
        - Tratar de meter en la mochila los objetos con el mejor ratio valor/peso.

        Por ejemplo, si tenemos una mochila con capacidad 10 y los siguientes objetos Obj(valor, peso) = {(1,1), (10, 5), (50, 9)}
        y podemos poner cantidades infinitas de cada objeto dentro de la mochila, si encaramos el problema poniendo primero los objetos menos pesados
        colocaríamos 10 objetos (1,1), obteniendo un valor total para la mochila de 10, cuando en realidad si pusieramos dos objetos (10, 5) o uno (50, 9)
        obtendríamos una mejor solución.
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

        Es un problema de optimización, porque queremos la menor cantidad de pasos necesarios
        para pasar por todas las casillas por las que debemos pasar.

*/

struct Pos{
    int x;
    int y;
    Pos() : x(0), y(0){};
};

struct Nodo{
    Pos * inicio;
    Nodo * siguiente;
}


struct Set{
    int cantidad;
    Nodo * par;
    Nodo * sig;
}



Nodo * caminoMasCorto(Pos * ini, Set debemos, Set noPodemos){
    
}

bool tengoQuePodar(int movimiento_actual, int mejor_nro_movimiento){
    return movimiento_actual > mejor_nro_movimiento;
}

bool coordenadasValidas(int fila, int columna, Set * noPodemos, int N){
    int cantidad_set = noPodemos->cantidad;
    int index = 0;
    bool esValida = true;
    while(esValida && index < cantidad_set){
        if(noPodemos->par->x == fila && noPodemos->par->y == columna) esValida = false;
        index++;
    }
    return esValida && fila < N && columna < N && fila >= 0 && columna >= 0;
}

bool paseAntes(int fila, int columna, int ** tablero){
    return tablero[fila][columna] != 0;
}

void realizarMovimiento(int fila, int columna, int movimiento, int ** tablero, Set & debemos){
    int cantidad_set = debemos->cantidad;
    for(int i = 0; i < cantidad_set; i++){
        if(fila == debemos->par->x && columna == debemos->par->y){
            debemos->cantidad--;
        }
    }
    tablero[fila][columna] = movimiento;
}

void deshacerMovimiento(int fila, int columna, int ** tablero, Set & debemos){
    int cantidad_set = debemos->cantidad;
    for(int i = 0; i < cantidad_set; i++){
        if(fila == debemos->par->x && columna == debemos->par->y){
            debemos->cantidad--;
        }
    }
    tablero[fila][columna] = 0;
}

bool esSolucion(Set * debemos){
    return debemos->cantidad == 0;
}

bool esMejorSolucion(int movimiento_actual, int mejor_nro_movimiento){
    return movimiento_actual < mejor_nro_movimiento;
}


void caminoMasCortoBT(int fila_candidata, int columna_candidata, Set & debemos, Set * noPodemos, int nro_movimiento, int N, int ** tablero, int & mejor_nro_movimiento, Nodo & resultado){

    if(!tengoQuePodar(nro_movimiento, mejor_nro_movimiento)){

        if(coordenadasValidas(fila_candidata, columna_candidata, noPodemos, N) && !paseAntes(fila_candidata, columna_candidata, tablero)){

            realizarMovimiento(fila_candidata, columna_candidata, movimiento, tablero, debemos);

            if(esSolucion(debemos) && esMejorSolucion(nro_movimiento, mejor_nro_movimiento)){

                //Recorremos el tablero y agregamos a una lista cada movimiento.

            } else {

                int d_filas [8] = {-2, -2, -1, 1, 2, 2, 1, -1};
                int d_columnas [8] = {-1, 1, 2, 2, 1, -1, -2, -2};
                for (int i = 0; i < 8; i++){
                    caminoMasCortoBT(fila_candidata + d_filas[i], columna_candidata + d_columnas[i], debemos, noPodemos, nro_movimiento + 1, N, tablero, mejor_nro_movimiento, resultado);
                }

            }

            deshacerMovimiento(fila_candidata, columna_candidata, tablero);

        }
    }
}


int main (){


    return 0;
}