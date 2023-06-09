# Caminho Guloso

## Exercício Proposto

Atividade avaliativa da disciplina Algoritmos e Estruturas de Dados I  sobre o o maior caminho percorrido em um labirinto.

O arquivo (input.data) disponibilizado pelo código feito pelo professor Michel Pires é composto pela definição do número de matrizes e o  tamanho N x N que elas terão. Essas matrizes serão utilizadas como o labirinto a ser percorrido. O objetivo do problema é começar pela primeira matriz por uma coordenada que o usuário informará, depois chegar até a posição final dela(N-1,N-1) e nas matrizes seguintes começar da posição (0,0) e chegar na sua última(N-1,N-1) até todas elas serem lidas. 

Foi pedido pelo o professor que no final do programa apresentasse o maior caminho percorrido e a soma dele. Por isso, o método de escolha da coordenada posterior é o maior número de cada uma em comparação as casas vizinhas. Porém, existem regras no método de escolha dependendo da posição da coordenada. Elas são:

* Quando a coordenada tem a coluna como 0:

![image](https://user-images.githubusercontent.com/102706840/227315265-a74144e3-634b-463e-93ef-d961b1ed9b64.png)

Nesse caso, a comparação do maior número são entre a direita, diagonal inferior direita e o abaixo.

* Quando a coordenada tem a coluna como N-1:

![image](https://user-images.githubusercontent.com/102706840/227316777-9acb8586-fe4c-4762-b12e-a59c22478a49.png)

Já nesse caso, a comparação é entre a esquerda, diagonal inferior esquerda e o abaixo.

* Quando a coordenada tem a linha como N-1:

![image](https://user-images.githubusercontent.com/102706840/227317145-11dbcf69-1c90-439b-8dfd-30901d7f993d.png)

E quando chega na última linha, independente de qual coluna esteja, apenas poderá se mover para a direita até a última posição.

* Em qualquer outra posição:

![image](https://user-images.githubusercontent.com/102706840/227322545-78467ece-2dd7-4d43-9ae1-019d484b68a2.png)


A comparação será feita entre a esquerda, direita, diagonais inferiores e o debaixo.

O caminho não pode retornar para qualquer casa que já tenha passado e também não poderá retornar para linha de cima a partir do momento que foi para a linha seguinte.

## Entrada

O primeiro passo da entrada é o arquivo "input.data" que é fornecido pelo usuário. Este arquivo deve estar na pasta principal junto dos outros e possuir a formatação em que na primeira linha é informado o tamanho da matriz para ser lida corretamente no programa, como no exemplo abaixo:

![image](https://user-images.githubusercontent.com/102706840/227331829-14272194-db84-47ff-9a0c-caf8f7a9fe28.png)

Além de possuir as matrizes preenchidas corretamente como a seguir:

![image](https://user-images.githubusercontent.com/102706840/227332588-e9c73f61-5fd9-4947-8f01-f871b19a1c9c.png)

No exemplo dado, mostra que a matriz terá o tamanho de 7 x 7 e no outro como deverá estar preenchida. Porém, a matriz poderá ser de qualquer tamanho e no arquivo ter quantas o usuário quiser. Nesse arquivo utilizado para teste há apenas 4 matrizes.

Além dessa entrada, o usuário também deverá informar de qual posição gostaria de começar na primeira matriz da seguinte maneira: 

![image](https://user-images.githubusercontent.com/102706840/227334494-fb6943e3-b970-4282-93d4-b46dc02c7947.png)

Assim, o programa iniciará o caminho a ser percorrido.

## Implementação

Para a implementação da solução do problema foi utilizado a linguagem c++. Na linguagem foram criados os arquivos main.cpp, labirinto.hpp e labirinto.cpp .

No labirinto.hpp foram criadas as funções utilizadas para ler o arquivo e caminhar pela matriz.

![image](https://user-images.githubusercontent.com/102706840/227354545-b7065579-eb7a-4e4a-9dcc-9634c6fcb0d5.png)


No labirinto.cpp foram desenvolvidas as funções criadas no hpp que serão explicadas a seguir:

* void LerMatriz()

![image](https://user-images.githubusercontent.com/102706840/227361321-2e0f9e97-c341-48a6-98f9-dfba22a21ad6.png)


Nessa função foi passado o arquivo "input.data" por ter sido aberto no main. Primeiro se lê nela as dimensões das matrizes informadas na primeira linha do arquivo, depois há um array de ponteiros que é alocado usando a palavra-chave "new". Esse array tem "rows" elementos, ou seja, "rows" ponteiros para arrays de inteiros. Depois, o loop "for" é usado para alocar um array de inteiros para cada ponteiro do array alocado anteriormente. O tamanho de cada array é "cols".

Após isso há um "while" que é utilizado para ler as matrizes enquanto o arquivo não falhar, dentro dele há um "duplo for" para fazer a leitura de cada elemento da matriz. Após isso, há a função Caminhar() que será utilizada para andar na matriz até chegar ao seu último elemento.

![image](https://user-images.githubusercontent.com/102706840/227361762-993b6b27-df67-4627-a5a6-a645103ccbab.png)


Foi criado um contador para saber qual é a matriz que está sendo lida e depois tem um "duplo for" novamente para imprimir a matriz. Nesse "duplo for", existe a condição de imprimir # no lugar do -1 para mostrar o caminho feito. Quando acaba o "while", existe ainda a apresentação da soma total dos elementos percorridos dentro de todas as matrizes e depois uma liberação de memória.

* void Caminhar()

![image](https://user-images.githubusercontent.com/102706840/227357648-1a16b99a-2c99-45b4-a6e8-e9740cdc50c9.png)



Nessa função é passado a matriz lida naquele momento, o número de linhas e colunas da matriz para fazer um parâmetro das condições, a soma para no final conseguir mostrar o total dela e o ContarMatriz que servirá para saber em qual matriz está.

Se o ContarMatriz for 0, significa que ainda está na primeira matriz, então o programa pedirá o usuário para informar a linha e coluna que ele quer começar, se não for 0 ,  começará pela posição (0,0) como o exercício pediu.

Nisso, já somará a primeira posição que encontra a matriz, seja a (0,0) ou outra em que o usuário tiver informado. E então, é feito um "do while" para aplicar as medidas que serão tomadas se a coluna for 0, se a coluna for N-1, se a linha for N-1 e se estiver em outra posição. Isso vai se repetir até j+1 ou k+1 for diferente de N.

* Funções Caminho0(), Caminho1(), Caminho2() e Caminho3()

Nelas foram passadas a matriz, o k e o j para poder localizar a posição que está na matriz e extrair o número daquela posição. Além de passar o soma para poder somar o elemento.

As funções são determinadas para ,respectivamente, andar apenas para a direita, andar para baixo, direita e diagonal inferior direita, andar para esquerda, diagonal inferior esquerda e baixo e para todas as posições menos para cima. Elas foram tratadas com "if's" que comparam se aquela posição é maior que todas as outras e se for, ela será a próxima posição. Também é somado o elemento e aquela posição antiga se transforma em -1 , pois o caminho não poderá retroceder para ela.

As posições são dadas por:

* direita-> [*k][*j+1]
* esquerda-> [*k][*j-1]
* para baixo-> [*k+1][*j]
* diagonal direita inferior-> [*k+1][*j+1]
* diagonal esquerda inferior-> [*k+1][*j-1]

E no caso de se todas as coordenadas forem números iguais, o algoritmo deverá optar pela diagonal direita sempre,com exceção de quando a coluna é igual a N-1 que deverá optar para baixo.

No main apenas foi incluso o labirinto.hpp , aberto o arquivo e feito a chamada da função LerMatriz().

## Saída

A saída apresentará o caminho percorrido pela matriz em # e a soma total do caminho percorrido. Como a seguir do exemplo de teste:

![image](https://user-images.githubusercontent.com/102706840/227360261-61945599-5ca8-422b-baf2-e693af5ead00.png)



# Compilação e Execução

O caminho guloso disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado executar um `make clean` antes do `make`.
