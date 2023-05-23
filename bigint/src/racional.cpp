#include "include/racional.hpp"

int Racional::mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Racional::mmc(int a, int b) {
    int mdc_ = this->mdc(a, b);
    int mmc_ = (a * b) / mdc_;
    return mmc_;
}

// relacionais
bool Racional::operator<(const Racional &racional) {
    auto aux = (double)racional.numerador_ / (double)racional.denominador_;
    return (this->valor() < aux);
}

bool Racional::operator<=(const Racional &racional) {
    auto aux = (double)racional.numerador_ / (double)racional.denominador_;
    return (this->valor() <= aux);
}

bool Racional::operator>(const Racional &racional) {
    auto aux = (double)racional.numerador_ / (double)racional.denominador_;
    return (this->valor() > aux);
}

bool Racional::operator>=(const Racional &racional) {
    auto aux = (double)racional.numerador_ / (double)racional.denominador_;
    return (this->valor() >= aux);
}

bool Racional::operator==(const Racional &racional) {
    auto aux = (double)racional.numerador_ / (double)racional.denominador_;
    return (this->valor() == aux);
}

// aritmeticos
const Racional Racional::operator+(const Racional &racional) {
    auto mmc = this->mmc(this->getDenominador(), racional.denominador_);
    auto num = (mmc / this->getDenominador()) * this->getNumerador()
        + ((mmc / racional.denominador_) * racional.numerador_);
    auto den = mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return Racional(num, den);
}

const Racional Racional::operator-(const Racional &racional) {
    auto mmc = this->mmc(this->getDenominador(), racional.denominador_);
    auto num = (mmc / this->getDenominador()) * this->getNumerador()
        - ((mmc / racional.denominador_) * racional.numerador_);
    auto den = mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return Racional(num, den);
}

const Racional Racional::operator*(const Racional &racional) {
    auto num = this->getNumerador() * racional.numerador_;
    auto den = this->getDenominador() * racional.denominador_;

    // no retorno n se utiliza std::move por causa de otimizacao
    return Racional(num, den);
}

const Racional Racional::operator/(const Racional &racional) {
    auto num = this->getNumerador() * racional.denominador_;
    auto den = this->getDenominador() * racional.numerador_;

    return Racional(num, den);
}

Racional Racional::operator+=(const Racional &racional) {
    auto mmc = this->mmc(this->getDenominador(), racional.denominador_);
    this->numerador_ = (mmc / this->getDenominador()) * this->getNumerador()
        + ((mmc / racional.denominador_) * racional.numerador_);
    this->denominador_ = mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return *this;
}

Racional Racional::operator-=(const Racional &racional) {
    auto mmc = this->mmc(this->getDenominador(), racional.denominador_);
    this->numerador_ = (mmc / this->getDenominador()) * this->getNumerador()
        - ((mmc / racional.denominador_) * racional.numerador_);
    this->denominador_ = mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return *this;
}

Racional Racional::operator*=(const Racional &racional) {
    this->numerador_ *= racional.numerador_;
    this->denominador_ *= racional.denominador_;
    return *this;
}

Racional Racional::operator/=(const Racional &racional) {
    auto num = this->getNumerador() * racional.denominador_;
    auto den = this->getDenominador() * racional.numerador_;

    this->numerador_ = num;
    this->denominador_ = den;

    return *this;
}

Racional Racional::operator++() {
    auto mmc = this->mmc(this->getDenominador(), 1);
    this->numerador_ += mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return *this;
}

Racional Racional::operator++(int) {
    auto mmc = this->mmc(this->getDenominador(), 1);
    this->numerador_ += mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return *this;
}

Racional Racional::operator--() {
    auto mmc = this->mmc(this->getDenominador(), 1);
    this->numerador_ -= mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return *this;
}

Racional Racional::operator--(int) {
    auto mmc = this->mmc(this->getDenominador(), 1);
    this->numerador_ -= mmc;

    if (this->getNumerador() == 0)this->denominador_ = 1;
    return *this;
}

Racional Racional::operator-() {
    this->numerador_ *= -1;
    return *this;
}

void Racional::simplificar() {
    bool aux = false;
    if (this->getNumerador() < 0) {
        aux = true;
        this->numerador_ *= -1;
    }

    int mdc = this->mdc(this->numerador_, this->denominador_);
    this->numerador_ /= mdc;
    this->denominador_ /= mdc;

    if (aux) this->numerador_ *= -1;
}

void Racional::imprimir(const std::string &n) {
    std::cout << n << ": ";
    std::cout <<
        getNumerador() << "/" <<
        getDenominador() << " = " <<
        valor() << " -> " <<
        getTipo() << std::endl;
}