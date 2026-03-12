#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    cout << "Exercício de Linked List" << endl;
    cout << "------------------------\n" << endl;
    
    ListaSimplesmenteEncadeada* lista = criaLista();
    
    insereInicio(*lista, 10);
    insereInicio(*lista, 20);
    insereInicio(*lista, 30);
    mostraLista(*lista);

    removeElemento(*lista, 2);
    mostraLista(*lista);

    inserePosicao(*lista, 25, 1);
    inserePosicao(*lista, 5, 0);
    mostraLista(*lista);
    
    inverteLista(*lista);
    mostraLista(*lista);
    
    cout<<"Numero de elementos: "<<numeroElementos(*lista)<<endl;

    
    
    destroiLista(*lista);
    mostraLista(*lista);
    free(lista);
    
    return 0;
}
