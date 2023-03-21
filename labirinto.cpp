#include "labirinto.hpp"
#include <iostream>

void GerarMatriz(ifstream& input){
    
    int rows, cols , soma=0;
    input >> rows >> cols; // lê as dimensões da matriz
    int N=0, ContarMatriz=0;
    N=rows;
    int **matriz;

    matriz = new int*[rows]; // aloca um array de ponteiros
    for (int i = 0; i < rows; i++) {
        matriz[i] = new int[cols]; // aloca um array para cada linha
    }

    while(!input.fail()){
       for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                input >> matriz[i][j]; // lê os elementos da matriz
                if(input.fail()){
                    break;
                }
            }
        }

        if(input.fail()){
            break;
        }

        Caminhar(matriz,N,ContarMatriz,&soma);

        ContarMatriz++;

        cout << endl; 
        cout << endl; 

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(matriz[i][j]==-1){
                    cout<<"#"<<" "<<"\t";
                }else{ 
                    cout << matriz[i][j] << " " << "\t";
                }
            }
            cout << endl;
            
        }

        cout << endl; 
         


    } 

    cout<<"A soma total do maior caminho é: "<<soma<<endl;

        for (int i = 0; i < rows; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    

    
   
    
}

void Caminhar(int**matriz,int N, int ContarMatriz,int* soma){
    int k=0, j=0;

    if(ContarMatriz==0){ 
    cout<< "Qual o número da linha que você quer começar?"<<endl;
    cin >> k;


    cout<< "Qual o número da coluna que você quer começar?"<<endl;
    cin >> j;
    }else{
        k=0;
        j=0;
    }


    *soma+=matriz[k][j];

    do{

       if(k==(N-1)){
            Caminho0(matriz,&k,&j,soma);
        }
        else if(j==0){
            Caminho1(matriz,&k,&j,soma);
        }
        else if(j==(N-1)){
            Caminho2(matriz,&k,&j,soma);
        }
        else{
           Caminho3(matriz,&k,&j,soma);
        }

    }while(j+1 != N || k+1 != N);
    

}
void Caminho0(int** matriz, int *k,int* j,int* soma){
    *soma+=matriz[*k][*j+1];
    matriz[*k][*j]=-1;
    *j=*j+1;
    
    if(*k == *j){
        matriz[*k][*j]=-1;
    }

}
void Caminho1(int** matriz, int *k,int* j,int* soma){

    if(matriz[*k][*j+1]>matriz[*k+1][*j] && matriz[*k][*j+1]>matriz[*k+1][*j+1]){
        *soma+=matriz[*k][*j+1];
        matriz[*k][*j]=-1;
        *j=*j+1;
    }
    else if(matriz[*k+1][*j]>matriz[*k][*j+1] && matriz[*k+1][*j]>matriz[*k+1][*j+1]){
        *soma+=matriz[*k+1][*j];
        matriz[*k][*j]=-1;
        *k=*k+1;
    }
    else if(matriz[*k+1][*j+1]>matriz[*k][*j+1] && matriz[*k+1][*j+1]>matriz[*k+1][*j]){
        *soma+=matriz[*k+1][*j+1];
        matriz[*k][*j]=-1;
        *k=*k+1;
        *j=*j+1;
    }

    if(*k == *j){
        matriz[*k][*j]=-1;
    }

}


void Caminho2(int** matriz, int *k,int* j,int* soma){

    if(matriz[*k+1][*j]>matriz[*k][*j-1] && matriz[*k+1][*j]>matriz[*k+1][*j-1]){
        *soma+=matriz[*k+1][*j];
        matriz[*k][*j]=-1;
        *k=*k+1;
    }
    else if(matriz[*k][*j-1]>matriz[*k+1][*j] && matriz[*k][*j-1]>matriz[*k+1][*j-1]){
        *soma+=matriz[*k][*j-1];
        matriz[*k][*j]=-1;
        *j=*j-1;
    }
    else if(matriz[*k+1][*j-1]>matriz[*k+1][*j] && matriz[*k+1][*j-1]>matriz[*k][*j-1]){
        *soma+=matriz[*k+1][*j-1];
        matriz[*k][*j]=-1;
        *j=*j-1;
        *k=*k+1;
    }

    if(*k == *j){
        matriz[*k][*j]=-1;
    }
}

void Caminho3(int** matriz, int *k,int* j,int* soma){
//caminho direito-> matriz[*k][*j+1]
//caminho esquerdo-> matriz[*k][*j-1]
//para baixo_>matriz[*k+1][*j]
//diagonal direita matriz[*k+1][*j+1]
//diagonal esquerda matriz[*k+1][*j-1]

    if(matriz[*k+1][*j]>matriz[*k+1][*j-1] && matriz[*k+1][*j]>matriz[*k+1][*j+1] && matriz[*k+1][*j]>matriz[*k][*j-1] && matriz[*k+1][*j]>matriz[*k][*j+1] ){
       
        *soma+=matriz[*k+1][*j];
        matriz[*k][*j]=-1;
        *k=*k+1;
    }
    else if(matriz[*k][*j-1]>matriz[*k+1][*j-1] && matriz[*k][*j-1]>matriz[*k+1][*j+1] && matriz[*k][*j-1]>matriz[*k+1][*j] && matriz[*k][*j-1]>matriz[*k][*j+1] ){
        
        *soma+=matriz[*k][*j-1];
        matriz[*k][*j]=-1;
        *j=*j-1;

    }
    else if(matriz[*k][*j+1]>matriz[*k+1][*j-1] && matriz[*k][*j+1]>matriz[*k+1][*j+1] && matriz[*k][*j+1]>matriz[*k+1][*j] && matriz[*k][*j+1]>matriz[*k][*j-1]){
        
        *soma+=matriz[*k][*j+1];
        matriz[*k][*j]=-1;
        *j=*j+1;
        
    }
   else if(matriz[*k+1][*j-1] > matriz[*k][*j+1] && matriz[*k+1][*j-1] > matriz[*k][*j-1] && matriz[*k+1][*j-1] > matriz[*k+1][*j] && matriz[*k+1][*j-1] > matriz[*k+1][*j+1]){
    *soma += matriz[*k+1][*j-1];
    matriz[*k][*j] = -1;
    *k = *k + 1;
    *j = *j - 1;
    }

    else if(matriz[*k+1][*j+1]>matriz[*k+1][*j-1] && matriz[*k+1][*j+1]>matriz[*k+1][*j] && matriz[*k+1][*j+1]>matriz[*k][*j-1] && matriz[*k+1][*j+1]>matriz[*k][*j+1]){
        
        *soma+=matriz[*k+1][*j+1];
        matriz[*k][*j]=-1;
        *k=*k+1;
        *j=*j+1;
    }

    if(*k == *j){
        matriz[*k][*j]=-1;
    }


}