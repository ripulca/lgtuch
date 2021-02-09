#include <iostream>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include "Hash.h"
using namespace std;
//using namespace hash;

struct Data {
	string Key;
	float B;
	char C;
};

struct htable {
	int ind;
	string hashd;
	Data *addr;
};

void add(htable*H, Data*D, bool*mas, int x, int *j) {
	Hash hash;
	string key, A;
	int Ind=0, Ind1;
	float data;
	char data1;
	
	cout << "Ключ (не может быть больше 15 символов)" << endl;
	getline(cin, key);
	while (key.size() >= 15) {
		cout << "Размер ключа не корректен. Повторите ввод" << endl;
		getline(cin, key);
	}
	D[*j].Key = key;
	D[*j].B = float(rand() % 100) / 100;
	D[*j].C = char('a' + rand() % ('z' - 'a'));
	cout << endl;
	A = hash.gethash(key, x);
	cout << "h(" << key << ")= ";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i];
	}
	for (int i = 0; i < A.size(); i++) {
		Ind += int((A[i])%10);
	}
	while (Ind > 2 * x) {
		int i = rand() % x;
		Ind -= i;
	}
	Ind1 = Ind;
	if(mas[Ind]==true){
		while (mas[Ind1] == true) {Ind1++;}
		mas[Ind1] = true;
		H[Ind1].ind = Ind;
		H[Ind1].hashd = A;
		H[Ind1].addr = &D[*j];
	}
	else {
		mas[Ind] = true;
		H[Ind].ind = Ind;
		H[Ind].hashd = A;
		H[Ind].addr = &D[*j];
	}
	(*j)++;
	cout << endl;
}

void del(htable* H, bool* mas, int x, int* j) {
	string key;
	int y, Ind;
	cout << "1-по ключу. 2-по индексу" << endl;
	(cin >> y).get();
	switch (y)
	{
	case 1:
		cout << "Введите ключ" << endl;
		getline(cin, key);
		for (int i = 0; i < (2 * x); i++) {
			if ((mas[i] == true)&&(H[i].addr->Key==key)) {
				H[i].ind = 0;
				H[i].hashd[0] = 0;
				H[i].addr->Key.clear();
				H[i].addr->B = 0;
				H[i].addr->C = 0;
				mas[i] = false;
			}
		}
		break;
	case 2:
		cout << "Введите индекс" << endl;
		cin >> Ind;
		for (int i = 0; i < (2 * x); i++) {
			if ((mas[i] == true) && (H[i].ind == Ind)) {
				H[i].ind = 0;
				H[i].hashd[0] = 0;
				H[i].addr->Key.clear();
				H[i].addr->B = 0;
				H[i].addr->C = 0;
				mas[i] = false;
			}
		}
		break;
	}
	(*j)--;
}

void search(htable* H, bool* mas, int x) {
	string key, A; Hash hash;
	int y, Ind, w;
	cout << "1-поиск по ключу. 2-по индексу"<<endl;
	(cin >> y).get();
	switch (y)
	{
	case 1:
		cout << "Введите ключ" << endl;
		getline(cin, key);
		cout << setw(5) << "Индекс:" << setw(20) << "Хеш" << setw(20) << "Ключ" << setw(15) << "Инфо1" << setw(15) << "Инфо2" << endl << endl;
		for (int i = 0; i < (2 * x); i++) {
			if ((mas[i] == true) && (H[i].addr->Key == key)) {
				cout << setw(7) << H[i].ind << setw(20) << H[i].hashd << setw(20) << H[i].addr->Key << setw(15) << H[i].addr->B << setw(15) << H[i].addr->C << endl;
				cout << "желаете изменить значение? 1-да" << endl;
				(cin >> w).get();
				if (w == 1) {
					cout << "Ключ ";
					getline(cin, key);
					while (key.size() >= 15) {
						cout << "Размер ключа не корректен. Повторите ввод" << endl;
						getline(cin, key);
					}
					H[i].addr->Key = key;
					H[i].addr->B = float(rand() % 100) / 100;
					H[i].addr->C = char('a' + rand() % ('z' - 'a'));
					H[i].hashd = hash.gethash(key, x);
				}
			}
		}
		break;
	case 2:
		cout << "Введите индекс" << endl;
		cin >> Ind;
		while ((Ind > (2 * x))||(Ind<0)) {
			cout << "Индекс не существует. Повторите ввод" << endl;
			cin >> Ind;
		}
		cout << setw(5) << "Индекс:" << setw(20) << "Хеш" << setw(20) << "Ключ" << setw(15) << "Инфо1" << setw(15) << "Инфо2" << endl << endl;
		for (int i = 0; i < (2 * x); i++) {
			if ((mas[i] == true) && (H[i].ind == Ind)) {
				cout << setw(7) << H[i].ind << setw(20) << H[i].hashd << setw(20) << H[i].addr->Key << setw(15) << H[i].addr->B << setw(15) << H[i].addr->C << endl;
				cout << "желаете изменить значение? 1-да" << endl;
				(cin >> w).get();
				if (w == 1) {
					getline(cin, key);
					while (key.size() >= 15) {
						cout << "Размер ключа не корректен. Повторите ввод " << endl;
						getline(cin, key);
					}
					H[i].addr->Key = key;
					H[i].addr->B = float(rand() % 100) / 100;
					H[i].addr->C = char('a' + rand() % ('z' - 'a'));
					H[i].hashd = hash.gethash(key, x);
				}
			}
		}
		break;
	}
}

