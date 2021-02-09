#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int MAX = 1000000;
	int size, S=0, St, min=MAX, max=0, a=0;
	cout << "enter size" << endl;
	cin >> size;
	while ((1>size) || (size > MAX)) {
		cout << "error. enter again" << endl;
		cin >> size;
	}
	vector<int> mas(size);
	cout << "fill in the massive (cherez probel)" << endl;
	for (int i = 0; i < size; i++) {
		cin >> mas[i];
		while (mas[i] < 0) {
			cout << "enter the mas. el. again" << endl;
			cin >> mas[i];
		}
		if (min > mas[i]) {
			min = mas[i];
		}
		if (max < mas[i]) {
			max = mas[i];
		}
	}
	for (int i = min; i <= max; i++) {
		for (int j = 0; j < size; j++) {
			if (j!= size - 1) {
				if (mas[j+1]>=i && mas[j]>=i) {
					a++;
					if (a == 1) { a++; }
				}
				else{
					St = i * a;
					if (St > S) {
						S = St;
					}
					a = 0;
				}
			}
		}
		St = i * a;
		if (St > S) {
			S = St;
		}
		a = 0;
	}
	cout << "result " << S << endl;
	return 0;
}