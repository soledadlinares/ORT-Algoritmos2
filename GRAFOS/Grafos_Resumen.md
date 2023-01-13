# Grafos
## ¿Para qué sirve cada algoritmo de los vistos en clase?
### Órden topológico

Es sólo aplicable a grafos dirigidos.  
Sirve para detectar la **existencia de ciclos**.

### Dijkstra

No acepta aristas negativas.  
Nos permite saber el **costo y el camino a todo vértice desde un origen dado**.

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (A. log V) |
| Matriz de adyacencia  | O (V^2) |

### Camino más corto con ponderación negativa

Permite saber el **costo a todo par de vértices desde un origen dado**.

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (A. V) |
| Matriz de adyacencia  | O (V^2) |

### Floyd

Nos permite saber **camino mas corto entre TODO par de vértices**.

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (V^3) |
| Matriz de adyacencia  | O (V^3) |


### Warshall

Tiene varios usos:

- Encontrar ciclos en un grafo dirigido.
- Encontrar matriz de clausura transitiva para **grafo no dirigido** (cuando está completa de 1s quiere decir que es un **grafo conexo**).
- Encontrar matriz de clausura transitiva para **grafo dirigido** (cuando está completa de 1s es **fuertemente conexo**, si tiene algún 0 **puede ser debilmente conexo o no conexo**).  En este caso se puede saber si es debilmente conexo forzando el grafo a ser no dirigido.


| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (V^3) |
| Matriz de adyacencia  | O (V^3) |

### Prim

Para grafos no dirigidos, ponderados y conexos.  
Sirve para obtener el **arbol de cubrimiento mínimo**: nos permite conectar todos los vértices con el menor costo posible.

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (A. log V) |
| Matriz de adyacencia  | O (V^2) |

### Kurskal

Arbol de cubrimiento mínimo.

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (A. log V) |
| Matriz de adyacencia  | O (A. log V) |

### BFS Amplitud

Recorre el grafo desde un origen dado.  
Permite saber si dos vértices están conectados.  
Permite obtener el camino mas corto en grafos no ponderados.  
Encontrar nodos a una distancia dada.

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (A + V) |
| Matriz de adyacencia  | O (V^2) |

### DFS Profundidad

Permite saber si dos vértices están conectados.  
Detectar ciclos.  
Detectar componentes fuertemente conexas en un grafo dirigido.  
Puntos de articulación (si un punto es de articulación, el grafo queda dividido en dos por ese punto).

| Estructura  | Órden |
| ------------- | ------------- |
| Lista de adyacencia  | O (A + V) |
| Matriz de adyacencia  | O (A + V) |