void cons(htable* H, bool *mas, int x, int j) {
	if (j == 0) { cout << "Хеш-табл. пуста." << endl; }
	else {
		cout << "Всего " << j << " элементов." << endl;
		cout << setw(5) << "Индекс:" << setw(20) << "Хеш" << setw(20) << "Ключ" << setw(15) << "Инфо1" << setw(15) << "Инфо2" << endl << endl;
		for (int i = 0; i < (2 * x); i++) {
			if (mas[i] == true) {
				cout << setw(7) << H[i].ind << setw(20) << H[i].hashd << setw(20) << H[i].addr->Key << setw(15) << H[i].addr->B << setw(15) << H[i].addr->C << endl;
			}
		}
		cout << endl;
	}
}

bool note_file(htable* H, bool* mas, int x, int j) {
	char Name[20];
	cout << "Введите имя файла" << endl;
	cin.getline(Name, 20);
	ofstream fout;
	fout.open(Name, ios::out);
	if (!fout.is_open()) {
		cout << "Не удалось открыть файл.";
		return false;
	}
	else {
		fout << j << endl;
		for (int i = 0; i < 2 * x; i++) {
			if (mas[i] == true) {
				fout << setw(10) << H[i].addr->Key << setw(10) << H[i].ind << setw(15) << H[i].hashd << setw(15) << H[i].addr->B << setw(15) << H[i].addr->C << endl;
			}
		}
		fout.close();
		cout << "oks" << endl;
		return true;
	}
}

bool read_file(htable* H, Data*D, bool*mas, int x, int *j) {
	string key, A; Hash hash; int Ind=0, Ind1;
	char Name[20];
	cout << "Введите имя файла" << endl;
	cin.getline(Name, 20);
	ifstream fin;
	fin.open(Name, ios::in);
	if (!fin.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		return false;
	}
	else {
		cout << "Файл успешно открыт." << endl;
		fin>>(*j);
		cout << "количество эл. в файле: " << *j << endl;
		for (int i = 0; i < *j; i++) {
			fin>>key;
			A = hash.gethash(key, x);
			for (int i = 0; i < A.size(); i++) {
				Ind += int((A[i]) % 10);
			}
			while (Ind > 2 * x) {
				int i = rand() % x;
				Ind -= i;
			}
			Ind1 = Ind;
			if (mas[Ind] == true) {
				while (mas[Ind1] == true) { Ind1++; }
				mas[Ind1] = true;
				D[i].Key = key;
				fin >> H[Ind1].ind;
				fin >> H[Ind1].hashd;
				fin >> D[i].B;
				fin >> D[i].C;
				H[Ind1].addr= &D[i];
			}
			else {
				mas[Ind] = true;
				D[i].Key = key;
				fin >> H[Ind].ind;
				fin >> H[Ind].hashd;
				fin >> D[i].B;
				fin >> D[i].C;
				H[Ind].addr = &D[i];
			}
		}
		fin.close();
		return true;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int x, a=1, j=0;
	cout << "Введите количество элементов:" << endl;
	cin >> x;
	while (x < 100) {
		cout << "Некорректный размер. Повторите ввод." << endl;
		cin >> x;
	}
	htable* H = new htable[2*x];
	Data* D = new Data [2*x];
	bool* mas = new bool[2*x];
	for (int i = 0; i < (2 * x); i++) {
		H[i].ind = 0;
		H[i].hashd[0] = 0;
		mas[i] = false;
	}
	cout << "1-добавить эл." << endl;
	cout << "2-удалить" << endl;
	cout << "3-вывод в консоль и проверка на пустоту" << endl;
	cout << "4-поиск и смена знач." << endl;
	cout << "5-запись в файл" << endl;
	cout << "6-чтение из файла" << endl;
	cout << "0-выход" << endl;
	while (a != 0) {
		(cin >> a).get();
		switch (a)
		{
		case 1:
			add(H, D, mas, x, &j);
			break;
		case 2:
			del(H, mas, x, &j);
			break;
		case 3:
			cons(H, mas, x, j);
			break;
		case 4:
			search(H, mas, x);
			break;
		case 5:
			note_file(H, mas, x, j);
			break;
		case 6:
			read_file(H, D, mas, x, &j);
			break;
		}
	}
	return 0;
}