#include "bigint.hpp"
#include <bitset>

int main() {
    BigInt a("100");
    BigInt b("21");

    // BigInt c = a + b;
    // cout << "+\n" << c.getVal() << endl << endl;

    BigInt d = a - b;
    cout << "-\n" << d.getVal() << endl;

    return 0;
}