#include <cassert>
#include <iostream>
#include "../include/linked_list.h"

using namespace std;

void teste_criaLista() {
    cout<< "Teste: criaLista()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    assert(lista != nullptr);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == nullptr);
    delete lista;
    cout << "Teste criaLista() passou!" << endl;
}

void teste_insere() {
    cout<< "Teste: insereInicio() e insereFinal()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    insereInicio(*lista, "Parada A");
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->nome == "Parada A");

    insereFinal(*lista, "Parada B");
    assert(lista->cardinalidade == 2);
    assert(lista->inicio->proximo->nome == "Parada B");

    delete lista;
    cout << "Teste insereInicio() e insereFinal() passou!" << endl;
}

void teste_removeElemento() {
    cout<< "Teste: removePrimeiraParada() e removeUltimaParada()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    insereInicio(*lista, "Parada A");
    insereFinal(*lista, "Parada B");
    removePrimeiraParada(*lista);
    assert(lista->cardinalidade == 1);
    assert(lista->inicio->nome == "Parada B");

    removeUltimaParada(*lista);
    assert(lista->cardinalidade == 0);
    assert(lista->inicio == nullptr);

    delete lista;
    cout << "Teste removePrimeiraParada() e removeUltimaParada() passou!" << endl;
}

void teste_verificaPosicaoValida() {
    cout<< "Teste: verificaPosicaoValida()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    insereInicio(*lista, "Parada A");
    insereFinal(*lista, "Parada B");

    assert(verificaPosicaoValida(*lista, 0) == true);
    assert(verificaPosicaoValida(*lista, 1) == true);
    assert(verificaPosicaoValida(*lista, 2) == false);
    assert(verificaPosicaoValida(*lista, -1) == false);

    delete lista;
    cout << "Teste verificaPosicaoValida() passou!" << endl;
}

void teste_buscaNomeParada() {
    cout<< "Teste: buscaNomeParada()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    insereInicio(*lista, "Parada A");
    insereFinal(*lista, "Parada B");

    buscaNomeParada(*lista, "Parada A");
    buscaNomeParada(*lista, "Parada B");
    buscaNomeParada(*lista, "Parada C");
    cout << "Teste buscaNomeParada() passou!" << endl;

    delete lista;
}

void teste_mostraLista() {
    cout<< "Teste: mostraRota() e mostraRotaContraria()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    insereInicio(*lista, "Parada A");
    insereFinal(*lista, "Parada B");

    mostraRota(*lista);
    mostraRotaContraria(*lista);

    delete lista;
    cout << "Teste mostraRota() e mostraRotaContraria() passou!" << endl;
}

void teste_contagemParadas() {
    cout<< "Teste: contagemParadas()" << endl;
    ListaDuplamenteEncadeada* lista = criaLista();
    insereInicio(*lista, "Parada A");
    insereFinal(*lista, "Parada B");
    insereFinal(*lista, "Parada C");

    assert(contagemParadas(*lista) == 3);

    delete lista;
    cout << "Teste contagemParadas() passou!" << endl;
}

// ===== FUNÇÃO PRINCIPAL =====
int main() {
    cout << "\n=========================================" << endl;
    cout << "  INICIANDO TESTES DE LINKED LIST" << endl;
    cout << "=========================================" << endl << endl;

    try {
        teste_criaLista();
        teste_insere();
        teste_mostraLista();
        teste_removeElemento();
        teste_verificaPosicaoValida();
        teste_buscaNomeParada();
        teste_contagemParadas();

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
