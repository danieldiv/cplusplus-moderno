#include <iostream>
#include <fstream>
#include <string>

void readFile(std::string origem, std::string destino) {
    std::ifstream myfile(origem);
    std::ofstream out(destino);

    std::string line;

    if (myfile.is_open()) {
        while (getline(myfile, line))
            out << line << std::endl;
        myfile.close();
        out.close();
    } else std::cout << "Nao foi possivel abrir o arquivo" << std::endl;
}