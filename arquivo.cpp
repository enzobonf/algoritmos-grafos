
#include "arquivo.h"
#include <cstring>

using namespace std;

Arquivo::Arquivo(string nomeArq){
    this->nomeArq = nomeArq;
}

Grafo Arquivo::lerGrafo(){
    FILE *fin;
    fin = fopen(this->nomeArq.c_str(), "r");

    if(fin != nullptr){

        int nVertices; bool orientado;
        int origem, dest, custo;
        char linha[20];

        fscanf(fin, "orientado=%s\n", linha);
        fscanf(fin, "V=%d\n", &nVertices);

        orientado = !strcmp(linha, "sim");
        Grafo grafo(nVertices, orientado);

        cout << orientado << " " << nVertices << '\n';

        while(fscanf(fin, "(%d,%d):%d\n", &origem, &dest, &custo) != EOF){
             printf("%d %d %d\n", origem, dest, custo);
             grafo.addAresta(origem, dest, custo);
        }

        return grafo;
    }
}