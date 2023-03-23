# Caminho Guloso

## Exercício Proposto

Atividade avaliativa da disciplina Algoritmos e Estruturas de Dados I  sobre o o maior caminho percorrido em um labirinto.

O arquivo (input.data) disponibilizado pelo código feito pelo professor Michel Pires é composto pela definição do número de matrizes e o  tamanho N x N que elas terão. Essas matrizes serão utilizadas como o labirinto a ser percorrido. O objetivo do problema é começar pela primeira matriz por uma coordenada que o usuário informará, depois chegar até a posição final dela(N,N) e nas matrizes seguintes começar da posição (0,0) e chegar na sua última(N,N) até todas elas serem lidas. 

Foi pedido pelo o professor que no final do programa apresentasse o maior caminho percorrido. Por isso, o método de escolha de qual será a  coordenada escolhida posteriormente é o maior número de cada uma em comparação as casas vizinhas. Porém, existem regras no método de escolha dependendo da posição da coordenada. Elas são:

* Quando a coordenada tem a coluna como 0:

![image](https://user-images.githubusercontent.com/102706840/227315265-a74144e3-634b-463e-93ef-d961b1ed9b64.png)

Nesse caso, a comparação do maior número são entre a direita, diagonal inferior direita e o debaixo.

* Quando a coordenada tem a coluna como N:

![image](https://user-images.githubusercontent.com/102706840/227316777-9acb8586-fe4c-4762-b12e-a59c22478a49.png)

Já nesse caso, a comparação é entre a esquerda, diagonal inferior esquerda e o debaixo.

* Quando a coordenada tem a linha como N:

![image](https://user-images.githubusercontent.com/102706840/227317145-11dbcf69-1c90-439b-8dfd-30901d7f993d.png)

E quando chega na última linha, independente de qualquer coluna só poderá se mover para a direita até a última posição.








# Compilação e Execução

O caminho guloso disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado executar um `make clean` antes do `make`.
