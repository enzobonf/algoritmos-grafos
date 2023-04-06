#include <iostream>
#include "grafo.h"

using namespace std;

#ifndef ALGORITMOS_H
#define ALGORITMOS_H


class Algoritmos {
    public:
        static void executarDFS(Grafo g, int s);
};


void DFS_aux(Grafo g, int u, vector<int> &d, vector<int> &cor, vector<int> &pai, int &timestamp);

#endif