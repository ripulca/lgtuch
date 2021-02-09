#pragma once
#include <stdexcept>
#include "DecartN.h"
using namespace std;
template <class T>
class Matrix {
    int size1=1, size2=1, ch;
    T**A;
public:
    Matrix(int size1, int size2) {
        set_matrix(size1, size2);
    }
    void set_matrix(int size1, int size2);
    template <class T>
    friend ostream& operator<< (ostream& out, Matrix<T>& matr);
    Matrix<T>& operator/ (double scale){
        for (int i = 0; i < this->size1; i++) {
            for (int j = 0; j < this->size2; j++) {
                this->A[i][j] / scale;
            }
        }
        return *this;
    }
    Matrix<T>& operator= (const Matrix<T>& matr) {
        for (int i = 0; i < this->size1; i++) {
            for (int j = 0; j < this->size2; j++) {
                this->A[i][j]= matr.A[i][j];
            }
        }
        return *this;
    }
};

template <class T>
ostream& operator<< (ostream& out, Matrix<T>& matr) {
    for (int i = 0; i < matr.size1; i++) {
        for (int j = 0; j < matr.size2; j++) {
            out << matr.A[i][j]<<"  ";
        }
        out << endl;
    }
    return out;
}

template <class T>
void Matrix<T>::set_matrix(int s1, int s2) {
    if ((s1 < 1) || (s2 < 1)) throw invalid_argument("invalid argument");
    this->size1 = s1;
    this->size2 = s2;
    this->A=new T*[this->size1];
    for (int i = 0; i < this->size1; i++) {
        this->A[i]=new T [this->size2];
    }
}