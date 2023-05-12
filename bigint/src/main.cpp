#include "include/bigint.hpp"

int main() {
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

    return 0;
}
