#include <iostream>
#include <cstdlib>
#include <csignal>

void handlerFinish(int sig) {
    std::cout << std::endl;
    exit(EXIT_SUCCESS);
}

void handler(int sig) {
    std::cout << "\nPara encerrar, pressione Ctrl + C novamente" << std::endl;
    signal(SIGINT, handlerFinish);
}

int main() {
    std::cout << "Tente encerrar esse processo..." << std::endl;

    signal(SIGINT, handler);

    while (true) { }
    return 0;
}