#pragma once
#include <vector>
//#include <ctime>
using namespace std;
class DecartN{
	vector<double> Dec;
	int size;
public:
	DecartN() { 
		//srand(time(NULL));
		this->size = rand() % 2 + 2;
		this->Dec.resize(this->size);
		for (int i = 0; i < this->size; i++) {
			this->Dec[i] = rand() % 100;
		}
	}

	friend ostream& operator<< (ostream& out, DecartN& matr);
	DecartN& operator/ (double scale) {
		for (int i = 0; i < this->size; i++) {
			this->Dec[i] /= scale;
		}
		return *this;
	}
};

ostream& operator<< (ostream& out, DecartN& matr) {
	out << "(";
	for (int i = 0; i < matr.size; i++) {
		out << matr.Dec[i];
		if (i == matr.size - 1) { break; }
		out << "; ";
	}
	out << ") ";
	return out;
}