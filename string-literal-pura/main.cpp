#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string str_1 = R"(teste\n)";
    string str_2 = R"(
    #include
    int main() {
    teste
    }
    )";

    string str_euro_8 = "o simbolo \u20AC em UTF-8";
    u16string str_euro_16 = u"o simbolo \u20AC em UTF-16"; // char 16_t
    u32string str_euro_32 = U"o simbolo \u20AC em UTF-32"; // char 32_t

    cout << str_1 << endl;
    cout << str_2 << endl;
    cout << str_euro_8 << " " << str_euro_8.size() << endl;
    cout << str_euro_16.size() << endl;
    cout << str_euro_32.size() << endl;

    string nome = "andré";
    u16string nome16 = u"andré";
    u32string nome32 = U"andré";

    cout << nome << endl;
    cout << reinterpret_cast<const char *>(nome.c_str()) << endl << endl;

    cout << endl << nome.size() << endl;
    cout << nome16.size() << endl;
    cout << nome32.size() << endl << endl;

    // u8string str = u8R"(
    // void f() {
    // std::cout << "\U0001F600" << std::endl;
    // }
    // )";
    // std::cout << reinterpret_cast<const char *>(str.c_str()) << std::endl;


    return 0;
}