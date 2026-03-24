Comandos para rodar: 

-Main:
g++ main.cpp src/linked_list.cpp -Iinclude -o main
./main

-tests:
g++ tests/tests.cpp src/linked_list.cpp -Iinclude -o tests
.\tests

Exemplo de saída:

-----------Menu de Opcoes----------- 
1) Inserir parada no inicio
2) Inserir parada no final
3) Remover primeira parada
4) Remover ultima parada
5) Buscar parada por nome
6) Mostrar rota
7) Mostrar rota contraria
8) Contar paradas
0) Sair


Respondendo as perguntas:

1. Qual variação de lista foi escolhida (simplesmente encadeada,
duplamente encadeada ou circular)?

  A variação de lista escolhida foi a Lista Duplamente Encadeada.


2. Por que essa estrutura é mais adequada para esse problema
do que as demais? Justifique com base nas operações
implementadas.

  Essa é a mais adequada pois ela pode ser percorrida nos dois sentidos, facilitando operações de inserção e de exibição da rota, 
  pois ao ter os campos próximo e anterior, faz com que não seja preciso percorrer a lista inteira toda vez que quisermos fazer uma operação, 
  tornando-as assim muito mais práticas e fáceis de usar do que em comparação a uma lista simplesmente encadeada ou circular.


3. Haveria algum cenário real (ex: linha circular de ônibus) em que
outra variação de lista seria mais vantajosa? Explique.

  Sim, pois em um cenário onde as rotas de ônibus fossem circulares, ou seja, ao passar pelo último ponto ela voltaria ao primeiro, 
  formando assim um loop, a Lista Circular seria a melhor escolha para usar nesse código, pois nesse estilo de lista, o último elemento
  aponta sempre para o primeiro, permitindo uma navegação contínua.