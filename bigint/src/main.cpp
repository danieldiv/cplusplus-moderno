#include <iostream>
#include <string>
#include <vector>

#include "include/bigint.hpp"
#include "include/racional.hpp"

void MDC(int num1, int num2) {
    while (num1 != num2) {
        if (num1 > num2) {
            num1 = num1 - num2;
        } else {
            num2 = num2 - num1;
        }
    }

    cout << num1 << endl;
}

int main() {
    cout << "BigInt" << endl << endl;
    BigInt a("234");
    BigInt b("852");

    BigInt sum1 = a + b;
    cout << "[+] " << sum1.getVal() << endl;

    BigInt sum2 = b + a;
    cout << "[+] " << sum2.getVal() << endl;

    BigInt sub1 = a - b;
    cout << "[-] " << sub1.getVal() << endl;

    BigInt sub2 = b - a;
    cout << "[-] " << sub2.getVal() << endl;

    BigInt mult1 = a * b;
    cout << "[*] " << mult1.getVal() << endl;

    BigInt mult2 = b * a;
    cout << "[*] " << mult2.getVal() << endl;

    BigInt div1 = a / b;
    cout << "[/] " << div1.getVal() << endl;

    BigInt div2 = b / a;
    cout << "[/] " << div2.getVal() << endl;

    cout << "\nRacional" << endl << endl;

    Racional r1;
    Racional r2(26, 30);
    Racional r3(r2);
    Racional r4(std::move(r2));
    Racional r5(Racional(98, 56));
    Racional r6(std::move(Racional(890, 45)));
    Racional r7 = r3;
    Racional *r8 = new Racional(45, 89);
    Racional r9 = std::move(r7);

    r1.imprimir(1);
    r2.imprimir(2);
    r3.imprimir(3);
    r4.imprimir(4);
    r5.imprimir(5);
    r6.imprimir(6);
    r7.imprimir(7);
    (*r8).imprimir(8);
    r9.imprimir(9);

    return 0;
}