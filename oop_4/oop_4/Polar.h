#pragma once
#include <vector>
//#include <ctime>
using namespace std;
class Polar
{
	vector<double> polar;
	double rad;
	int size;
public:
	Polar(){
		//srand(time(NULL));
		this->size = 2+rand() % 2;
		this->rad = rand() % 50;
		this->polar.resize(this->size);
		for (int i = 0; i < this->size; i++) {
			this->polar[i] = rand() % 100;
		}
	}
	friend ostream& operator<<(ostream& out, Polar& matr);
	Polar& operator/ (double scale){
		for (int i = 0; i < this->size; i++) {
			this->rad /= scale;
		}
		return *this;
	}
};

ostream& operator<<(ostream& out, Polar& matr) {
	out << matr.rad << " ";
	for (int i = 0; i < matr.size; i++) {
		out << "("<<matr.polar[i]<<") ";
	}
	return out;
}