#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <Windows.h>
using namespace std;

void fread(float**M, int *N, int*n) {
	ifstream fin;
	char name[50];
	int i = 0, j = 0;
	cout << "введите имя файла" << endl;
	cin.getline(name, 50);
	fin.open(name, ios::in);
	if (!fin.is_open()) {
		cout << "Не удалось открыть файл." << endl;
	}
	else {
		cout << "Файл успешно открыт." << endl;
		cout << "" << endl << "" << endl;
		fin >> (*n);
		(*N) = (*n);
		while (!fin.eof())
		{
			fin >> M[i][j];
			cout << M[i][j] << " ";
			j++;
			if (j == (*n)) {
				i++;
				j = 0;
				cout << endl;
			}
		}
		fin.close();
	}
}

void input(float**M1, int N, int* n) {
	(*n) = N*N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M1[i][j]= float(rand() % 101) / 100;
			cout << M1[i][j]<<" ";
		}
		cout << endl;
	}
}

void getCofactor(float** mat, float** temp, int p, int q, int n){
	int offstr = 0;
	int offstb = 0;
	for (int i = 0; i < n - 1; i++) {
		if (i == p) {
			offstr = 1;
		}
		offstb = 0;
		for (int j = 0; j < n - 1; j++) {
			if (j == q) {
				offstb = 1;
			}
			temp[i][j] = mat[i + offstr][j + offstb];
		}
	}
}

float det(float** A, int n){
	float D = 0;
	int degree = 1;
	if (n == 1) {
		return A[0][0];
	}
	else if (n == 2) {
		return A[0][0] * A[1][1] - A[0][1] * A[1][0];
	}
	else {
		float** temp = new float* [n - 1];
		for (int i = 0; i < n - 1; i++) {
			temp[i] = new float[n - 1];
		}
		for (int j = 0; j < n; j++) {
			getCofactor(A, temp, 0, j, n);
			D +=(degree * A[0][j] * det(temp, n - 1));
			degree = -degree;
		}
		for (int i = 0; i < n - 1; i++) {
			delete[] temp[i];
		}
		delete[] temp;
	}
	return D;
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int N, a, b, num, x=0, n = 0;
	float A;
	cout << "введите кол-во столбцов и строк" << endl;
	cin >> N;
	float** M1 = new float*[N];
	for (int i = 0; i < N; i++) {
		M1[i] = new float[N];
	}
	float** M = new float* [50];
	for (int i = 0; i < 50; i++) {
		M[i] = new float[50];
	}
	cout << "выберите откуда брать матрицу" << endl;
	(cin >> x).get();
	switch (x) {
	case 1:
		fread(M, &N, &n);
		A=det(M, N);
		cout << "det=" << A;
		break;
	case 2:
		input(M1, N, &n);
		A=det(M1, N);
		cout << "det=" << A;
		break;
	}
}