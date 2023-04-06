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
        for(int j = 0; j < nVertices; j++)
            matriz[i][j] = i == j ? 0 : infinity;
    }
}

void Grafo::addAresta(int origem, int dest, int peso){
    matriz[origem][dest] = peso;
    if(!this->isOrientado){
        matriz[dest][origem] = peso;
    }

    if(peso < 0) temPesoNegativo = true;
}

void Grafo::mostrar() {

    printf("%4s", "");
    for (int i = 0; i < nVertices; i++)
        printf("%2d%3s", i, "");

    cout << '\n';
    for (int i = 0; i < nVertices; i++) {
        printf("%2d  ", i);
        for (int j = 0; j < nVertices; j++){
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