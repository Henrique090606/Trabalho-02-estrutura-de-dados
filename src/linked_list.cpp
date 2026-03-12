#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaSimplesmenteEncadeada* criaLista()
{
    ListaSimplesmenteEncadeada* lista = (ListaSimplesmenteEncadeada*) malloc(sizeof(ListaSimplesmenteEncadeada));
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    return lista;
}

void destroiLista(ListaSimplesmenteEncadeada &lista)
{
    if(listaVazia(lista)){
        cout << "Lista já está vazia" << endl;
        return;
    }
    Node* temp;
    while (lista.inicio != NULL) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        free(temp);
    }
    lista.cardinalidade = 0;
}

void insereInicio(ListaSimplesmenteEncadeada &lista, int conteudo)
{
    Node* novoNode = new Node;
    novoNode->conteudo = conteudo;
    novoNode->proximo = lista.inicio;
    lista.inicio = novoNode;
    lista.cardinalidade++;
}

void inserePosicao(ListaSimplesmenteEncadeada &lista, int conteudo, int posicao)
{
    if (!verificaPosicaoValida(lista, posicao)) {
        cerr << "Posição inválida para inserção" << endl;
        return;
    }

    Node* novoNode = (Node*) malloc(sizeof(Node));
    novoNode->conteudo = conteudo;

    if (posicao == 0) {
        novoNode->proximo = lista.inicio;
        lista.inicio = novoNode;
    } else {
        Node* atual = lista.inicio;
        for (int i = 0; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novoNode->proximo = atual->proximo;
        atual->proximo = novoNode;
    }
    lista.cardinalidade++;
}

bool verificaPosicaoValida(ListaSimplesmenteEncadeada &lista, int posicao)
{
    return posicao >= 0 && posicao < lista.cardinalidade;
}

int recuperaElemento(ListaSimplesmenteEncadeada &lista, int posicao)
{
    if (!verificaPosicaoValida(lista, posicao)){
        cout << "Posição inválida" << endl;
        return -1;
    }

    Node* atual = lista.inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }
    return atual->conteudo;
}

int numeroElementos(ListaSimplesmenteEncadeada &lista){
    return lista.cardinalidade;
}

void mostraLista(ListaSimplesmenteEncadeada &lista)
{
    if(listaVazia(lista)){
        cout << "Lista vazia" << endl;
        return;
    }
    Node* atual = lista.inicio;
    for(int i = 0; i < lista.cardinalidade; i++){
        cout<<recuperaElemento(lista, i)<<" ";
    }
    cout << endl;
}

bool listaVazia(ListaSimplesmenteEncadeada &lista)
{
    return lista.cardinalidade == 0;
}

void removeElemento(ListaSimplesmenteEncadeada &lista, int posicao)
{
    if (!verificaPosicaoValida(lista, posicao)){
        cout << "Posição inválida para remoção" << endl;
        return;
    }

    Node* temp;
    if (posicao == 0) {
        temp = lista.inicio;
        lista.inicio = lista.inicio->proximo;
    } else {
        Node* atual = lista.inicio;
        for (int i = 0; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        temp = atual->proximo;
        atual->proximo = temp->proximo;
    }
    free(temp);
    lista.cardinalidade--;
}

void inverteLista(ListaSimplesmenteEncadeada &lista)
{
    if(listaVazia(lista)){
        cout << "Lista está vazia" << endl;
        return;
    }

    if(numeroElementos(lista)==1){
        cout << "Lista tem apenas um elemento"<<endl;
        return;
    }

    Node* anterior = NULL;
    Node* atual = lista.inicio;
    Node* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    lista.inicio = anterior;
}