#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include <set>
#include <stdio.h>
#include <sstream>
#include <fstream>

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

const int infinity =  std::numeric_limits<int>::max();
enum {BRANCO, CINZA, PRETO};
typedef vector<vector<int>> Matriz;

struct Aresta {
  int origem;
  int dest;
  int peso;

  Aresta(int origem, int dest, int peso): origem(origem), dest(dest), peso(peso) {};

  bool operator< (const Aresta& a2) const {
    return peso < a2.peso;
  };
};

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

void printMatriz(Matriz matriz);

#endif