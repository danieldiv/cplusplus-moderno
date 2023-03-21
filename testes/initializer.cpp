#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Foo {
    int a_;
    int b_;
    std::vector<std::vector<int>> vec;

public:
    Foo(): a_(0), b_(0) {
        std::cout << "invocando Foo()" << std::endl;
    }

    Foo(int a, int b = 0): a_(a), b_(b) {
        std::cout << "invocando Foo(int, int)" << std::endl;
    }

    Foo(std::initializer_list<int> l) {
        std::cout << "Invocando Foo(std::initializer_list<int>)" << std::endl;
    }

    Foo(std::initializer_list<std::initializer_list<int>> l) {
        std::cout << "Invocando Foo(std::initializer_list<std::initializer_list<int>>)" << std::endl;

        for (auto v : l) vec.emplace_back(v);

        // for (auto v1 : vec) {
        //     for (auto v2 : v1) {
        //         cout << v2 << " ";
        //     }
        //     cout << endl;
        // }

    }

    static void teste(int i) {
        cout << i << endl;
    }
};

int main() {
    Foo f0;
    Foo f1 {};
    Foo f2 { 1,2 };
    Foo f3(1, 2);
    Foo f4 { 42 };
    Foo f5(42);
    Foo f6 { {1,2,4,3},{5,6,7},{7,8,9} };

    Foo f;


    return 0;
}