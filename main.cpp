#include <iostream>
#include "labirinto.hpp"

using namespace std;

int main() {

    ifstream input;
    input.open("input.data",std::ios::in);
    
    GerarMatriz(input);


    return 0;
}




