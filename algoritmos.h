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

// estrutura para receber o resultado do algoritmo Floyd Warshall
struct ResultadoFloydWarshall {
    Matriz d;
    Matriz pai;
};

struct ArvoreGeradora {
    vector<Aresta> arestas;
    int custo;
};

// classe contendo os metodos dos algoritmos em Grafo
class Algoritmos {
    public:
        //Pre-condicao: Grafo existente, vertice inicial existente
        //Pos-condicao: imprime a ordem de visitacao dos vertices.
        static void executarDFS(Grafo g, int s);

        //Pre-condicao: Grafo existente, indice inicial existente
        //Pos-condicao: imprime a ordem de visitacao dos vertices      
        static void executarBFS(Grafo g, int s);

        //Pre-condicao: Grafo existente e origem existente
        //Pos-condicao: imprime vertice de origem e vertice de destino com a respectiva distancia e caminho
        static void executarDijkstra(Grafo g, int s);

        //Pre-condicao: Grafo existente estado inicial existente
        //Pos-condicao: Menor caminho eh entre a origem e demais caminhos eh calculado e impresso
        static void executarBellmanFord(Grafo g, int s);        
        
        //Pre-condicao: Grafo existente
        //Pos-condicao: Menor caminho entre todos os pares de vertices eh calculado e impresso na tela
        static void executarFloydWarshall(Grafo g);        
        
        //Pre-condicao: Grafo existente
        //Pos-condicao: Arvore geradora eh calculada e impressa
        static void executarKruskal(Grafo g);        
        static void executarPrim(Grafo g, int s);        
};

// metodos auxiliares

//Pre-condicao: Grafo existente, vetores validos, indice do estado atual valido
//Pos-condicao: visita no NO do grafo eh realizado
void DFS_visit(Grafo g, int u, vector<int> &visitados, vector<int> &cor);

//Pre-condicao: Grafo existente, vetores validos, indice do estado atual valido
//Pos-condicao: visita vertice do grafo eh realizado
void dijkstraAux(Grafo g, priority_queue<pair<int, int>> &pq, vector<int> &d, vector<int> &pai, vector<int> &cor);

//Pre-condicao: Grafo existente e vetores validos
//Pos-condicao: atualiza o vetor d com as distâncias mínimas entre o vértice inicial e os demais vértices do grafo
bool bellmanFordAux(Grafo g, vector<int> &d, vector<int> &pai, vector<int> &cor);

//Pre-condicao: indices e vetor validos
//Pos-condicao: impressao do caminho da origem ate o vertice passado
void imprimirCaminho(int s, int v, vector<int> pai);

//Pre-condicao: Matriz contendo dados de um Grafo
//Pos-condicao: Retorna a matriz de distâncias mínimas e a matriz de predecessores
// que são atualizadas de acordo com o resultado do algoritmo de Floyd-Warshall
ResultadoFloydWarshall floydWarshallAux(Matriz matriz);
ArvoreGeradora kruskalAux(Grafo g);
ArvoreGeradora primAux(Grafo g, int s);

//Pre-condicao: vetor para pai existente, vertice existente
//Pos-condicao: O retorno eh o pai do vertice
int find_set(vector<int> &pai, int v);

//Pre-condicao: Vetor para pai existente, "a" e "b" sao vertices existentes no grafo
//Pos-condicao: Atualiza o Vetor de Pai
void union_sets(vector<int> &pai, int a, int b);

#endif