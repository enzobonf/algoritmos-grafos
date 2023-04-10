#include <iostream>
#include <cstdio>
#include "arquivo.h"
#include "algoritmos.h"

using namespace std;

int main(){

    Arquivo *arq = new Arquivo("grafo3.txt");
    Grafo grafo = arq->lerGrafo();
    grafo.mostrar();
    grafo.desenhar();

    /* Algoritmos::executarDFS(grafo, 3);
    Algoritmos::executarBFS(grafo, 3);
    Algoritmos::executarDijkstra(grafo, 0);
    Algoritmos::executarBellmanFord(grafo, 1); */

    //Algoritmos::executarFloydWarshall(grafo);

    //Algoritmos::executarKruskal(grafo);

   /* Agraph_t* g = agopen("MeuGrafo", Agdirected, nullptr);
    Agnode_t* A = agnode(g, "A", 1);
    Agnode_t* B = agnode(g, "B", 1);
    Agnode_t* C = agnode(g, "C", 1);
    agedge(g, A, B, nullptr, 1);
    agedge(g, B, C, nullptr, 1);
    agedge(g, C, A, nullptr, 1);
    
    GVC_t* gvc = gvContext();
    gvLayoutJobs(gvc, g);
    gvRenderJobs(gvc, g);
    gvFreeLayout(gvc, g);
    gvFreeContext(gvc); */
    
    //printf("%p", gvc);

    //Agraph_t* g = agopen("G", Agundirected, nullptr);

    return 0;
}
