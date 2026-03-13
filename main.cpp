#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    cout << "Exercício de Linked List" << endl;
    cout << "------------------------\n" << endl;
    
    ListaSimplesmenteEncadeada* lista = criaLista();
    
    cout<<"Inserindo no inicio"<<endl;
    insereInicio(*lista, 10);
    mostraLista(*lista);
    insereInicio(*lista, 20);
    mostraLista(*lista);
    insereInicio(*lista, 30);
    mostraLista(*lista);

    cout<<"Removendo elemento"<<endl;
    removeElemento(*lista, 0);
    mostraLista(*lista);

    cout<<"Inserindo em posicao especifica"<<endl;
    inserePosicao(*lista, 25, 1);
    inserePosicao(*lista, 5, 0);
    mostraLista(*lista);
    
    cout<<"invertendo a lista"<<endl;
    inverteLista(*lista);
    mostraLista(*lista);
    
    cout<<"Numero de elementos: "<<numeroElementos(*lista)<<endl;

    
    cout<<"destruindo a lista"<<endl;
    destroiLista(*lista);
    mostraLista(*lista);
    free(lista);
    
    return 0;
}
