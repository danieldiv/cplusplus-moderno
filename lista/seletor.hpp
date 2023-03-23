#ifndef SELETOR_HPP__
#define SELETOR_HPP__

#include <iostream>
#include <string>

#include "lista.hpp"

using namespace std;

template<typename T>
class Seletor {
private:
    string tipo_;
    Lista<T> lista_;
public:
    Seletor(string tipo):tipo_(tipo) { }

    void leituraOpcoes();
    void leituraEntrada();
    int menuOpcao();

    string getTipo() { return tipo_; }
};

template<typename T>
void Seletor<T>::leituraOpcoes() {
    int op;

    while (op = menuOpcao(), op != 0) {
        if (op == 1) {

        } else if (op == 2) {
            size_t pos;

            cout << "Informe a posicao para remover: ";
            cin >> pos;

            try {
                lista_.remover(pos);
            } catch (std::string &res) {
                cout << res << endl;
            }
        } else if (op == 3) {
            size_t pos;

            cout << "Informe a posicao para buscar: ";
            cin >> pos;

            try {
                cout << lista_.buscar(pos);
            } catch (std::string &res) {
                cout << res << endl;
            }
        } else {
            cout << "Opcao invalida" << endl;
        }
        system("read -p \"\nPressione enter para continuar...\" continue");
    }
}

template<typename T>
void Seletor<T>::leituraEntrada() {

}

template<>
void Seletor<std::string>::leituraEntrada() {

}

// template<>
// void Seletor<string>::leituraOpcoes() {
//     int op;

//     while (op = menuOpcao(), op != 0) {
//         system("read -p \"\nPressione enter para continuar...\" continue");
//     }
//     // string str;

//     // cin.ignore();
//     // getline(cin, str);
// }

template<typename T>
int Seletor<T>::menuOpcao() {
    int op;

    system("clear");
    cout << getTipo() << endl;
    cout << "================" << endl;
    cout << "   MENU OPCOES" << endl;
    cout << "================" << endl << endl;

    cout << "[1] Inserir" << endl;
    cout << "[2] Remover" << endl;
    cout << "[3] Buscar" << endl;
    cout << "\n[0] Voltar" << endl;

    cout << "\nEscolha uma opcao: ";
    cin >> op;

    return op;
}

#endif