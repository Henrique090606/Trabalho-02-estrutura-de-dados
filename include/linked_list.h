#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int conteudo;
    Node* proximo;
};

struct ListaSimplesmenteEncadeada {
    int cardinalidade;
    Node* inicio;
};

ListaSimplesmenteEncadeada* criaLista();
void destroiLista(ListaSimplesmenteEncadeada &lista);
void insereInicio(ListaSimplesmenteEncadeada &lista, int conteudo);
bool verificaPosicaoValida(ListaSimplesmenteEncadeada &lista, int posicao);
int recuperaElemento(ListaSimplesmenteEncadeada &lista, int posicao);
int numeroElementos(ListaSimplesmenteEncadeada &lista);
void mostraLista(ListaSimplesmenteEncadeada &lista);
bool listaVazia(ListaSimplesmenteEncadeada &lista);
void inserePosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao);
void removeElemento(ListaSimplesmenteEncadeada &lista, int posicao);
void inverteLista(ListaSimplesmenteEncadeada &lista);

#endif // LINKED_LIST_H
