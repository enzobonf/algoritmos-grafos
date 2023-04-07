#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

const int infinity =  std::numeric_limits<int>::max();
enum {BRANCO, CINZA, PRETO};

struct Aresta {
  int dest;
  int peso;

  Aresta(int dest, int peso): dest(dest), peso(peso) {};

  /* friend bool operator> (Aresta a1, Aresta a2) {
    return a1.peso > a2.peso;
  }; */
};

class Grafo {
    private:
      void inicializaMatriz();

    public:
        int **matriz;
        int nVertices;
        bool temPesoNegativo = false;
        bool isOrientado;

        Grafo(int nVertices, bool isOrientado);
        void addAresta(int origem, int dest, int peso);
        void mostrar();
};

#endif