#include "menu.h"
#include "arquivo.h"

// Mostra as opções do menu.
// Pré-condição: O menu deve estar inicializado
// Pós-condição: As opções do menu são exibidas na tela.
void Menu::mostrarOpcoes() {
    cout << "\nSelecione uma das opcoes abaixo\n\n";
    cout << "1 - Busca em profundidade" << '\n'
         << "2 - Busca em largura" << '\n'
         << "3 - Dijkstra" << '\n'
         << "4 - Bellman-Ford" << '\n'
         << "5 - Floyd-Warshall" << '\n'
         << "6 - Kruskal" << '\n'
         << "7 - Prim" << '\n'
         << "8 - Desenhar grafo" << "\n\n"
         << "9 - Carregar outro grafo" << '\n'
         << "0 - Sair" << '\n';
}

// Mostra as opções do menu.
// Pré-condição: O menu deve estar inicializado
// Pós-condição: As opções do menu são exibidas na tela, 
// e a opção do usuário é pedida
void Menu::iniciar() {

    int opcao = -1;
    string nomeArq;

    cout << "1 -Carregar grafo\n"
         << "0 - Sair\n" ;
    
    cin >> opcao;
    if(opcao == 1)
        carregarGrafo();

    while(opcao != 0){
        this->mostrarOpcoes();
        cin >> opcao;

        switch(opcao){
            case 1:
                lerVerticeOrigem();
                Algoritmos::executarDFS(*grafo, origem);
                break;
            case 2:
                lerVerticeOrigem();
                Algoritmos::executarBFS(*grafo, origem);
                break;
            case 3:
                lerVerticeOrigem();
                Algoritmos::executarDijkstra(*grafo, origem);
                break;
            case 4:
                lerVerticeOrigem();
                Algoritmos::executarBellmanFord(*grafo, origem);
                break;
            case 5:
                Algoritmos::executarFloydWarshall(*grafo);
                break;
            case 6:
                Algoritmos::executarKruskal(*grafo);
                break;
            case 7:
                lerVerticeOrigem();
                Algoritmos::executarPrim(*grafo, origem);
                break;
            case 8:
                grafo->desenhar();
                break;
            case 9:
                carregarGrafo();
                break;
            default:
                opcao = 0;
                break;
        }
    }
}

int Menu::lerVerticeOrigem(){
    cout << "Entre com o vertice de origem: ";
    cin >> origem; cout << '\n';
}

void Menu::carregarGrafo(){
    string nomeArq;
    cout << "Digite o nome do arquivo do grafo: ";
    cin >> nomeArq;
    Arquivo arq = Arquivo(nomeArq);    
    grafo = new Grafo(arq.lerGrafo());
    grafo->mostrar();
}