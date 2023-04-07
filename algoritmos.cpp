#include "algoritmos.h"
#include "grafo.h"

void Algoritmos::executarDFS(Grafo g, int s){
    vector<int> cor(g.nVertices, BRANCO);
    vector<int> visitados;
    for (int u = 0; u < g.nVertices; u++) {
        cor[u] = BRANCO;
    }

    DFS_visit(g, s, visitados, cor);

    for(int i = 0; i < visitados.size(); i++){
        cout << visitados[i];
        if(i != visitados.size() - 1)
            cout << " - ";
    }

    cout << '\n';
}

void DFS_visit(Grafo g, int u, vector<int> &visitados, vector<int> &cor){
    cor[u] = CINZA;
    visitados.push_back(u);

    int *adj = g.matriz[u];
    for (int v = 0; v < g.nVertices; v++) {
        if (adj[v] == infinity)
            continue;
            
        if (cor[v] == BRANCO) {
            DFS_visit(g, v, visitados, cor);
        }
    }

    cor[u] = PRETO;
}

void Algoritmos::executarBFS(Grafo g, int s){
    vector<int> cor(g.nVertices, BRANCO);
    queue<int> fila; int u;

    cor[s] = CINZA;

    fila.push(s);

    while(!fila.empty()){
        u = fila.front();
        cout << u;
        int *adj = g.matriz[u];

        for(int v = 0; v < g.nVertices; v++){
            if(adj[v] == infinity) 
                continue;

            if(cor[v] == BRANCO){
                cor[v] = CINZA;
                fila.push(v);
            }
        }

        fila.pop();
        cor[u] = PRETO;
    }
}