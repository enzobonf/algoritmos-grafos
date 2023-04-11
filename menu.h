#include <vector>
#include <iostream>
#include <string>
#include <chrono>
#include "grafo.h"
#include "algoritmos.h"

using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu {
    private:
      Grafo *grafo = nullptr;
      int origem = -1;
      void mostrarOpcoes();
      void carregarGrafo();
      int lerVerticeOrigem();
    public:
      Menu() = default;
      void iniciar();
};

#endif