#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>

using namespace std;

struct Node {
    string nome;
    Node* proximo;
    Node* anterior;
};

struct ListaDuplamenteEncadeada {
    int cardinalidade;
    Node* inicio;
};

ListaDuplamenteEncadeada* criaLista();
void insereInicio(ListaDuplamenteEncadeada &lista, string conteudo);
void insereFinal(ListaDuplamenteEncadeada &lista, string conteudo);
bool ehVazia(ListaDuplamenteEncadeada &lista);
bool verificaPosicaoValida(ListaDuplamenteEncadeada &lista, int posicao);
void inserePosicao(ListaDuplamenteEncadeada &lista, string conteudo, string posicao);
void removePrimeiraParada(ListaDuplamenteEncadeada &lista);
void removeUltimaParada(ListaDuplamenteEncadeada &lista);
void buscaNomeParada(ListaDuplamenteEncadeada &lista, string nome);
void mostraRota(ListaDuplamenteEncadeada &lista);
void mostraRotaContraria(ListaDuplamenteEncadeada &lista);
int contagemParadas(ListaDuplamenteEncadeada &lista);

#endif // LINKED_LIST_H
