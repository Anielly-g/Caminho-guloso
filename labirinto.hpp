#ifndef LABIRINTO_HPP 
#define LABIRINTO_HPP
#include <fstream>
using namespace std;


void GerarMatriz(ifstream& input);
void Caminhar(int** matriz,int N, int ContarMatriz, int* soma);
void Caminho0(int** matriz, int *k,int* j,int* soma);
void Caminho1(int** matriz, int* k, int* j,int* soma);
void Caminho2(int** matriz, int *k,int* j,int* soma);
void Caminho3(int** matriz, int *k,int* j,int* soma);

#endif