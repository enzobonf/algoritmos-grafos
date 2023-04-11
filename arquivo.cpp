
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
        int origem, dest, peso;
        char linha[20];

        fscanf(fin, "orientado=%s\n", linha);
        fscanf(fin, "V=%d\n", &nVertices);

        orientado = !strcmp(linha, "sim");
        Grafo grafo(nVertices, orientado);

        cout << orientado << " " << nVertices << '\n';

        while(fscanf(fin, "(%d,%d):%d\n", &origem, &dest, &peso) != EOF){
             //printf("%d %d %d\n", origem, dest, peso);
             grafo.addAresta(origem, dest, peso);
        }

        return grafo;
    }
}

bool Arquivo::escreverArquivoDot(string code){
    auto nomeOut = "output.dot";
    ofstream outfile(nomeOut);
    if(!outfile.is_open()) return false;

    outfile << code;
    outfile.close();
    return true;
}