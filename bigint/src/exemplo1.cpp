// #include <sys/resource.h>

// #include <iostream>
// #include <string>
// #include <vector>

// using std::cout;
// using std::endl;

// // template<class T>
// // void swap(T &a, T &b) {
// //     T temp(a); // faz copia de a para temp
// //     a = b; // faz copia de b para a
// //     b = temp; // faz copia de temp para b
// // }

// template<class T>
// void swap(T &a, T &b) {
//     T c { std::move(a) }; // evita copia temporaria de a para temp
//     a = std::move(b); // evita copia temporaria de b para a
//     b = std::move(c); // evita copia temporaria de temp para b
// }

// int main() {
//     int a = 10;
//     int b = 20;

//     cout << a << " " << b << endl;
//     swap(a, b);
//     cout << a << " " << b << endl;

//     struct rusage rusage;
//     getrusage(RUSAGE_SELF, &rusage);
//     std::cout << "Memória residente (KB): " << rusage.ru_maxrss << " (MB): " << rusage.ru_maxrss / 1024 << std::endl;

//     // string s(10, 'a');
//     // string z = s;

//     // cout << s << endl;
//     // cout << z << endl;


//     return 0;
// }

// // // #include "include/bigint.hpp"

// // // int main() {
// // //     BigInt a("234");
// // //     BigInt b("852");

// // //     BigInt sum1 = a + b;
// // //     cout << "[+] " << sum1.getVal() << endl;

// // //     BigInt sum2 = b + a;
// // //     cout << "[+] " << sum2.getVal() << endl;

// // //     BigInt sub1 = a - b;
// // //     cout << "[-] " << sub1.getVal() << endl;

// // //     BigInt sub2 = b - a;
// // //     cout << "[-] " << sub2.getVal() << endl;

// // //     BigInt mult1 = a * b;
// // //     cout << "[*] " << mult1.getVal() << endl;

// // //     BigInt mult2 = b * a;
// // //     cout << "[*] " << mult2.getVal() << endl;

// // //     BigInt div1 = a / b;
// // //     cout << "[/] " << div1.getVal() << endl;

// // //     BigInt div2 = b / a;
// // //     cout << "[/] " << div2.getVal() << endl;

// // //     return 0;
// // // }


// #include <iostream>
// #include <sys/resource.h>
// #include <vector>

// using std::cout;
// using std::endl;

// class Buffer {
// private:
//     char *data_;
//     std::size_t size_;
// public:
//     Buffer() : data_(nullptr), size_(0) { }
//     Buffer(std::size_t size) : data_(data_ = new char[size_]), size_(size) { }

//     Buffer(Buffer &&other) : data_(nullptr), size_(0) {
//         *this = std::move(other);
//     }
//     ~Buffer() { delete [] data_; }

//     Buffer &operator=(Buffer &&other) {
//         if (this != &other) {
//             delete [] data_;
//             data_ = other.data_;
//             size_ = other.size_;
//             other.data_ = nullptr;
//             other.size_ = 0;
//         }
//         return *this;
//     }

//     std::size_t size() const { return size_; }
//     char *data() const { return data_; }

//     void swap(Buffer &first, Buffer &second) {
//         using std::swap;
//         swap(first.data_, second.data_);
//         swap(first.size_, second.size_);
//     }
// };

// void swap(Buffer &first, Buffer &second) {
//     first.swap(first, second);
// }

// #include <chrono>
// #include <ctime>
// #include <ratio>

// using std::cout;
// using std::endl;
// using namespace std::chrono;

// steady_clock::time_point t1;
// steady_clock::time_point t2;

// void getUsage();

// int main() {
//     std::vector<Buffer> buffers;
//     buffers.push_back(Buffer(100)); // transferencia

//     Buffer b(200);
//     // buffers.push_back(b); // copia
//     buffers.push_back(std::move(b)); // transferencia


//     // Buffer b1(100);
//     // Buffer b2(200);

//     // cout << "b1 size: " << b1.size() << endl;

//     // swap(b1, b2);

//     // cout << "b1 size: " << b1.size() << endl;

//     // getUsage();

//     return 0;
// }

// void getUsage() {
//     struct rusage rusage;
//     getrusage(RUSAGE_SELF, &rusage);
//     cout << "Memória residente (KB): " << rusage.ru_maxrss << " (MB): " << rusage.ru_maxrss / 1024 << endl;
// }