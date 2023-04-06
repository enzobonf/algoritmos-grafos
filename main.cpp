#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "arquivo.h"

using namespace std;

int main(){

    Arquivo *arq = new Arquivo("grafo.txt");
    Grafo grafo = arq->lerGrafo();
    grafo.mostrar();

    cout << grafo.temPesoNegativo;

    return 0;
}
