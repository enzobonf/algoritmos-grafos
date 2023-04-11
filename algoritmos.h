#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include "grafo.h"

using namespace std;

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

struct ResultadoFloydWarshall {
    Matriz d;
    Matriz pai;
};

struct ArvoreGeradora {
    vector<Aresta> arestas;
    int custo;
};

class Algoritmos {
    public:
        static void executarDFS(Grafo g, int s);        
        static void executarBFS(Grafo g, int s);        
        static void executarDijkstra(Grafo g, int s);        
        static void executarBellmanFord(Grafo g, int s);        
        static void executarFloydWarshall(Grafo g);        
        static void executarKruskal(Grafo g);        
        static void executarPrim(Grafo g, int s);        
};

void DFS_visit(Grafo g, int u, vector<int> &visitados, vector<int> &cor);
void dijkstraAux(Grafo g, priority_queue<pair<int, int>> &pq, vector<int> &d, vector<int> &pai, vector<int> &cor);
bool bellmanFordAux(Grafo g, vector<int> &d, vector<int> &pai, vector<int> &cor);
void imprimirCaminho(int s, int v, vector<int> pai);
ResultadoFloydWarshall floydWarshallAux(Matriz matriz);
ArvoreGeradora kruskalAux(Grafo g);
ArvoreGeradora primAux(Grafo g, int s);

int find_set(vector<int> &pai, int v);
void union_sets(vector<int> &pai, int a, int b);

#endif