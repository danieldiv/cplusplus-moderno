#include "bigint.hpp"

BigInt::BigInt(const BigInt &obj) {
    this->val_ = obj.val_;
    init();
}

void BigInt::init() {
    for (const auto &c : val_)
        vec_.push_back(c - '0');
    // for (const auto &c : vec_)
    //     cout << c << " ";
    // cout << endl;
}

void BigInt::printVal(const string &v1, const string &v2) {
    std::stringstream ss;
    ss << std::setw(v1.size()) << std::setfill(' ') << v2;
    std::string n_zeros = ss.str();

    cout << v1 << endl;
    cout << n_zeros << endl;
}

BigInt BigInt::operator+(const BigInt &obj) {
    string res("");

    if (obj.val_.size() >= getVal().size())
        soma(obj.val_, getVal(), res);
    else
        soma(getVal(), obj.val_, res);
    return (BigInt(res));
}

BigInt BigInt::operator-(const BigInt &obj) {
    string res("");

    if (obj.val_.size() >= getVal().size()) {
        sub(obj.vec_, getVec(), res);
        res.insert(0, "-");
    } else
        sub(getVec(), obj.vec_, res);
    return (BigInt(res));
}

void BigInt::soma(const string &v1, const string &v2, string &res) {
    printVal(v1, v2);
    auto it_v2 = v2.rbegin();
    int aux = 0;

    for (auto it = v1.rbegin(); it != v1.rend(); it++) {
        if (it_v2 != v2.rend()) {
            auto val = (*it - '0') + (*it_v2 - '0');
            insertValor(val, aux, res);
            it_v2++;
        } else {
            auto val = *it - '0';
            insertValor(val, aux, res);
        }
    }
    if (aux == 1) res.insert(0, to_string(1));
}

void BigInt::sub(const vector<int> &v1, const vector<int> &v2, string &res) {
    printVal(transformVal(v1), transformVal(v2));

    vector<int> v1_aux;
    vector<int> v2_aux;

    v1_aux.insert(v1_aux.begin(), v1.begin(), v1.end());
    v2_aux.insert(v2_aux.begin(), v2.begin(), v2.end());

    auto it_v2 = v2_aux.rbegin();

    for (auto it = v1_aux.rbegin(); it != v1_aux.rend(); it++) {
        if (it_v2 != v2_aux.rend()) {
            auto val = *it - *it_v2;
            it_v2++;

            if (val < 0) {
                auto it_aux = it + 1;

                while (it_aux != v1_aux.rend()) {
                    if (*it_aux != 0) {
                        (*it_aux)--;
                        break;
                    }
                    it_aux++;
                }
                while (--it_aux != it) {
                    (*it_aux)--;
                    (*it_aux) += 10;
                }
                val += 10;
            }
            res.insert(0, to_string(val));
        } else {
            auto val = *it;
            res.insert(0, to_string(val));
        }
    }
    for (auto &c : res) {
        if (c != '0') return;
        res.erase(0, 1);
    }
}

void BigInt::insertValor(int &val, int &aux, string &res) {
    val += aux;
    if (val >= 10) {
        res.insert(0, to_string(val - 10));
        aux = 1;
    } else {
        res.insert(0, to_string(val));
        aux = 0;
    }
}

string BigInt::transformVal(const vector<int> &vec) {
    string res("");
    for (const auto &c : vec) res.append(to_string(c));
    return res;
}