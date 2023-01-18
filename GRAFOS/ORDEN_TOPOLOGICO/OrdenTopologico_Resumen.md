# Orden topológico

Aplicable a grafos **DIRIGIDOS y ACICLICOS**.  

Sirve para detectar ciclos, si no se puede hacer la ordenación topológica es que el grafo tiene al menos un ciclo.

## La idea del algoritmo

- Calcular los índices de entrada de los vértices del grafo.
- Para cada vértice con grado de entrada 0 no visitado:  
1) Opero sobre el vértice.  
2) Lo marco como visitado.  
3) Para cada adyacente al vértice reduzco su índice de entrada en 1.

## Que necesito para implementar el algoritmo

En primer lugar necesito tener el grafo implementado con la función "adyacentesA" un vértice dado.  

También necesito una estructura auxiliar del TAD COLA (FIFO) con las operaciones encolar y desencolar.