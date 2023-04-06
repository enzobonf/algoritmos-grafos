#include "grafo.h"

using namespace std;

Grafo::Grafo(int nVertices, bool isOrientado){
    this->nVertices = nVertices;
    this->isOrientado = isOrientado;
    inicializaMatriz();

    cout << "n vertices: " << nVertices << '\n';
}

void Grafo::inicializaMatriz(){
    this->matriz = new int*[nVertices];
    for(int i = 0; i < nVertices; i++){
        this->matriz[i] = new int[nVertices];
        for(int j = 0; j < nVertices; j++){
            matriz[i][j] = 0;
        }
    }
}

void Grafo::addAresta(int origem, int dest, int custo){
    matriz[origem][dest] = custo;
    if(!this->isOrientado){
        matriz[dest][origem] = custo;
    }
}

void Grafo::mostrar() {
  int v, w;
  for (v = 0; v < nVertices; ++v) {
    printf("%2d:", v);
    for (w = 0; w < nVertices; ++w)
      if (matriz[v][w] != 0)
        printf(" %2d (%2d)", w, matriz[v][w]);
    printf("\n");
  }
  printf("\n\n");
}