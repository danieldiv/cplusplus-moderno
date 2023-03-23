#include "seletor.hpp"

enum class Tipos { STRING, INT, DOUBLE, FLOAT, BOOL, CHAR, SAIR, NONE };

string tp;

int menuTipo();

Tipos checkOpcao(int op);

int main() {
    Tipos op_tipo;

    while (op_tipo = checkOpcao(menuTipo()), op_tipo != Tipos::SAIR) {
        if (op_tipo == Tipos::STRING) {
            Seletor<string> sel(tp);
            sel.leituraOpcoes();
        } else  if (op_tipo == Tipos::INT) {
            Seletor<int> sel(tp);
            sel.leituraOpcoes();
        } else  if (op_tipo == Tipos::DOUBLE) {
            Seletor<double> sel(tp);
            sel.leituraOpcoes();
        } else  if (op_tipo == Tipos::FLOAT) {
            Seletor<float> sel(tp);
            sel.leituraOpcoes();
        } else  if (op_tipo == Tipos::BOOL) {
            Seletor<bool> sel(tp);
            sel.leituraOpcoes();

        } else  if (op_tipo == Tipos::CHAR) {
            Seletor<char> sel(tp);
            sel.leituraOpcoes();
        } else  if (op_tipo == Tipos::NONE) {
            cout << "Opcao invalida" << endl;
        }
        system("read -p \"\nPressione enter para continuar...\" continue");
    }
    return EXIT_SUCCESS;
}

int menuTipo() {
    int op;

    system("clear");
    cout << "================" << endl;
    cout << "   MENU TIPOS" << endl;
    cout << "================" << endl << endl;

    cout << "[1] String" << endl;
    cout << "[2] Int" << endl;
    cout << "[3] Double" << endl;
    cout << "[4] Float" << endl;
    cout << "[5] Bool" << endl;
    cout << "[6] Char" << endl;
    cout << "\n[0] Sair" << endl;

    cout << "\nEscolha uma opcao: ";
    cin >> op;

    return op;
}

Tipos checkOpcao(int op) {
    switch (op) {
    case 0: return Tipos::SAIR;
    case 1: tp.assign("STRING"); return Tipos::STRING;
    case 2: tp.assign("INT"); return Tipos::INT;
    case 3: tp.assign("DOUBLE"); return Tipos::DOUBLE;
    case 4: tp.assign("FLOAT"); return Tipos::FLOAT;
    case 5: tp.assign("BOOL"); return Tipos::BOOL;
    case 6: tp.assign("CHAR"); return Tipos::CHAR;
    default: return Tipos::NONE;
    }
}