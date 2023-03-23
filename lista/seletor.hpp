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
    T leituraEntrada();
    int menuOpcao();
    int menuLeitura();

    string getTipo() { return tipo_; }
};

template<typename T>
void Seletor<T>::leituraOpcoes() {
    int op;

    while (op = menuOpcao(), op != 0) {
        if (op == 1) {
            int tipoInsercao = menuLeitura();

            if (tipoInsercao == 1) {
                lista_.insert(leituraEntrada());
            } else if (tipoInsercao == 2) {
                lista_.push_back(leituraEntrada());
            } else if (tipoInsercao == 3) {
                size_t pos;

                cout << "Informe a posicao: ";
                cin >> pos;

                lista_.insert(pos, leituraEntrada());
            }
        } else if (op == 2) {
            if (lista_.isEmpity()) {
                cout << "Lista vazia" << endl;
            } else {
                size_t pos;

                lista_.imprime();
                cout << endl;

                cout << "Informe a posicao para remover: ";
                cin >> pos;

                try {
                    cout << endl;
                    lista_.remover(pos);
                } catch (std::string &res) {
                    cout << res << endl;
                }
            }
        } else if (op == 3) {
            if (lista_.isEmpity()) {
                cout << "Lista vazia" << endl;
            } else {
                size_t pos;

                cout << "Informe a posicao para buscar: ";
                cin >> pos;

                try {
                    cout << lista_.buscar(pos) << endl;
                } catch (std::string &res) {
                    cout << res << endl;
                }
            }
        } else if (op == 4) {
            lista_.imprime();
            lista_.imprimeReverse();
        } else {
            cout << "Opcao invalida" << endl;
        }
        system("read -p \"\nPressione enter para continuar...\" continue");
    }
}

template<typename T>
T Seletor<T>::leituraEntrada() {
    T val;

    cout << "Informe o valor para inserir: ";

    cin >> val;
    return val;
}

template<>
string Seletor<std::string>::leituraEntrada() {
    string val;
    cin.ignore();

    cout << "Informe o valor para inserir: ";

    getline(cin, val);
    return val;
}

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
    cout << "[4] Imprimir" << endl;
    cout << "\n[0] Voltar" << endl;

    cout << "\nEscolha uma opcao: ";
    cin >> op;

    return op;
}

template<typename T>
int Seletor<T>::menuLeitura() {
    cout << endl;
    cout << "[1] Inicio" << endl;
    cout << "[2] Fim" << endl;
    cout << "[3] Escolher local" << endl << endl;

    cout << "Escolha onde deseja inserir: ";

    int tipoInsercao;
    cin >> tipoInsercao;

    return tipoInsercao;
}

#endif