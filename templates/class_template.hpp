#ifndef CLASS_TEMPLATE_HPP__
#define CLASS_TEMPLATE_HPP__

template<typename T>
class Matriz {
private:
    T **dados_;
    int nL_;
    int nC_;
public:
    Matriz(int l, int c);
    ~Matriz();

    T &operator() (int l, int c); // operador ()

};

template<typename T>
Matriz<T>::Matriz(int l, int c): nL_(l), nC_(c) {
    dados_ = new T * [l];

    for (int i = 0; i < nL_; ++i)
        dados_[i] = new T[c];
}

template<typename T>
Matriz<T>::~Matriz() {
    for (int i = 0; i < nL_; ++i)
        delete [] dados_[i];
    delete [] dados_;
}

template<typename T>
T &Matriz<T>:: operator() (int l, int c) {
    return dados_[l][c];
}

#endif