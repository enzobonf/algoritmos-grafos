#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include "grafo.h"

using namespace std;

#ifndef ARQUIVO_H
#define ARQUIVO_H

class Arquivo {
    private:
        string nomeArq;
    public:
        Arquivo(string nomeArq);
        Grafo lerGrafo();
};

#endif