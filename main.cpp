#include <iostream>
#include <cstdio>
#include "arquivo.h"
#include "algoritmos.h"
#include <cgraph.h>
#include "gvc.h"

using namespace std;

int main(){

    Arquivo *arq = new Arquivo("grafo2.txt");
    Grafo grafo = arq->lerGrafo();
    grafo.mostrar();

    /* Algoritmos::executarDFS(grafo, 3);
    Algoritmos::executarBFS(grafo, 3);
    Algoritmos::executarDijkstra(grafo, 0);
    Algoritmos::executarBellmanFord(grafo, 1); */

    //Algoritmos::executarFloydWarshall(grafo);

    Algoritmos::executarKruskal(grafo);

    /* GVC_t *gvc = gvContext();
     Agraph_t* g;
    gvLayout(gvc, nullptr, "dot");
    gvRenderFilename(gvc, nullptr, "png", "aaaa.png");
    
    printf("%p", gvc); */

    //Agraph_t* g = agopen("G", Agundirected, nullptr);

    return 0;
}
