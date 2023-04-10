#include "algoritmos.h"
#include "grafo.h"

//Executa o algoritmo Busca em Profundidade (Depth-First-Search) - DFS
//Pre-condicao: Grafo existente, vertice inicial existente
//Pos-condicao: imprime a ordem de visitacao dos vertices.
//Entrada: objeto Grafo e vértice inicial
//Retorno: Nenhum
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

//Realiza a visita do vertice no grafo, identificando seu estado(BRANCO, CINZA, PRETO)
// e alterando o mesmo caso necessario
//Pre-condicao: Grafo existente, vetores validos, indice do estado atual valido
//Pos-condicao: visita no NO do grafo eh realizado
//Entrada: objeto Grafo e índice do vértice atual
// vetor de inteiros que representa a cor de cada vértice do grafo, inicializado com BRANCO para cada vértice,
// vetor vazio que será usado para armazenar os vértices visitados durante a busca em profundidade.
//Retorno: Nenhum
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

//Executa o algoritmo Busca em Largura (Breadth-First-Search) - BFS
//Pre-condicao: Grafo existente, indice inicial existente
//Pos-condicao: imprime a ordem de visitacao dos vertices
//Entrada: objeto Grafo e vértice inicial
//Retorno: Nenhum
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

//Executa o Algoritmo de Dijkstra
//Pre-condicao: Grafo existente e origem existente
//Pos-condicao: imprime vertice de origem e vertice de destino com a respectiva distancia e caminho
//Entrada: objeto Grafo e vertice inicial
//Retorno: Nenhum
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

//Realiza a visita do vertice no grafo e analiza o mesmo de forma a auxiliar o algoritmo de dijkstra
//Pre-condicao: Grafo existente, vetores validos, indice do estado atual valido
//Pos-condicao: visita vertice do grafo eh realizado
//Entrada: objeto Grafo, fila de prioridade dos vertices, 
// vetor de inteiros que representa a cor de cada vértice do grafo, inicializado com BRANCO para cada vértice,
// vetor vazio que será usado para armazenar os vértices visitados durante a busca em profundidade,
// vetor com as distancias minimas ate a origem
//Retorno: Nenhum
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

//Funcao para auxiliar dijkstra, imprime o caminho da origem ate o devido vertice
//Pre-condicao: indices e vetor validos
//Pos-condicao: impressao do caminho da origem ate o vertice passado
//Entrada: vertice inicial, vertice atual, vetor com o caminho
//Retorno: Nenhum
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

//Dado um vertice de origem, calcular os menores caminhos para os demais vertices usando o algoritmo de Bellman-Ford
//Pre-condicao: Grafo existente estado inicial existente
//Pos-condicao: 
//Entrada:
//Retorno: Nenhum
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

//
//Pre-condicao: 
//Pos-condicao:
//Entrada:
//Retorno:
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

//Calcula o menor caminho entre todos os pares de vertices usando o algoritmo de Floyd Warshall
//Pre-condicao: Grafo existente
//Pos-condicao: Menor caminho entre todos os pares de vertices eh calculado e impresso na tela
//Entrada: objeto para Grafo g
//Retorno: Nenhum
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

//
//Pre-condicao: Grafo existente
//Pos-condicao:
//Entrada:
//Retorno:
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

//Executa o algoritmo
//Pre-condicao: Grafo existente
//Pos-condicao:
//Entrada:
//Retorno: Nenhum
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