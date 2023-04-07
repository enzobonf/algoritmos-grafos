#include <iostream>
#include "grafo.h"

using namespace std;

#ifndef ALGORITMOS_H
#define ALGORITMOS_H


class Algoritmos {
    public:
        static void executarDFS(Grafo g, int s);        
};

void DFS_visit(Grafo g, int u, vector<int> &visitados, vector<int> &cor);

#endif