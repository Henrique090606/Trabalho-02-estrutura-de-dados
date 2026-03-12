#include <cassert>
#include <iostream>
#include "../include/linked_list.h"

using namespace std;

// ===== TESTES DA FUNÇÃO criaLista =====
void teste_criaLista() {
    cout << "Testando criaLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();
    assert(lista != NULL);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "criaLista() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO insere (inserção no início) =====
void teste_insere() {
    cout << "Testando insere()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere primeiro elemento
    insereInicio(*lista, 10);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio != NULL);
    assert(lista->inicio->conteudo == 10);
    assert(lista->inicio->proximo == NULL);

    // Insere segundo elemento (deve ficar no início)
    insereInicio(*lista, 20);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 20);
    assert(lista->inicio->proximo->conteudo == 10);

    // Insere terceiro elemento
    insereInicio(*lista, 30);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 30);
    assert(lista->inicio->proximo->conteudo == 20);
    assert(lista->inicio->proximo->proximo->conteudo == 10);

    destroiLista(*lista);
    free(lista);
    cout << "insere() passou em todos os testes" << endl;
}

// ===== TESTES DA FUNÇÃO destroiLista =====
void teste_destroiLista() {
    cout << "Testando destroiLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insereInicio(*lista, 1);
    insereInicio(*lista, 2);
    insereInicio(*lista, 3);

    // Destrói a lista
    destroiLista(*lista);

    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    free(lista);
    cout << "destroiLista() passou em todos os testes" << endl;
}

void teste_mostraLista() {
    cout << "Testando mostraLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insereInicio(*lista, 1);
    insereInicio(*lista, 2);
    insereInicio(*lista, 3);

    cout << "Conteúdo da lista (deve ser 3 2 1): ";
    mostraLista(*lista);

    destroiLista(*lista);
    free(lista);
    cout << "mostraLista() passou em todos os testes" << endl;
}

void teste_removeElemento() {
    cout << "Testando removeElemento()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insereInicio(*lista, 1);
    insereInicio(*lista, 2);
    insereInicio(*lista, 3);

    // Remove elemento do meio
    removeElemento(*lista, 1);
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->conteudo == 3);
    assert(lista->inicio->proximo->conteudo == 1);

    // Remove elemento do início
    removeElemento(*lista, 0);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->conteudo == 1);

    // Remove último elemento
    removeElemento(*lista, 0);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == NULL);

    destroiLista(*lista);
    free(lista);
    cout << "removeElemento() passou em todos os testes" << endl;
}

void teste_inverteLista() {
    cout << "Testando inverteLista()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insereInicio(*lista, 1);
    insereInicio(*lista, 2);
    insereInicio(*lista, 3);

    // Inverte a lista
    inverteLista(*lista);
    assert(lista->cardinalidade == 3);
    assert(lista->inicio->conteudo == 1);
    assert(lista->inicio->proximo->conteudo == 2);
    assert(lista->inicio->proximo->proximo->conteudo == 3);

    destroiLista(*lista);
    free(lista);
    cout << "inverteLista() passou em todos os testes" << endl;
}

void teste_verificaPosicaoValida() {
    cout << "Testando verificaPosicaoValida()..." << endl;

    ListaSimplesmenteEncadeada* lista = criaLista();

    // Insere elementos
    insereInicio(*lista, 1);
    insereInicio(*lista, 2);
    insereInicio(*lista, 3);

    assert(verificaPosicaoValida(*lista, 0) == true);
    assert(verificaPosicaoValida(*lista, 1) == true);
    assert(verificaPosicaoValida(*lista, 2) == true);
    assert(verificaPosicaoValida(*lista, 3) == false);
    assert(verificaPosicaoValida(*lista, -1) == false);

    destroiLista(*lista);
    free(lista);
    cout << "verificaPosicaoValida() passou em todos os testes" << endl;
}

// ===== FUNÇÃO PRINCIPAL =====
int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    try {
        teste_criaLista();
        teste_insere();
        teste_destroiLista();
        teste_mostraLista();
        teste_inverteLista();
        teste_removeElemento();
        teste_verificaPosicaoValida();


        cout << "\n=========================================" << endl;
        cout << "  TODOS OS TESTES PASSARAM COM SUCESSO!" << endl;
        cout << "=========================================" << endl << endl;

        return 0;
    } catch (const exception& e) {
        cout << "\nErro durante os testes: " << e.what() << endl;
        return 1;
    } catch (const char* e) {
        cout << "\nErro durante os testes: " << e << endl;
        return 1;
    }
}
