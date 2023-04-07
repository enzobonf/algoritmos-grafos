#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "arquivo.h"
#include "algoritmos.h"

using namespace std;

int main(){

    Arquivo *arq = new Arquivo("grafo3.txt");
    Grafo grafo = arq->lerGrafo();
    grafo.mostrar();

    Algoritmos::executarDFS(grafo, 3);
    Algoritmos::executarBFS(grafo, 3);
    Algoritmos::executarDijkstra(grafo, 0);

    return 0;
}
