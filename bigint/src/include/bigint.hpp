#ifndef BIGINT_HPP__
#define BIGINT_HPP__

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#define CASA_DECIMAL 10

// 1,0136128201749495727621962962588
// 1,013612820174949572762196296258755080734261126934733470508934997

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
    BigInt operator/(const BigInt &obj);

    string getVal() { return (this->val_); }
    decltype(auto) getVec() { return (this->vec_); }

    void soma(const string &v1, const string &v2, string &res);
    void sub(const vector<int> &v1, const vector<int> &v2, string &res);
    void mult(const vector<int> &v1, const vector<int> &v2, string &res);
    void div(const string &v1, const string &v2, string &res);

    void printVal(const string &v1, const string &v2);

    void strip(std::string &str) {
        if (str.length() == 0) return;

        auto start_it = str.begin();
        auto end_it = str.rbegin();
        while (std::isspace(*start_it)) {
            ++start_it;
            if (start_it == str.end()) break;
        }
        while (std::isspace(*end_it)) {
            ++end_it;
            if (end_it == str.rend()) break;
        }
        int start_pos = start_it - str.begin();
        int end_pos = end_it.base() - str.begin();
        str = start_pos <= end_pos ? std::string(start_it, end_it.base()) : "";
    }
};

#endif