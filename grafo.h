#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

struct Aresta {
  int dest;
  int custo;

  Aresta(int dest, int custo): dest(dest), custo(custo) {};

  /* friend bool operator> (Aresta a1, Aresta a2) {
    return a1.custo > a2.custo;
  }; */
};

class Grafo {
    private:
      void inicializaMatriz();

    public:
        int nVertices;
        bool isOrientado;
        int **matriz;

        Grafo(int nVertices, bool isOrientado);
        void addAresta(int origem, int dest, int custo);
        void mostrar();
};

#endif