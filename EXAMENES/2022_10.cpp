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