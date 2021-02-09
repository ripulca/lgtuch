#include <iostream>
#include<cstdio>;
#include<cstdlib>;
#include<string.h>
#include<conio.h>;
#include<clocale>;

using namespace std;

int vvod(int a, int b, float* A, float* B, float* C) {
    for (int i = 0; i < a*b; i++){
        cin >> A[i];
    }
    for (int i = 0; i < a*b; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < a*b; i++) {
        cin >> C[i];
    }
    return 0;
}

int Btrns(int a, int b, float* B, float* P) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            P[i*b+j] = B[j*a+i];
        }
    }
    cout << "Транспонированная матрица В:" << endl;
    for (int i = 0; i < a*b; i++) {
        cout << " " << P[i];
    }
    cout << endl;
    return 0;
}

int Ck(int a, int b, float* C) {
    int k;
    cin >> k;
    for (int i = 0; i < a*b; i++) {
        C[i] /= k;
    }
    cout << "C/k:" << endl;
    for (int i = 0; i < a*b; i++) {
        cout << " " << C[i];
    }
    cout << endl;
    return 0;
}

int ABt(int a, int b, float* A, float* B, float* P) {
    for (int i = 0; i < a*b; i++) {
        A[i] = A[i] - P[i];
    }
    cout << "A-Bт:" << endl;
    for (int i = 0; i < a*b; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    return 0;
}

int ABtCk(int a, int b, float* A, float* C, float* S) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            S[i*a+j] = 0;
            for (int k = 0; k < b; k++)
                S[i*a+j] += A[i*b+k] * C[k*a+j];
        }
    }
    cout << "(A-Bт)*C/k:" << endl;
    for (int i = 0; i < a*a; i++) {
        cout << " " << S[i];
    }
    cout << endl;
    return 0;
}

int vivod(int a, int b, float* A, float* B, float* C) {
    for (int i = 0; i < a*b; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    for (int i = 0; i < a*b; i++) {
        cout << " " << B[i];
    }
    cout << endl;
    for (int i = 0; i < a*b; i++) {
        cout << " " << C[i];
    }
    cout << endl;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    cin >> a >> b; //кол-во строк и столбцов
    float*A = new float [a*b];
    float*B = new float [a*b];
    float*C = new float [a*b];
    float*P = new float [a*b];
    float*S = new float [a*a];
    vvod(a, b, A, B, C);
    vivod(a, b, A, B, C);
    Btrns(a, b, B, P);
    Ck(a, b, C);
    ABt(a, b, A, B, P);
    ABtCk(a, b, A, C, S);
    return 0;
}