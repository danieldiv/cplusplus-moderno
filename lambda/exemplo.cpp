// #include <iostream>
// #include <vector>
// #include <algorithm>

// // template <typename F, typename T>
// // void g(F f, T a, T b) {
// //     f(a, b);
// // }

// // void soma(int a, int b) {
// //     cout << a + b << endl;
// // }

// using std::cout;
// using std::endl;

// // bool compare(int a, int b) {
// //     return a > b;
// // }

// int main() {
//     int x = 0;
//     double y = 0.0;

//     auto f = [z = x, &w = y]() mutable { //x = copia, y = referencia, mutable faz uma copia para utilizar apenas na funcoa lambda
//         z++; // copia
//         ++w; // referencia de y
//     };
//     f();

//     auto g = [=]() mutable { // = captura tudo por copia
//         ++x;
//         ++y;
//     };

//     auto h = [&]() { // = captura tudo por referencia
//         ++x;
//         ++y;
//     };

//     h();

//     cout << x << endl;
//     cout << y << endl;


//     // std::vector<int> v = { 35, 62, 3, 1, 7, 9, 10, 2, 4, 5, 6, 8 };
//     // std::sort(v.begin(), v.end(), compare);
//     // std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

//     // for (auto x : v) {
//     //     cout << x << " ";
//     // }
//     // cout << endl;

//     // g(soma, 1, 2); // g(soma<int, int>, 1, 2
//     // g([](int x, int y) { cout << x + y << endl; }, 5, 7); // g(lambda, 5, 7)

//     // auto f = [](int x, int y) { cout << x + y << endl; };
//     // g(f, 5, 7); // g(lambda, 5, 7)

//     return 0;
// }