#include "include/bigint.hpp"

// tratar para pegar o modulo
BigInt::BigInt(const BigInt &obj) {
    this->val_ = obj.val_;
    init();
}

void BigInt::init() { for (const auto &c : val_) vec_.push_back(c - '0'); }

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

    // cout << "A: " << this->val_ << endl;
    // cout << "B: " << obj.val_ << endl;

    if (obj.val_.size() == getVal().size()) {
        if (this->val_.compare(obj.val_) == 0) return (BigInt("0"));
        if (obj.vec_.size() == 1)
            return (BigInt(to_string(this->vec_[0] - obj.vec_[0])));

        auto it_obj = obj.vec_.begin();
        it_obj++;
        for (size_t i = 0; i < this->vec_.size(); i++) {
            if (this->vec_[i] == obj.vec_[i]) continue;
            else if (this->vec_[i] > obj.vec_[i]) {
                sub(getVec(), obj.vec_, res);
                break;
            } else {
                sub(obj.vec_, getVec(), res);
                res.insert(0, "-");
                break;
            }
            it_obj++;
        }
    } else if (obj.val_.size() > getVal().size()) {
        sub(obj.vec_, getVec(), res);
        res.insert(0, "-");
    } else
        sub(getVec(), obj.vec_, res);
    return (BigInt(res));
}

BigInt BigInt::operator*(const BigInt &obj) {
    string res("");

    if (obj.val_.size() >= getVal().size())
        mult(obj.vec_, getVec(), res);
    else
        mult(getVec(), obj.vec_, res);
    return (BigInt(res));
}

BigInt BigInt::operator/(const BigInt &obj) {
    string res("");

    div(getVal(), obj.val_, res);
    return (BigInt(res));
}

// trabalhar com vector
void BigInt::soma(const string &v1, const string &v2, string &res) {
    auto it_v2 = v2.rbegin();
    int aux = 0;

    for (auto it = v1.rbegin(); it != v1.rend(); it++) {
        int val = 0;
        if (it_v2 != v2.rend()) {
            val = (*it - '0') + (*it_v2 - '0');
            it_v2++;
        } else {
            val = *it - '0';
        }
        val += aux;
        if (val >= 10) {
            res.insert(0, to_string(val - 10));
            aux = 1;
        } else {
            res.insert(0, to_string(val));
            aux = 0;
        }
    }
    if (aux == 1) res.insert(0, to_string(1));
}

// precisa de correcoes
void BigInt::sub(const vector<int> &v1, const vector<int> &v2, string &res) {
    vector<int> v1_aux;
    vector<int> v2_aux;

    v1_aux.insert(v1_aux.begin(), v1.begin(), v1.end());
    v2_aux.insert(v2_aux.begin(), v2.begin(), v2.end());

    // for (const auto &v : v1_aux) cout << v << " ";
    // cout << endl;
    // for (const auto &v : v2_aux) cout << v << " ";
    // cout << endl;
    // cout << endl;

    auto it_v2 = v2_aux.rbegin();
    auto val = 0;

    for (auto it = v1_aux.rbegin(); it != v1_aux.rend(); it++) {
        if (it_v2 != v2_aux.rend()) {
            val = *it - *it_v2;
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
        } else
            val = *it;
        // cout << val << " ";
        res.insert(0, to_string(val));
    }
    // cout << endl;
    for (auto &c : res) {
        if (c != '0') return;
        res.erase(0, 1);
    }
}

void BigInt::mult(const vector<int> &v1, const vector<int> &v2, string &res) {
    auto it_v2 = v2.rbegin();
    int aux = 0;
    int cont = 0;

    vector<string> temp;

    while (it_v2 != v2.rend()) {
        for (auto it = v1.rbegin(); it != v1.rend(); it++) {
            auto val = (*it) * (*it_v2);
            val += aux;
            aux = 0;

            if (val >= 10 && it != v1.rend() - 1) {
                while (val >= 10) {
                    aux += 1;
                    val -= 10;
                }
            }
            res.insert(0, to_string(val));
        }
        if (cont > 0) {
            const string zeros(cont, '0');
            res.append(zeros);
        }
        cont++;
        temp.push_back(res);
        res.clear();
        it_v2++;
    }

    BigInt res_temp("0");
    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
        BigInt val_temp(*it);
        BigInt soma_temp = val_temp + res_temp;
        res_temp.val_ = soma_temp.val_;
    }
    res = res_temp.getVal();
}

// v2 deve ser <= 2^64-1
void BigInt::div(const string &v1, const string &v2, string &res) {

    if (v2.size() > 20) {
        cout << "tamanho do divisor invalido" << endl;
        return;
    }
    string copia = v1;
    unsigned long long int dividendo = 0;
    const unsigned long long int divisor = stoull(v2);

    int controle = 0;

    while (!copia.empty()) {
        dividendo = stoull(copia.substr(0, v2.size()));
        if (dividendo < divisor) {
            while (dividendo < divisor) {
                if (copia.size() > v2.size()) {
                    dividendo = stoull(copia.substr(0, v2.size() + 1));
                    copia.erase(0, v2.size() + 1);
                } else {
                    if (controle == 0) {
                        if (res.size() == 0) res.append("0");
                        res.append(",");
                    } else {
                        copia.append("0");
                        if (controle == (CASA_DECIMAL)) break;
                        else if (copia.size() < v2.size())
                            res.append("0");
                        else if (stoull(copia.substr(0, v2.size() + 1)) < divisor)
                            res.append("0");
                    }
                    controle++;
                }
            }
        } else
            copia.erase(0, v2.size());

        res.append(to_string(dividendo / divisor));
        dividendo = dividendo % divisor;

        if (dividendo != 0) copia.insert(0, to_string(dividendo));
        if (controle == CASA_DECIMAL) break;
    }
}