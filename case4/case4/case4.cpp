#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double f(double x) {
	double func= pow(x, 3) + 8 * pow(x, 2) - 3 * x + 3;
	return func;
}

int main() {
    double a, b, e, xmin;
	float r = (sqrt(5) + 1) / 2;
	cin >> a >> b >> e;
    double t = (sqrt(5) - 1) * 0.5;
    double x1 = b - t * (b - a);
    double x2 = a + t * (b - a);
    while (e <= fabs(b - a)){
        if (f(x2) < f(x1))
            a = x1;
        else
            b = x2;
        x1 = b - t * (b - a);
        x2 = a + t * (b - a);
    }
    cout << "xmin =  " << (xmin = (a + b) * 0.5) << endl;
    cout << "f(xmin)= " << f(xmin) << endl;
	return 0;
}