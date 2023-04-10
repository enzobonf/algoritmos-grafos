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

    auto adj = g.matriz[u];
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
        auto adj = g.matriz[u];

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
        cout << "Nao e possivel aplicar o algoritmo de Dijkstra - grafo possui arestas de peso negativo\n";
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

        imprimirCaminho(s, u, pai);
        printf("\n");
    }

}

void dijkstraAux(Grafo g, priority_queue<pair<int, int>> &pq, vector<int> &d, vector<int> &pai, vector<int> &cor){
    while(!pq.empty()){
        auto pair = pq.top();
        int u = pair.second;
        pq.pop();
        cor[u] = CINZA;

        auto adj = g.matriz[u];
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

void imprimirCaminho(int s, int v, vector<int> pai){
    if(v == s){
        cout << s;
    }
    else if(pai[v] == -1){
        cout << "--";
    }
    else{
        imprimirCaminho(s, pai[v], pai);
        cout << " - " << v;
    }
}

void Algoritmos::executarBellmanFord(Grafo g, int s){
    vector<int> d(g.nVertices, infinity);
    vector<int> pai(g.nVertices, -1);
    vector<int> cor(g.nVertices, BRANCO);

    d[s] = 0;
    cor[s] = CINZA;

    if(bellmanFordAux(g, d, pai, cor)){
        printf("origem: %d\n", s);
        for(int u = 0; u < g.nVertices; u++){
            printf("destino: %2d dist.: ", u, d[u]);

            if(d[u] != infinity) printf("%2d", d[u]);
            else cout << "--";

            cout << " caminho: ";

            imprimirCaminho(s, u, pai);
            printf("\n");
        }
    }
    else{
        cout << "Nao e possivel aplicar o algoritmo de Bellman Ford - ha um ciclo negativo no grafo\n";
    }
}

bool bellmanFordAux(Grafo g, vector<int> &d, vector<int> &pai, vector<int> &cor){
    int i, u, v; vector<int> adj;
    for(i = 0; i < g.nVertices - 1; i++)
        for(u = 0; u < g.nVertices; u++){
            adj = g.matriz[u];

            for(v = 0; v < g.nVertices; v++){
                if(d[u] == infinity || adj[v] == infinity || u == v) continue;

                int dist_aux = d[u] + adj[v];
                if(dist_aux < d[v]){
                    d[v] = dist_aux;
                    pai[v] = u;
                } // relaxação
            }
        }

    for(u = 0; u < g.nVertices; u++){
        adj = g.matriz[u];
        for(v = 0; v < g.nVertices; v++){
            if(d[u] == infinity || adj[v] == infinity || u == v) continue;

            if(d[v] > d[u] + adj[v])
                return false; // tem ciclo negativo
        }
    }

    return true;
}

void Algoritmos::executarFloydWarshall(Grafo g){
    auto resultado = floydWarshallAux(g.matriz);
    printMatriz(resultado.d);

    for(int i = 0; i < g.nVertices; i++)
        for(int j = 0; j < g.nVertices; j++){
            printf("caminho de %d para %d: ", i, j);
            if(resultado.d[i][j] != infinity){
                imprimirCaminho(i, j, resultado.pai[i]);
            }
            else{
                cout << "--";
            }
            cout << '\n';
        }
}

ResultadoFloydWarshall floydWarshallAux(Matriz matriz){
    Matriz d = matriz;
    Matriz pai = Matriz(matriz.size(), vector<int>(matriz.size()));
    int v = d.size();

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            pai[i][j] = i == j ? -1 : i;

    for(int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++){
                if(d[i][j] > (d[i][k] + d[k][j]) && (d[k][j] != infinity && d[i][k] != infinity)){
                    d[i][j] = d[i][k] + d[k][j];
                    pai[i][j] = pai[k][j];
                }
            }
    
    return {d, pai};
}

void Algoritmos::executarKruskal(Grafo g){
    
    vector<Aresta> arestas;
    for(int i = 0; i < g.nVertices; i++){
        for(int j = 0; j < g.nVertices; j++){
            if(i != j && g.matriz[i][j] != infinity){
                arestas.push_back(Aresta(i, j, g.matriz[i][j]));
            }
        }
    }

    sort(arestas.begin(), arestas.end());

}