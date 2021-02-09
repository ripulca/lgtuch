#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>
#include <windows.h>
using namespace std;

struct info {
	float Key;
	char A;
	int B;
};
struct note {
	float Key;
	info *addr;
};

void vvod(info*arr, note*guide, int N) {
	for (int i = 0; i < N; i++) {
		arr[i].A = char('a' + rand() % ('z' - 'a'));
		arr[i].B = rand() % 100 - 50;
		int x = rand();
		arr[i].Key= float(rand()%100)/100;
		guide[i].Key = arr[i].Key;
		guide[i].addr = &arr[i];
	}
	for (int i = 0; i < N; i++) {
		cout << guide[i].addr->A << " " << guide[i].addr->B << " " << guide[i].addr->Key << endl;
	}
	cout << endl;
}

void sort(note* guide, int N) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (guide[j].Key > guide[j + 1].Key) {
				note temp = guide[j];
				guide[j] = guide[j + 1];
				guide[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << guide[i].addr->A << " " << guide[i].addr->B << " " << guide[i].addr->Key << endl;
	}
	cout << endl;
}

void block_same(note* guide, int N, float arg) {
	int nblock = int(sqrt(N));    //количество блоков. окр. в мин сторону
	int step = N/nblock;
	int resi = -1;

	for (int i = step; i < N; i++) {                    
		if ((guide[i].Key < arg)&&(i<step*nblock)) {
			i += step;
		}
		if ((guide[i].Key < arg) && (i == step * nblock)) {
			i++;
		}
		if (guide[i].Key >= arg) {
			if (guide[i].Key == arg) {
				resi = i;
				cout << guide[i].addr->A << " " << guide[i].addr->B << " " << guide[i].addr->Key << endl;
				break;
			}
			if (guide[i].Key > arg) {
				for (int j = i - step; j < i; j++) {
					if (guide[j].Key == arg) {
						resi = j;
						cout << guide[j].addr->A << " " << guide[j].addr->B << " " << guide[j].addr->Key << endl;
						break;
					}
					if ((j == i - 1) && (guide[j].Key != arg)) {
						break;
					}
				}
			}
		}
		if (resi != -1) { break; }
	}
	if (resi == -1) {
		cout << "элемент не найден"<<endl;
	}
	else {
		cout << "элемент найден" << endl << "анализ соседних значений" << endl;
		if (resi != 0) {
			int a = resi - 1;
			while (a != 0) {
				if (guide[a].Key == arg) {
					cout << "элемент найден" << endl;
					cout << guide[a].addr->A << " " << guide[a].addr->B << " " << guide[a].addr->Key << endl;
				}
				a--;
			}
		}
		if (resi != N) {
			int b = resi + 1;
			while (b != N) {
				if (guide[b].Key == arg) {
					cout << "элемент найден" << endl;
					cout << guide[b].addr->A << " " << guide[b].addr->B << " " << guide[b].addr->Key << endl;
				}
				b++;
			}
		}
	}
}

void int_block(note* guide, int N, float c, float d) {
	int nblock = int(sqrt(N));    //количество блоков. окр. в мин сторону
	int step = N / nblock;
	int resi = -1;
	int resi1 = -1;

	for (int i = step; i < N; i++) {
		if ((guide[i].Key < c) && (i < step * nblock)) {
			i += step;
		}
		if ((guide[i].Key < c) && (i == step * nblock)) {
			i++;
		}
		if (guide[i].Key >= c) {
			if (guide[i].Key == c) {
				resi = i;
				break;
			}
			if (guide[i].Key > c) {
				for (int j = i - step; j < i; j++) {
					if (guide[j].Key == c) {
						resi = j;
						break;
					}
				}
			}
		}
		if (resi != -1) { break; }
	}
	for (int i = step; i < N; i++) {
		if ((guide[i].Key < d) && (i < step * nblock)) {
			i += step;
		}
		if ((guide[i].Key < d) && (i == step * nblock)) {
			i++;
		}
		if (guide[i].Key >= d) {
			if (guide[i].Key == d) {
				resi1 = i;
				break;
			}
			if (guide[i].Key > c) {
				for (int j = i - step; j < i; j++) {
					if (guide[j].Key == d) {
						resi1 = j;
						break;
					}
				}
			}
		}
		if (resi1 != -1) { break; }
	}
	if ((resi == -1) && (resi1 == -1)) {
		cout << "границы не найдены" << endl;
		cout << "вывод возможного интервала:" << endl;
		for (int i = 0; i < N; i++) {
			if ((guide[i].Key >= c) && (guide[i].Key <= d)) {
				cout << guide[i].addr->A << " " << guide[i].addr->B << " " << guide[i].addr->Key << endl;
			}
		}
	}
	else if ((resi == -1)||(resi1 == -1)) {
		cout << "одна граница не найдена" << endl;
		cout << "вывод интервала:" << endl;
		for (int i = 0; i < N; i++) {
			if ((guide[i].Key >= c) && (guide[i].Key <= d)) {
				cout << guide[i].addr->A << " " << guide[i].addr->B << " " << guide[i].addr->Key << endl;
			}
		}
	}
	else {
		cout << "вывод интервала:" << endl;
		for (int i = resi; i <= resi1; i++) {
			cout<< guide[i].addr->A << " " << guide[i].addr->B << " " << guide[i].addr->Key << endl;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int N;
	float arg, c, d;
	cout << "введите кол-во элементов:" << endl;
	cin >> N;
	info* arr = new info [N];
	note* guide = new note[N];
	vvod(arr, guide, N);
	sort(guide, N);
	cout << "введите аргумент поиска:" << endl;
	cin >> arg;
	cout << "введите интервал:" << endl;
	cin >> c;
	cin >> d;
	cout << "сортировка по совпадению:" << endl;
	block_same(guide, N, arg);
	cout << endl<<"сортировка интервалом:"<<endl;
	int_block(guide, N, c, d);
	return 0;
}