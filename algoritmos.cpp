#include "algoritmos.h"
#include "grafo.h"

void Algoritmos::executarDFS(Grafo g, int s){
    std::vector<int> d(g.nVertices, infinity);
    std::vector<int> cor(10, BRANCO);
    std::vector<int> pai(10, -1);


    for (int u = 0; u < g.nVertices; u++) {
        cor[u] = BRANCO;
        pai[u] = -1;
    }

    int timestamp = 0;

    cout << s << " - ";
    DFS_aux(g, s, d, cor, pai, timestamp);

    /* for (int v = 0; v < g.nVertices; v++) {
        printf("%d\n", d[v]);
    } */
}

void DFS_aux(Grafo g, int u, vector<int> &d, vector<int> &cor, vector<int> &pai, int &timestamp){
    cor[u] = CINZA;
    timestamp++;

    d[u] = timestamp;
    int *adj = g.matriz[u];

    cout << "- " << u;

    int v;
    for (v = 0; v < g.nVertices; v++) {
        if (adj[v] == infinity)
            continue;

        if (cor[v] == BRANCO) {
            pai[v] = u;
            DFS_aux(g, v, d, cor, pai, timestamp);
        }
    }

    cor[u] = PRETO;
    timestamp++;
}