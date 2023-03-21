#include <iostream>

// using namespace std; almenta apenas uma linha no arquivo .ii

int main(int argc, char **argv) {

    std::cout << "Ola mundo!" << std::endl;

    return 0;
}

// assember -> montador
// assembly -> linguagem

// -E pre processamento
// -P tira os comentarios 

// -S faz o processo gerar apoz gerar o codigo assembly
// g++ -S -o program.s program.cpp

// gera o codigo objeto
// g++ -c -o program.o program.cpp 