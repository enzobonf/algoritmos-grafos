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

        if(!fila.empty()) printf(" - ");
    }

    cout <<  '\n';
}

void Algoritmos::executarDijkstra(Grafo g, int s){

    if(g.temPesoNegativo){
        cout << "Nao e possivel aplicar o algoritmo de Dijkstra - grafo possui arestas de peso negativo";
        return;
    }

    vector<int> d(g.nVertices, infinity);
    vector<int> pai(g.nVertices, -1);
    vector<int> cor(g.nVertices, BRANCO);
    priority_queue<pair<int, int>> pq;

    d[s] = 0;
    cor[s] = CINZA;
    pq.push({d[s], s});

    dijkstraAux(g, pq, d, pai, cor);

    printf("origem: %d\n", s);
    for(int u = 0; u < g.nVertices; u++){
        printf("destino: %2d dist.: ", u, d[u]);

        if(d[u] != infinity) printf("%2d", d[u]);
        else cout << "--";

        cout << " caminho: ";

        imprimirCaminho(g, s, u, d, pai);
        printf("\n");
    }

}

void dijkstraAux(Grafo g, priority_queue<pair<int, int>> &pq, vector<int> &d, vector<int> &pai, vector<int> &cor){
    while(!pq.empty()){
        auto pair = pq.top();
        int u = pair.second;
        pq.pop();
        cor[u] = CINZA;

        int *adj = g.matriz[u];
        for(int v = 0; v < g.nVertices; v++){
            if(adj[v] == infinity || u == v) continue;

            int dist_aux = d[u] + adj[v];
            if(dist_aux < d[v]){
                d[v] = dist_aux;
                pai[v] = u;
                pq.push({d[v], v});
            } // relaxação
        }
    }
}

void imprimirCaminho(Grafo g, int s, int v, vector<int> d, vector<int> pai){
    if(v == s){
        cout << s;
    }
    else if(pai[v] == -1){
        cout << "--";
    }
    else{
        imprimirCaminho(g, s, pai[v], d, pai);
        cout << " - " << v;
    }
}