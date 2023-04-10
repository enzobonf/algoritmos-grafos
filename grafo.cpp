#include "grafo.h"

using namespace std;

Grafo::Grafo(int nVertices, bool isOrientado){
    this->nVertices = nVertices;
    this->isOrientado = isOrientado;
    inicializaMatriz();

    cout << "n vertices: " << nVertices << '\n';
}

void Grafo::inicializaMatriz(){
    this->matriz = Matriz(this->nVertices, vector<int>(this->nVertices));
    for(int i = 0; i < nVertices; i++)
        for(int j = 0; j < nVertices; j++)
            matriz[i][j] = i == j ? 0 : infinity;
}

void Grafo::addAresta(int origem, int dest, int peso){
    matriz[origem][dest] = peso;
    if(!this->isOrientado){
        matriz[dest][origem] = peso;
    }

    if(peso < 0) temPesoNegativo = true;
}

void Grafo::mostrar() {
    printMatriz(matriz);
}

void Grafo::desenhar() {
    ostringstream os;

    // Adiciona a linha inicial do grafo
    os << (isOrientado ? "digraph" : "graph") << " G {\n";

    // Adiciona os vértices
    for (int i = 0; i < nVertices; i++) {
        os << i << " [label=\"" << i << "\"];\n";
    }

    set<pair<int, int>> arestas;
    // Adiciona as arestas
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {

            if(i == j || (!isOrientado && arestas.count({j, i}) > 0)) continue;;

            if (matriz[i][j] != infinity) {
                os << i << (isOrientado ? " -> " : " -- ") << j;
                os << " [label=\"" << matriz[i][j] << "\"];\n";
            }

            if(!isOrientado) arestas.insert({i, j});
        }
    }

    os << "}\n";
    cout << os.str();
}

void printMatriz(Matriz matriz){
    int v = matriz.size();
    printf("%4s", "");
    for (int i = 0; i < v; i++)
        printf("%2d%3s", i, "");

    cout << '\n';
    for (int i = 0; i < v; i++) {
        printf("%2d  ", i);
        for (int j = 0; j < v; j++){
            if(matriz[i][j] != infinity){
                printf("%2d%3s", matriz[i][j], "");
            }
            else{
                printf("%2s%3s", "-", "");
            }
        }
        cout << '\n';
    }
    cout << '\n' << '\n';
}