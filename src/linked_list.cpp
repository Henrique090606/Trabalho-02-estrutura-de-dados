#include "linked_list.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ListaDuplamenteEncadeada* criaLista()
{
    ListaDuplamenteEncadeada* lista = new ListaDuplamenteEncadeada;
    lista->cardinalidade = 0;
    lista->inicio = NULL;
    return lista;
}

void insereInicio(ListaDuplamenteEncadeada &lista, string conteudo){
    Node* novoNode = new Node;
    
    novoNode->nome = conteudo;
    novoNode->proximo = lista.inicio;
    novoNode->anterior = NULL;

    if (lista.inicio != NULL) {
        lista.inicio->anterior = novoNode;
    }

    lista.inicio = novoNode;
    lista.cardinalidade++;
    cout<<"Parada inserida com sucesso!"<<endl;
}

void insereFinal(ListaDuplamenteEncadeada &lista, string conteudo){
    Node* novoNode = new Node;
    
    novoNode->nome = conteudo;
    novoNode->proximo = NULL;

    if(ehVazia(lista)){
        novoNode->anterior = NULL;
        lista.inicio = novoNode;
    }else{
        Node* temp = lista.inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNode;
        novoNode->anterior = temp;
    }
    lista.cardinalidade++;
    cout<<"Parada inserida com sucesso!"<<endl;
}

bool ehVazia(ListaDuplamenteEncadeada &lista){
    return lista.cardinalidade == 0;
}

bool verificaPosicaoValida(ListaDuplamenteEncadeada &lista, int posicao){
    return posicao >= 0 && posicao < lista.cardinalidade;
}

void inserePosicao(ListaDuplamenteEncadeada &lista, string conteudo, int posicao){
    if (!verificaPosicaoValida(lista, posicao)) {
        cout << "Posição inválida!" << endl;
        return;
    }

    if (posicao == 0) {
        insereInicio(lista, conteudo);
        return;
    }

    if (posicao == lista.cardinalidade) {
        insereFinal(lista, conteudo);
        return;
    }

    Node* novoNode = new Node;
    novoNode->nome = conteudo;

    Node* temp = lista.inicio;
    for (int i = 0; i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    novoNode->proximo = temp->proximo;
    novoNode->anterior = temp;

    if (temp->proximo != NULL) {
        temp->proximo->anterior = novoNode;
    }
    
    temp->proximo = novoNode;
    lista.cardinalidade++;
    cout<<"Parada inserida com sucesso!"<<endl;
}

void removePrimeiraParada(ListaDuplamenteEncadeada &lista){
    if (ehVazia(lista)) {
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* temp = lista.inicio;
    lista.inicio = temp->proximo;

    if (lista.inicio != NULL) {
        lista.inicio->anterior = NULL;
    }

    delete temp;
    lista.cardinalidade--;
    cout<<"Parada removida com sucesso!"<<endl;
}

void removeUltimaParada(ListaDuplamenteEncadeada &lista){
    if (ehVazia(lista)) {
        cout << "Lista vazia!" << endl;
        return;
    }

    if (lista.cardinalidade == 1) {
        removePrimeiraParada(lista);
        return;
    }

    Node* temp = lista.inicio;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }

    temp->anterior->proximo = NULL;
    delete temp;
    lista.cardinalidade--;
    cout<<"Parada removida com sucesso!"<<endl;
}

void buscaNomeParada(ListaDuplamenteEncadeada &lista, string nome){
    Node* temp = lista.inicio;
    while (temp != NULL) {
        if (temp->nome == nome) {
            cout << "Nome encontrado: " << temp->nome << endl;
            return;
        }
        temp = temp->proximo;
    }
    cout << "Nome nao encontrado!" << endl;
}

void mostraRota(ListaDuplamenteEncadeada &lista){
    if(ehVazia(lista)){
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* temp = lista.inicio;
    cout << "Rota: ";
    while (temp != NULL) {
        cout << temp->nome << " ";
        temp = temp->proximo;
    }
    cout << endl;
}

void mostraRotaContraria(ListaDuplamenteEncadeada &lista){
    if(ehVazia(lista)){
        cout << "Lista vazia!" << endl;
        return;
    }

    Node* temp = lista.inicio;
    while(temp->proximo != NULL){
        temp = temp->proximo;
    }

    cout << "Rota Contraria: ";
    while(temp!=NULL){
        cout<<temp->nome<<" ";
        temp=temp->anterior;
    }
    cout<<endl;
}

int contagemParadas(ListaDuplamenteEncadeada &lista){
    return lista.cardinalidade;
}