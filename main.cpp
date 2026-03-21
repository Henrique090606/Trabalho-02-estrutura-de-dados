#include <iostream>
#include "linked_list.h"

using namespace std;

string lerNomeParada();

int main() {  
    ListaDuplamenteEncadeada* lista = criaLista();

    int opcao;
    
    do{
        do{
            cout<<"-----------Menu de Opcoes----------- "<<endl;
            cout<<"1) Inserir parada no inicio"<<endl;
            cout<<"2) Inserir parada no final"<<endl;
            cout<<"3) Remover primeira parada"<<endl;
            cout<<"4) Remover ultima parada"<<endl;
            cout<<"5) Buscar parada por nome"<<endl;
            cout<<"6) Mostrar rota"<<endl;
            cout<<"7) Mostrar rota contraria"<<endl;
            cout<<"8) Contar paradas"<<endl;
            cout<<"0) Sair"<<endl;
            cin>>opcao;
        }while(opcao<0 || opcao>8);

        if(opcao == 1){
            cout<<"-----------Inserir parada no inicio-----------"<<endl;
            insereInicio(*lista, lerNomeParada());
        }else if(opcao==2){
            cout<<"-----------Inserir parada no final-----------"<<endl;
            insereFinal(*lista, lerNomeParada());
        }else if(opcao==3){
            cout<<"-----------Remover primeira parada-----------"<<endl;
            removePrimeiraParada(*lista);
        }else if(opcao==4){
            cout<<"-----------Remover ultima parada-----------"<<endl;
            removeUltimaParada(*lista);
        }else if(opcao==5){
            cout<<"-----------Buscar parada por nome-----------"<<endl;
            buscaNomeParada(*lista, lerNomeParada());
        }else if(opcao==6){
            cout<<"-----------Mostrar rota-----------"<<endl;
            mostraRota(*lista);
        }else if(opcao==7){
            cout<<"-----------Mostrar rota contraria-----------"<<endl;
            mostraRotaContraria(*lista);
        }else if(opcao==8){
            cout<<"-----------Contar paradas-----------"<<endl;
            cout << "Numero de paradas: " << contagemParadas(*lista) << endl;
        }

    }while(opcao!=0);

    cout<<"Liberando lista e saindo..."<<endl;
    liberaLista(lista);

    return 0;
}

string lerNomeParada() {
    string nome;
    do{
        cout << "Digite o nome da parada: ";
        cin.ignore();
        getline(cin, nome);
    }while(nome.empty());
    return nome;
}