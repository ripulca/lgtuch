#include <iostream>
#include "DecartN.h"
#include "Polar.h"
#include "Matrix.h"
#include <vector>
using namespace std;

int main(){
    int size1, size2;
    bool choice = true;
    double a;
    cout << "enter type of matrix (true-NDecart, false-Polar) and it's size" << endl;
    while (!(cin >> choice)) {
        cout << "error. try again" << endl;
        cin.clear();
        cin.ignore();
    }
    while (!(cin >> size1)) {
        cout << "error. try again" << endl;
        cin.clear();
        cin.ignore();
    }
    while (!(cin >> size2)) {
        cout << "error. try again" << endl;
        cin.clear();
        cin.ignore();
    }
    cout << "enter the scale" << endl;
    while (!(cin >> a)) {
        cout << "" << endl;
        cin.clear();
        cin.ignore();
    }
    if (choice == 1) {
        Matrix<DecartN> A1(size1, size2);
        Matrix<DecartN> B1(size1, size2);
        cout << "first matix"<<endl<<A1;
        B1 = A1;
        Matrix<DecartN> C1(size1, size2);
        C1 = A1 / a;
        cout << "result matrix"<<endl << C1;
    }
    else {
        Matrix<Polar> A2(size1, size2);
        Matrix<Polar> B2(size1, size2);
        cout << "first matix" << endl << A2;
        B2 = A2;
        Matrix<Polar> C2(size1, size2);
        C2 = A2 / a;
        cout << "result matrix" << endl << C2;
    }
    return 0;
}