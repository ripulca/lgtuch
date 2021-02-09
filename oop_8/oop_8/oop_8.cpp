#include <iostream>
#include <stdexcept>
using namespace std;

class MatrixException : public std::runtime_error {
char* msg;
public: MatrixException(const char* msg) : std::runtime_error(msg) {};
public: MatrixException() : std::runtime_error("matrix's undefined error") {};
};
class IllegalSizeOfMatrixes : public MatrixException {
public: IllegalSizeOfMatrixes(const char* msg) : MatrixException(msg) {};
public: IllegalSizeOfMatrixes() : MatrixException("incorrect size of matrix") {};
};
class NegativeSizeOfMatrix : public MatrixException {
public: NegativeSizeOfMatrix(const char* msg) : MatrixException(msg) {};
public: NegativeSizeOfMatrix() : MatrixException("size of matrix is negative") {};
};
class NullMatrix : public MatrixException {
public: NullMatrix(const char* msg) : MatrixException(msg) {};
public: NullMatrix() : MatrixException("matrix is null") {};
};

class Matrix {
    int** A;
public:
    int size1, size2;

    Matrix(int s1) {
        this->size1 = s1;
        this->size2 = s1;
        A = new int* [size1];
        for (int i = 0; i < size1; i++) {
            A[i] = new int[size2];
            for (int j = 0; j < size2; j++) {
                A[i][j] = NULL;
            }
        }
    }

    Matrix() {  /// просто создание рандомного массива
        cout << "enter size [X;Y]" << endl;
        try {
            cout << "x: ";
            cin >> size1;
            cout << "y: ";
            cin >> size2;
            if (size1 < 0 || size2 < 0)throw new NegativeSizeOfMatrix();
            A = new int* [size1];
            for (int i = 0; i < size1; i++) {
                A[i] = new int[size2];
                for (int j = 0; j < size2; j++) {
                    A[i][j] = NULL;
                }
            }
            cout << "genered matrix" << endl;
            for (int i = 0; i < size1; i++) {
                for (int j = 0; j < size2; j++) {
                    A[i][j] = (i + rand() % 11) * (j + rand() % 11);
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
        }
        catch (...) {
            cout << "GG WP" << endl;
            system("pause");
        }
    }
    class Array {
    public:
        int* temp;
        Array(int* a) { temp = a; }
        int& operator[](int a)
        {
            return temp[a];
        }
        ~Array() {
            temp = nullptr;
        }
    };
    Array operator[] (int a)
    {
        try {

            if (A == nullptr) throw new NullMatrix();
            return Array(A[a]);
        }
        catch (...) {
            cout << "GG WP" << endl;
            system("pause");
        }
    }
    friend ostream& operator<< (ostream& out, Matrix& A) {
        try {
            if (A[0][0] == NULL) throw new NullMatrix();
            for (int i = 0; i < A.size1; i++) {
                for (int j = 0; j < A.size2; j++) {
                    out << A[i][j] << " ";
                }
                out << endl;
            }
            out << endl;
            return out;
        }
        catch (...) {
            cout << "GG WP" << endl;
            system("pause");
        }
    }
    friend Matrix operator+ (Matrix& A, Matrix& B) {
        Matrix C=A;
        try {
            if (A.size1 != B.size1) { throw new IllegalSizeOfMatrixes(); }
            if (A.size2 != B.size2) { throw new IllegalSizeOfMatrixes(); }
            for (int i = 0; i < A.size1; i++) {
                for (int j = 0; j < A.size2; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            return C;
        }
        catch (...) {
            cout << "GG WP" << endl;
            system("pause");
        }
    }
    friend Matrix operator- (Matrix& A, Matrix& B) {
        Matrix C=A;
        try {
            if (A.size1 != B.size1) { throw new IllegalSizeOfMatrixes(); }
            if (A.size2 != B.size2) { throw new IllegalSizeOfMatrixes(); }
            for (int i = 0; i < A.size1; i++) {
                for (int j = 0; j < A.size2; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            return C;
        }
        catch (...) {
            cout << "GG WP"<<endl;
            system("pause");
        }
    }
};

int main()
{
    Matrix A, B, C;
    int i, j;
    try {
        cout << "enter the index(i,j)" << endl;
        cout << "i, j: ";
        cin >> i >> j;
        if (i < 0 || j < 0) throw new MatrixException();
        i--; j--;
        cout << A[i][j] << endl;
        C = A + B;
        cout << "\n\nplus" << C << endl;
        C = A - B;
        cout << "\n\nminus" << C << endl;
    }
    catch (...) {
        cout << "GG WP" << endl;
        system("pause");
    }
    return 0;
}