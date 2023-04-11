#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
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
      //Pre-Condicao: O grafo deve conhecer seu numero de vertices
      //Pos-Condicao: Grafo settado com 0s
      void inicializaMatriz();
    public:
        Matriz matriz;
        //int **matriz;
        int nVertices;
        bool temPesoNegativo = false;
        bool isOrientado;

        //Pre-Condicao: Nenhum
        //Pos-Condicao: Grafo recebe seu formato, numero de vertices, se eh orientado e setta Matriz adjacente com 0s
        Grafo(int nVertices, bool isOrientado);

        //Pre-Condicao: Deve-se saber se o grafo eh orientado ou nao (isOrientado)
        //Pos-Condicao: peso do vertice eh inserido na Matriz, condicao de peso negativo eh atualziada se for o caso
        void addAresta(int origem, int dest, int peso);

        //Pre-Condicao: Grafo existir
        //Pos-Condicao: Imprime a matriz de adjacencia
        void mostrar();

        //Pre-Condicao: grafo existir
        //Pos-Condicao: gera um arquivo .png contendo a imagem do grafo
        void desenhar();

        //Pre-Condicao: grafo existir
        //Pos-Condicao: imprime grafo desenhado
        void desenhar(vector<Aresta> arvoreGeradora, string outFile);

        //Pre-Condicoes: O grafo nao deve ser orientado e nao deve conter vertices repetidos
        //Pos-Condicoes: retorna um valor booleano, indicando se o grafo é conexo ou não
        bool isConexo();
};

// imprime o grafo no formato de matriz adjacente
void printMatriz(Matriz matriz);

#endif