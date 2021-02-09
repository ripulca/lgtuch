#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cmath>
using namespace std;

struct vehicle{
	string mark;
	int year;
	int mileage;
	int price;
};

void sort(vehicle* M, int n) {
	for (int i = 1; i < n; i++) {
		int noSwap = 1;
		for (int j = 0; j < n-i; j++) {
			if (M[j].price < M[j + 1].price) {
				vehicle tmp = M[j];
				M[j] = M[j + 1];
				M[j + 1] = tmp;
				noSwap = 0;
			}
		}
		if (noSwap == 1) {
			break;
		}
	}
}

void output(vehicle* M, int n) {
	for (int i = 0; i < n; i++) {
		cout << M[i].mark << " " << M[i].mileage << " " << M[i].price << " " << M[i].year << endl;
	}
}

bool fread() {
	ifstream fin; 
	string name;
	int n;
	cout << "введите имя файла" << endl;
	getline(cin, name);
	fin.open(name, ios::in);
	if (!fin.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		return false;
	}
	else {
		cout << "Файл успешно открыт." << endl;
		fin >> n;
		vehicle* M = new vehicle[n];
		int i = 0;
		while (!fin.eof())
		{
			fin >> M[i].mark >> M[i].year >> M[i].mileage >> M[i].price;
			i++;
		}
		fin.close();
		sort(M, n);
		output(M, n);
		return true;
	}
}

int main(){
	setlocale(LC_ALL, "rus");
	fread();
	return 0;
}