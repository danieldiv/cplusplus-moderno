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
    BigInt a("25");
    BigInt b("15");

    BigInt sum1 = a + b + a;
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

    r1.imprimir("r1");
    r2.imprimir("r2");
    r3.imprimir("r3");
    r4.imprimir("r4");
    r5.imprimir("r5");
    r6.imprimir("r6");
    r7.imprimir("r7");
    (*r8).imprimir("r8");
    r9.imprimir("r9");

    bool res1 = (r2 < (*r8));
    bool res2 = (r2 <= r3);
    bool res3 = (r2 > (*r8));
    bool res4 = (r2 >= r3);
    bool res5 = (r2 == r3);
    bool res6 = (r6 == r9);

    cout << endl;
    cout << "r2 <  r8 = " << res1 << endl;
    cout << "r2 <= r3 = " << res2 << endl;
    cout << "r2 >= r3 = " << res2 << endl;
    cout << "r2 >  r8 = " << res3 << endl;
    cout << "r2 == r3 = " << res5 << endl;
    cout << "r6 == r9 = " << res6 << endl;

    Racional mult = r2 * r3;
    Racional div = r5 / r7;

    cout << endl;
    mult.imprimir("mult");
    div.imprimir("div");

    r5 *= r7;
    r9 /= r5;
    r2 /= r2;

    r5.imprimir("r5 *= r7");
    r9.imprimir("r9 /= r5");
    r2.imprimir("r2 /= r2");

    -r5;
    -r2;

    r5.imprimir("-r5");
    r2.imprimir("-r2");

    ++r9;
    ++r2;

    r9.imprimir("++r9");
    r2.imprimir("++r2");

    Racional test = r2++;
    test.imprimir("test++");

    Racional test2 = ++(++(++r2));
    test2.imprimir("test2++");

    test2 = --(--(--r2));
    test2.imprimir("test2--");

    r6.imprimir("r6");
    r6--;
    r6.imprimir("r6--");

    cout << endl;
    Racional r10(std::move(Racional(1, 3)));
    Racional r11(std::move(Racional(2, 5)));

    r10.imprimir("r10");
    r11.imprimir("r11");

    Racional r12 = r10 + r11;
    r12.imprimir("r12");

    Racional r13 = r10 - r11;
    r13.imprimir("r13");

    r13 += r10;
    r13.imprimir("r13 += r10");

    r13 -= r10;
    r13.imprimir("r13 -= r10");

    return 0;
}