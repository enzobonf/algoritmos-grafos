#include "algoritmos.h"
#include "grafo.h"

//Pre-condicao: Grafo existente, vertice inicial existente
//Pos-condicao: imprime a ordem de visitacao dos vertices.
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

//Pre-condicao: Grafo existente, vetores validos, indice do estado atual valido
//Pos-condicao: visita no NO do grafo eh realizado
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

//Pre-condicao: Grafo existente, indice inicial existente
//Pos-condicao: imprime a ordem de visitacao dos vertices
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

//Pre-condicao: Grafo existente e origem existente
//Pos-condicao: imprime vertice de origem e vertice de destino com a respectiva distancia e caminho
void Algoritmos::executarDijkstra(Grafo g, int s){
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

//Pre-condicao: Grafo existente, vetores validos, indice do estado atual valido
//Pos-condicao: visita vertice do grafo eh realizado
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

//Pre-condicao: indices e vetor validos
//Pos-condicao: impressao do caminho da origem ate o vertice passado
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

//Pre-condicao: Grafo existente estado inicial existente
//Pos-condicao: Menor caminho eh entre a origem e demais caminhos eh calculado e impresso
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

//Pre-condicao: Grafo existente e vetores validos
//Pos-condicao: atualiza o vetor d com as distâncias mínimas entre o vértice inicial e os demais vértices do grafo
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

//Pre-condicao: Grafo existente
//Pos-condicao: Menor caminho entre todos os pares de vertices eh calculado e impresso na tela
void Algoritmos::executarFloydWarshall(Grafo g){

    vector<int> d(g.nVertices, infinity);
    vector<int> pai(g.nVertices, -1);
    vector<int> cor(g.nVertices, BRANCO);
    d[0] = 0;
    cor[0] = CINZA;

    bool temCicloNegativo = !bellmanFordAux(g, d, pai, cor);

    if(temCicloNegativo){
        cout << "Nao e possivel aplicar o algoritmo de Floyd-Warshall - ha um ciclo negativo no grafo\n";
        return;
    }

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

//Pre-condicao: Matriz contendo dados de um Grafo
//Pos-condicao: Retorna a matriz de distâncias mínimas e a matriz de predecessores
// que são atualizadas de acordo com o resultado do algoritmo de Floyd-Warshall
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

//Pre-condicao: Grafo existente
//Pos-condicao: Arvore geradora eh calculada e impressa
void Algoritmos::executarKruskal(Grafo g){
    auto resultado = kruskalAux(g);
    auto arestas = resultado.arestas;
    printf("peso total: %d\n", resultado.custo);
    printf("arestas: ");
    for(int i = 0; i < arestas.size(); i++){
        printf("(%d, %d)", arestas[i].origem, arestas[i].dest);
        if(i != arestas.size() - 1) printf(", ");
    }

    g.desenhar(arestas, "kruskal.png");
}

//Pre-condicao: Grafo existente
//Pos-condicao: O retorno contem o vetor de arestas que contem a arvore geradora minima
// junto com o custo total da arvore
ArvoreGeradora kruskalAux(Grafo g){

    vector<Aresta> arestas;
    for(int i = 0; i < g.nVertices; i++){
        for(int j = 0; j < g.nVertices; j++){
            if(i != j && g.matriz[i][j] != infinity){
                arestas.push_back(Aresta(i, j, g.matriz[i][j]));
            }
        }
    }

    sort(arestas.begin(), arestas.end());
    vector<int> pai(g.nVertices, -1);
    vector<Aresta> resultado;

    for(int i = 0; i < g.nVertices; i++){
        pai[i] = i;
    }
    
    int custo = 0; 
    for(auto& aresta: arestas){
        if(find_set(pai, aresta.origem) != find_set(pai, aresta.dest)){
            custo += aresta.peso;
            resultado.push_back(aresta);
            union_sets(pai, aresta.origem, aresta.dest);
        }
    }

    return {resultado, custo};
}

//Pre-condicao: vetor para pai existente, vertice existente
//Pos-condicao: O retorno eh o pai do vertice
int find_set(vector<int> &pai, int v){
    if(v == pai[v]) return v;
    return find_set(pai, pai[v]);
}

//Pre-condicao: Vetor para pai existente, "a" e "b" sao vertices existentes no grafo
//Pos-condicao: Atualiza o Vetor de Pai
void union_sets(vector<int> &pai, int a, int b){
    pai[a] = pai[b];
}

//Calcular arvore geradora mınima usando o algoritmo Kruskal
//Pre-condicao: Grafo existente
//Pos-condicao: Arvore geradora eh calculada e impressa
//Entrada: objeto para Grafo g
//Retorno: Nenhum
void Algoritmos::executarPrim(Grafo g, int s){
    auto resultado = primAux(g, s);
    auto arestas = resultado.arestas;
    printf("vertice inicial: %d\n", s);
    printf("peso total: %d\n", resultado.custo);
    printf("arestas: ");
    for(int i = 0; i < arestas.size(); i++){
        printf("(%d, %d)", arestas[i].origem, arestas[i].dest);
        if(i != arestas.size() - 1) printf(", ");
    }

    g.desenhar(arestas, "prim.png");
}

//Pre-condicao: grafo existir e estado inicial ser um vertice existente no grafo
//Pos-condicao: calcula e retorna vetor de arestas resultado e o custo total da árvore geradora mínima.
ArvoreGeradora primAux(Grafo g, int s){
    
    vector<Aresta> resultado; int custo = 0;
    vector<int> d(g.nVertices, infinity);
    vector<int> pai(g.nVertices, -1);
    vector<int> cor(g.nVertices, BRANCO);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //cor[s] = CINZA;
    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto pair = pq.top();
        int u = pair.second;
        pq.pop();

        if(cor[u] != BRANCO) continue;
        cor[u] = CINZA;

        auto adj = g.matriz[u];
        for(int v = 0; v < g.nVertices; v++){
            if(adj[v] == infinity || u == v) continue;

            if(cor[v] == BRANCO && adj[v] < d[v]){  
                pai[v] = u;
                d[v] = adj[v];
                pq.push({adj[v], v});
            }
        }
    }

    for(int i = 0; i < g.nVertices; i++){
        if(pai[i] != -1 && d[i] != infinity){
            custo += d[i];
            resultado.push_back(Aresta(pai[i], i, d[i]));
        }
    }

    return {resultado, custo};

}