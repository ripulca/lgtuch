#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cmath>
using namespace std;

void sort(string*s, int n) {
	string key; int j = 0;
	for (int i = 1; i < n; i++)
	{
		key = s[i];
		j = i - 1;
		while (j >= 0 && s[j] > key)
		{
			s[j + 1] = s[j];
			j--;
		}
		s[j + 1] = key;
	}
}

bool fwrite(string*s, int n) {
	ofstream fout;
	string name;
	cout << "введите имя файла" << endl;
	getline(cin, name);
	fout.open(name, ios::in);
	if (!fout.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		return false;
	}
	else {
		cout << "Файл успешно открыт." << endl;
		fout << n << endl;
		int i = 0;
		for (int i = 0; i < n; i++) {
			fout << s[i]<<" ";
		}
		fout.close();
		return true;
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
		string* s = new string[n];
		int i = 0;
		while (!fin.eof())
		{
			fin >> s[i];
			i++;
		}
		fin.close();
		sort(s, n);
		fwrite(s, n);
		return true;
	}
}

int main(){
	setlocale(LC_ALL, "rus");
	fread();
	return 0;
}