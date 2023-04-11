#include "grafo.h"
#include "arquivo.h"

using namespace std;

Grafo::Grafo(int nVertices, bool isOrientado){
    this->nVertices = nVertices;
    this->isOrientado = isOrientado;
    inicializaMatriz();

    cout << "n vertices: " << nVertices << '\n';
}

void Grafo::inicializaMatriz(){
    this->matriz = Matriz(this->nVertices, vector<int>(this->nVertices));
    for(int i = 0; i < nVertices; i++)
        for(int j = 0; j < nVertices; j++)
            matriz[i][j] = i == j ? 0 : infinity;
}

void Grafo::addAresta(int origem, int dest, int peso){
    matriz[origem][dest] = peso;
    if(!this->isOrientado){
        matriz[dest][origem] = peso;
    }

    if(peso < 0) temPesoNegativo = true;
}

void Grafo::mostrar() {
    printMatriz(matriz);
}

void Grafo::desenhar(){
    this->desenhar(vector<Aresta>(), "grafo.png");
}

void Grafo::desenhar(vector<Aresta> arvoreGeradora, string outFile) {
    ostringstream os;

    // Adiciona a linha inicial do grafo
    os << (isOrientado ? "digraph" : "graph") << " G {\n";

    // Adiciona os vértices
    for (int i = 0; i < nVertices; i++) {
        os << i << " [label=\"" << i << "\"" << (arvoreGeradora.size() ? ", color=green" : "") << "];\n";
    }

    cout << os.str() << endl;

    set<pair<int, int>> arestas;

    for(auto& aresta: arvoreGeradora){ // Adiciona as arestas da árvore geradora
        os << aresta.origem << " -- " << aresta.dest;
        os << " [label=\"" << matriz[aresta.origem][aresta.dest] << "\", color=green];\n";
        arestas.insert({aresta.origem, aresta.dest});
    }

    // Adiciona as arestas restantes
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {

            if(i == j || arestas.count({i, j}) || (!isOrientado && arestas.count({j, i}) > 0)) continue;;

            if (matriz[i][j] != infinity) {
                os << i << (isOrientado ? " -> " : " -- ") << j;
                os << " [label=\"" << matriz[i][j] << "\"];\n";
            }

            if(!isOrientado) arestas.insert({i, j});
        }
    }

    os << "}\n";
    if(Arquivo::escreverArquivoDot(os.str())){
        string cmd = "dot -Tpng output.dot -o" + outFile;
        system(cmd.c_str());
    }
    else{
        cout << "Erro ao desenhar o grafo\n";
    }
}

void printMatriz(Matriz matriz){
    int v = matriz.size();
    printf("%4s", "");
    for (int i = 0; i < v; i++)
        printf("%2d%3s", i, "");

    cout << '\n';
    for (int i = 0; i < v; i++) {
        printf("%2d  ", i);
        for (int j = 0; j < v; j++){
            if(matriz[i][j] != infinity){
                printf("%2d%3s", matriz[i][j], "");
            }
            else{
                printf("%2s%3s", "-", "");
            }
        }
        cout << '\n';
    }
    cout << '\n' << '\n';
}