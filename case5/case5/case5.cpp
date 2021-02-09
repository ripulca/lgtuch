#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <cmath>
using namespace std;

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "" << endl;
	cin >> n;
	n++;
	string* s = new string[n];
	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			if ((s[i][j]>=97) && (s[i][j]<=122)) {
				s[i][j] += 127;
			}
			else if ((s[i][j] >= 65) && (s[i][j] <= 90)) {
				s[i][j] += 127;
			}
			else if ((s[i][j] >= -64) && (s[i][j] <= -31)) {
				s[i][j] += 129;
			}
			else if ((s[i][j] >= -32) && (s[i][j] <= -1)) {
				s[i][j] += 129;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
}