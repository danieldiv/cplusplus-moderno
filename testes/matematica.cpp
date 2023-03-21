#include <iostream>
#include <climits>
#include <cfloat>
#include <vector>

#define tipo initializer_list<int>

using namespace std;

class Matematica {
private:
    int val_;
public:
    Matematica(): val_(0) { }

    int minimo(tipo il);
    int maximo(tipo il);
    int soma(tipo il);
};

int Matematica::minimo(tipo il) {
    this->val_ = INT_MAX;
    for (auto v : il) this->val_ = (this->val_ > v) ? v : this->val_;
    return this->val_;
}

int Matematica::maximo(tipo il) {
    this->val_ = INT_MIN;
    for (auto v : il) this->val_ = (this->val_ > v) ? this->val_ : v;
    return this->val_;
}

int Matematica::soma(tipo il) {
    for (auto v : il) this->val_ += v;
    return this->val_;
}

int main() {
    Matematica m;

    cout << m.minimo({ -1000,2,-123,4,5 }) << endl;
    cout << m.maximo({ 100,29,3,4,5 }) << endl;
    cout << m.soma({ 1,2,3,4,5 }) << endl;

    vector<int>vec = { 1,2,3 };
    vector<int>::iterator it;

    for (auto v : vec) {
        cout << v << " ";
    }
    cout << endl;

    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;

    return 0;
}