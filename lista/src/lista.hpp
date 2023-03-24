#ifndef LISTA_HPP__
#define LISTA_HPP__

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class No {
private:
    T val_;
    No<T> *next_;
    No<T> *prev_;
public:
    No(T val):val_(val), next_(NULL) { }

    T getValue() { return val_; }
    No *getNext() { return next_; }
    No *getPrev() { return prev_; }

    void setNext(No *no) { next_ = no; }
    void setPrev(No *no) { prev_ = no; }
};

template<typename T>
class Lista {
private:
    No<T> *begin_;
    No<T> *end_;

    No<T> *getPosition(size_t pos);
public:
    Lista();
    Lista(T val);

    void imprime();
    void imprimeReverse();

    bool isEmpity();
    size_t size();

    void insert(T val);
    void insert(size_t pos, T val);
    void push_back(T val);

    T buscar(size_t pos);
    void remover(size_t pos);
};

template<typename T>
Lista<T>::Lista(): begin_(NULL), end_(NULL) { }

template<typename T>
Lista<T>::Lista(T val) : begin_(new No(val)), end_(begin_) { }

template<typename T>
void Lista<T>::imprime() {
    if (isEmpity()) {
        cout << "Lista vazia" << endl;
    } else {
        No<T> *aux = begin_;

        while (aux) {
            cout << aux->getValue() << " ";
            aux = aux->getNext();
        }
        cout << endl;
    }
}

template<typename T>
void Lista<T>::imprimeReverse() {
    if (isEmpity()) {
        cout << "Lista vazia" << endl;
    } else {
        No<T> *aux = end_;

        while (aux) {
            cout << aux->getValue() << " ";
            aux = aux->getPrev();
        }
        cout << endl;
    }
}

template<typename T>
bool Lista<T>::isEmpity() { return (begin_ == NULL); }

template<typename T>
size_t Lista<T>::size() {

    if (isEmpity()) {
        return 0;
    } else {
        No<T> *aux = begin_;
        size_t cont = 0;

        while (aux) {
            cont++;
            aux = aux->getNext();
        }
        return cont;
    }
}

template<typename T>
inline No<T> *Lista<T>::getPosition(size_t pos) {
    if (isEmpity()) {
        throw std::string("Lista vazia\n");
    } else {
        No<T> *aux = begin_;
        size_t cont = 0;

        while (aux) {
            if (cont++ == pos)
                return aux;
            aux = aux->getNext();
        }
    }
    throw std::string("Posicao nao encontrado");
}

template<typename T>
void Lista<T>::insert(T val) {
    No<T> *novo_no = new No(val);

    if (isEmpity()) {
        begin_ = novo_no;
        end_ = novo_no;
    } else {
        novo_no->setNext(begin_);
        begin_->setPrev(novo_no);
        begin_ = novo_no;
    }
}

template<typename T>
void Lista<T>::insert(size_t pos, T val) {
    No<T> *novo_no = new No(val);

    size_t tam = size();

    if (pos == 0) {
        insert(val);
    } else if (pos == tam)
        push_back(val);
    else {
        try {
            No<T> *no_aux = getPosition(pos);

            novo_no->setNext(no_aux);
            novo_no->setPrev(no_aux->getPrev());
            no_aux->setPrev(novo_no);

            no_aux = novo_no->getPrev();
            no_aux->setNext(novo_no);
            no_aux = novo_no;
        } catch (const std::string &ref) {
            cout << ref << endl;
        }
    }
}

template<typename T>
void Lista<T>::push_back(T val) {
    No<T> *novo_no = new No(val);

    if (isEmpity()) {
        begin_ = novo_no;
        end_ = novo_no;
    } else {
        end_->setNext(novo_no);
        novo_no->setPrev(end_);
        end_ = novo_no;
    }
}

template<typename T>
T Lista<T>::buscar(size_t pos) {
    if (isEmpity()) {
        throw std::string("Lista vazia\n");
    } else {
        No<T> *aux = begin_;
        size_t cont = 0;

        while (aux) {
            if (cont++ == pos)
                return aux->getValue();
            aux = aux->getNext();
        }
    }
    throw std::string("Valor nao encontrado");
}

template<typename T>
void Lista<T>::remover(size_t pos) {
    if (isEmpity()) {
        throw std::string("Lista vazia");
    } else {
        No<T> *no_remover = begin_;
        size_t cont = 0;

        while (no_remover) {
            if (cont++ == pos) {
                if (pos == 0) {
                    if (begin_ == end_) {
                        begin_ = NULL;
                        end_ = NULL;
                    } else {
                        begin_ = begin_->getNext();
                        begin_->setPrev(NULL);
                    }
                } else {
                    No<T> *no_prev = no_remover->getPrev();

                    if (no_remover == end_) {
                        end_ = no_prev;
                        end_->setNext(NULL);
                    } else {
                        No<T> *no_next = no_remover->getNext();
                        no_prev->setNext(no_next);
                        no_next->setPrev(no_prev);
                    }
                }
                delete(no_remover);
                return;
            }
            no_remover = no_remover->getNext();
        }
    }
    throw std::string("Valor nao encontrado");
}

#endif