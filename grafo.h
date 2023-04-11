#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <fstream>

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

// representa o infinito, estado inicial do vertice do grafo antes de se calcular distancia da origem
const int infinity =  std::numeric_limits<int>::max();

// Indica o estado do grafo durante seu percorrimento
enum {BRANCO, CINZA, PRETO};

// matriz para representar grafo
typedef vector<vector<int>> Matriz;

// estrutura para representar uma aresta
struct Aresta {
  int origem;
  int dest;
  int peso;

  Aresta(int origem, int dest, int peso): origem(origem), dest(dest), peso(peso) {};

  bool operator< (const Aresta& a2) const {
    return peso < a2.peso;
  };

  static bool compareOrigem(Aresta a1, Aresta a2){
    return a1.origem < a2.origem;
  };
};

// classe para representar um Grafo
class Grafo {
    private:
      void inicializaMatriz();
    public:
        Matriz matriz;
        //int **matriz;
        int nVertices;
        bool temPesoNegativo = false;
        bool isOrientado;

        Grafo(int nVertices, bool isOrientado);
        void addAresta(int origem, int dest, int peso);
        void mostrar();
        void desenhar();
        void desenhar(vector<Aresta> arvoreGeradora, string outFile);
};

// imprime o grafo no formato de matriz adjacente
void printMatriz(Matriz matriz);

#endif