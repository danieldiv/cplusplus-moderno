#include "bigint.hpp"

int main() {
    BigInt a("153");
    BigInt b("125");
    BigInt novo("1");

    BigInt c = a + b + novo;
    cout << "[+] = " << c.getVal() << endl;

    // BigInt d = a - b;
    // cout << "[-] = " << d.getVal() << endl;

    BigInt f = a * b;
    cout << "[*] = " << f.getVal() << endl;

    return 0;
}