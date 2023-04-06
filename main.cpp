#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "arquivo.h"

using namespace std;

int main(){

    Arquivo *arq = new Arquivo("input1.txt");
    Grafo grafo = arq->lerGrafo();
    grafo.mostrar();

    return 0;
}