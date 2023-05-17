#ifndef RACIONAL_HPP
#define RACIONAL_HPP

#include <iostream>
#include <string>

#define dbg(x) std::cout << #x << " = " << x << std::endl

class Racional {
private:
    int numerador_;
    int denominador_;
    std::string tipo_;
public:
    Racional() : numerador_(0), denominador_(1), tipo_("zero") { }

    Racional(int numerador, int denominador) {
        numerador_ = numerador;
        denominador_ = denominador;
        tipo_ = "copia inteiro";
        simplificar();
    }

    Racional(const Racional &racional) {
        numerador_ = racional.numerador_;
        denominador_ = racional.denominador_;
        tipo_ = "copia lvalue";
    }

    Racional(Racional &&other)
        : numerador_(0), denominador_(1) {
        *this = std::move(other);
    }

    Racional operator=(Racional &&other) {
        if (this != &other) {
            numerador_ = other.numerador_;
            denominador_ = other.denominador_;
        }
        tipo_ = "transferencia rvalue";
        return *this;
    }

    ~Racional() { } // Destrutor

    // relacionais
    bool operator<(const Racional &racional);
    bool operator<=(const Racional &racional);
    bool operator>(const Racional &racional);
    bool operator>=(const Racional &racional);
    bool operator==(const Racional &racional);

    // aritmeticos
    Racional operator+(const Racional &racional);
    Racional operator-(const Racional &racional);
    Racional operator*(const Racional &racional);
    Racional operator/(const Racional &racional);
    Racional operator+=(const Racional &racional);
    Racional operator-=(const Racional &racional);
    Racional operator*=(const Racional &racional);
    Racional operator/=(const Racional &racional);
    Racional operator++();
    Racional operator-();

    const int &getNumerador() { return numerador_; }
    const int &getDenominador() { return denominador_; }

    void setNumerador(int numerador) { this->numerador_ = numerador; }
    void setDenominador(int denominador) { this->denominador_ = denominador; }

    const double valor() { return (double)numerador_ / denominador_; }
    const std::string &getTipo() { return tipo_; }

    int mdc(int a, int b);

    void simplificar();
    void imprimir(int n);
};

#endif