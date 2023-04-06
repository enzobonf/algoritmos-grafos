#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

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