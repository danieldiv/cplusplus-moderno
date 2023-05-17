#include "include/racional.hpp"

int Racional::mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// relacionais
bool Racional::operator<(const Racional &racional) {
    return true;
}

bool Racional::operator<=(const Racional &racional) {
    return true;
}

bool Racional::operator>(const Racional &racional) {
    return true;
}

bool Racional::operator>=(const Racional &racional) {
    return true;
}

bool Racional::operator==(const Racional &racional) {
    return true;
}

// aritmeticos
Racional Racional::operator+(const Racional &racional) {
    return *this;
}

Racional Racional::operator-(const Racional &racional) {
    return *this;
}

Racional Racional::operator*(const Racional &racional) {
    return *this;
}

Racional Racional::operator/(const Racional &racional) {
    return *this;
}

Racional Racional::operator+=(const Racional &racional) {
    return *this;
}

Racional Racional::operator-=(const Racional &racional) {
    return *this;
}

Racional Racional::operator*=(const Racional &racional) {
    return *this;
}

Racional Racional::operator/=(const Racional &racional) {
    return *this;
}

Racional Racional::operator++() {
    return *this;
}

Racional Racional::operator-() {
    return *this;
}

void Racional::simplificar() {
    int mdc = this->mdc(this->numerador_, this->denominador_);
    this->numerador_ /= mdc;
    this->denominador_ /= mdc;
}

void Racional::imprimir(int n) {
    std::cout << "r" << n << ": ";
    std::cout <<
        getNumerador() << "/" <<
        getDenominador() << " = " <<
        valor() << " -> " <<
        getTipo() << std::endl;
}