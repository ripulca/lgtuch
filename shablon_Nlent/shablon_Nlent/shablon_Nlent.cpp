#include <iostream>
#include <cstdio>
#include<cstring>
#include <cstdlib>
#include <limits.h>
#include <ctime>
#include <cmath>
using namespace std;

struct mas
{
	int a[3];                   
};

void Shell(int len, int lent, int count, mas** A, int L) {
	for (int i(0), j(0); (i < lent && j < len); i++)
	{
		for (int step = count / 2; step > 0; step /= 2)
		{
			for (int a = step; a < count; a++)
			{
				for (int b = a - step; (b >= 0) && (A[i][b].a[0] < A[i][b + 1].a[0]); b -= step)
				{
					mas tmp = A[i][b];
					A[i][b] = A[i][b + step];
					A[i][b + step] = tmp;
					j++;
				}
			}
		}
	}
}

void delete_t(int *lentt,  mas**A) {
	for (int i = 0; i < *lentt - 1; i++) {
		A[i] = A[i + 1];
	}
	(*lentt)--;
}

void merge(int len, int *lentt, int count, mas** A, mas* M, int L) {
	int* K = new int [*lentt];
	for (int i = 0; i < *lentt; i++) {
		if (i == *lentt - 1) {
			K[i] = L;
		}
		else {
			K[i] = count;
		}
	}
	int *I = new int[*lentt];
	for (int i = 0; i < *lentt; i++) {
		I[i] = 0;
	}
	int max = INT_MIN, m_i=0, m_j=0;
	for (int k = 0; k < len; k++) {
		for (int i = 0; i < *lentt; i++) {
			if (A[i][I[i]].a[0] > max) {
				max = A[i][I[i]].a[0];
				m_i = i;
				m_j = I[i];
			}
		}
		M[k] = A[m_i][m_j];
		K[m_i]--;
		if (K[m_i] == NULL) {
			for (int j = 0; j < count; j++) {
				A[m_i][j].a[0] = INT_MIN;
			}
		}
		else { I[m_i]++; }
		max = INT_MIN;
	}
	delete[]K;
	if (len < ((*lentt) * count)) {
		delete_t(lentt, A);
	}
}

void tapes(int len, int lent, int count, mas* M) {
	mas** A = new mas * [lent];
	for (int i = 0; i < lent; i++) {
		A[i] = new mas[count];        
	}
	int k1 = 0, k2 = 0, temp;
	for (int k = 0; k < len; k++) {
		if (k1 == count) {
			k1 = 0;
			k2++;
		}
		A[k2][k1] = M[k];
		k1++;
	}
	int L = len - (lent - 1) * count;
	for (int i = L; i < count; i++) {
		A[lent - 1][i].a[0] = INT_MIN;
	}
	int tem=count;
	Shell(len, lent, count, A, L);
	for (int i = 0; i < lent; i++) {
		for (int j = 0; j < count; j++) {
			if (i == lent - 1) {
				count = L;
			}
			if (i * j > len) { break; }
			cout << "{";
			for (int k = 0; k < 3; k++) {
				cout << A[i][j].a[k] << " ";
			}
			cout << "} ";
		}
		cout << endl;
	}
	count = tem;
	merge(len, &lent, count, A, M, L);
	delete[] A;
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int len;

	cout << "Количество триад:";
	cin>> len;
	cout << endl << "Количество лент:";
	int lent = int(sqrt(len));
	cout << lent << endl << "Количество триад в ленте:";
    int count = ceil(len / lent);
	if ((len % lent) != 0) {
		count+=1;
	}
	cout << count << endl;

	mas* M = new mas[len];    
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 3; j++) {
			M[i].a[j] = rand() % 1000 - 500;
		}
	}
	for (int i = 0; i < len; i++) {
		cout << "{ ";
		for (int j = 0; j < 3; j++) {
			cout << M[i].a[j] << " ";
		}
		cout << "} ";
	}
	cout << endl;

	cout << endl;
	tapes(len, lent, count, M);
	for (int i = 0; i < len; i++) {
		cout << "{ ";
		for (int j = 0; j < 3; j++) {
			cout << M[i].a[j] << " ";
		}
		cout << "} ";
	}
	return 0;
}