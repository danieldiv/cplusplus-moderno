#ifndef BIGINT_HPP__
#define BIGINT_HPP__

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class BigInt {
private:
    string val_;
    vector<int> vec_;
public:
    BigInt() : val_("") { }
    BigInt(string val) : val_(val) { init(); }
    BigInt(const BigInt &obj);

    void init();

    BigInt operator+(const BigInt &obj);
    BigInt operator-(const BigInt &obj);
    BigInt operator*(const BigInt &obj);

    string getVal() { return (this->val_); }
    decltype(auto) getVec() { return (this->vec_); }

    void soma(const string &v1, const string &v2, string &res);
    void sub(const vector<int> &v1, const vector<int> &v2, string &res);
    void mult(const vector<int> &v1, const vector<int> &v2, string &res);

    void printVal(const string &v1, const string &v2);
};

#endif