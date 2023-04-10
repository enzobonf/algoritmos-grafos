#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include "grafo.h"

using namespace std;

#ifndef ARQUIVO_H
#define ARQUIVO_H

// classe criado para realizar a leitura do arquivo texto
// contendo os dados do grafo
class Arquivo {
    private:
        string nomeArq;
    public:
        // Pre-Condicao: Nenhum
        // Pos-Condicao: classe arquivo recebe o nome do arquivo a ser lido
        Arquivo(string nomeArq);

        //Pre-Condicao: Nenhum
        //Pos-Condicao: Grafo eh lido
        Grafo lerGrafo();
};

#endif