#include <iostream>
#include "labirinto.hpp"

using namespace std;

int main() {

    ifstream input;
    input.open("input.data",std::ios::in);
    
    LerMatriz(input);


    return 0;
}




