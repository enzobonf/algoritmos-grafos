#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "grafo.h"

using namespace std;

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

class Algoritmos {
    public:
        static void executarDFS(Grafo g, int s);        
        static void executarBFS(Grafo g, int s);        
        static void executarDijkstra(Grafo g, int s);        
};

void DFS_visit(Grafo g, int u, vector<int> &visitados, vector<int> &cor);
void dijkstraAux(Grafo g, priority_queue<pair<int, int>> &pq, vector<int> &d, vector<int> &pai, vector<int> &cor);
void imprimirCaminho(Grafo g, int s, int v, vector<int> d, vector<int> pai);

#endif