#include <iostream>
#include "weight.hpp"

using namespace std;

int main() {
    Weight w1 = 200.0_g; // 200.g eh igual
    Weight w2 = 200.0_Kg;
    Weight w3(300);
    Weight w4(300.0_g);
    Weight w5(400.0_Kg);

    cout << w1.get() << endl;
    cout << w2.get() << endl;
    cout << w3.get() << endl;
    cout << w4.get() << endl;
    cout << w5.get() << endl;

    return 0;
}