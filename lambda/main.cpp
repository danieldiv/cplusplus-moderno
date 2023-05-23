#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;

int main() {
    std::vector<std::string>pessoas = { "alex", "daniel","gabriel","gustavo","yuri" };
    std::vector<double> alturas = { 1.75, 1.80, 1.65, 1.70, 1.90 };
    std::vector<int> idx = { 0, 1, 2, 3, 4 };

    // std::sort(idx.begin(), idx.end(), [&alturas](int a, int b) { return alturas[a] < alturas[b]; });

    auto comp = [&alturas](int a, int b) { return alturas[a] < alturas[b]; };
    std::sort(idx.begin(), idx.end(), comp);

    for (auto i : idx)
        cout << pessoas[i] << " " << alturas[i] << endl;

    return 0;
}