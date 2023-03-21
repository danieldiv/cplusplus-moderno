#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> foo = { 5,6 };

    for (auto v : foo) cout << v << " ";
    cout << endl;

    return 0;
}