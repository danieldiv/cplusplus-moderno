#include <iostream>
#include <string.h>
#include <string>

using namespace std;

template<typename T>
void troca(T &x, T &y) {
    T aux = x;
    x = y;
    y = aux;
}

template<typename T>
void troca(T *x, T *y) {
    cout << "template" << endl;
    T aux = *x;
    *x = *y;
    *y = aux;
}

template<>
void troca(char *&x, char *&y) {
    cout << "especializacao" << endl;
    for (int i = 0; i < strlen(x); i++)
        troca(x[i], y[i]);
}

int main() {
    string t1 = "daniel";
    string t2 = "ealves";

    if (t1 > t2)
        cout << "daniel maior que alves" << endl;
    else
        cout << "daniel menor que alves" << endl << endl;

    char c1 [] = "eu";
    char c2 [] = "na";

    if (c1 < c2)
        cout << "c1 maior que c2" << endl;
    else
        cout << "c1 menor que c2" << endl;

    return 0;

    int t = 0;

    if (t) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;

    string a1 = "10";
    string b2 = "eu";

    string x = a1 + b2;

    cout << x << endl;

    int a = 42, b = 7;

    cout << a << " " << b << endl;
    troca(a, b);
    cout << a << " " << b << endl;

    char str1 [] = "daniel";
    char str2 [] = "alvess";

    char *p1 = str1;
    char *p2 = str2;

    cout << str1 << " " << str2 << endl;
    troca<char *>(p1, p2);
    cout << str1 << " " << str2 << endl;

    return 0;
}