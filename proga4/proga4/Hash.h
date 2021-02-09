#if !defined(HASH)
#define HASH

#include <iostream>
#include <string>
using namespace std;

//namespace hash {
	class Hash {
		string hash;
		int hashind;
		int Controlsum(string key);
		int SimbCodeANSI(int x);
	public:
		string gethash(string key, int y);
	};

	int Hash::SimbCodeANSI(int x) {
		x += 256;
		while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) {
			if (x < 48) {
				x += 24;
			}
			else { x -= 47; }
		}
		return x;
	}

	int Hash::Controlsum(string key) {
		int Sum=0;
		if (key.size() % 2 != 0) {key+= 'a';}
		for (int i = 0; i < key.size(); i+=2) {
			int mult = key[i] * key[i + 1];
			int div = key[i] / key[i + 1];
			Sum += SimbCodeANSI(mult+div);
		}
		return Sum;
	}

	string Hash::gethash(string key, int y) {
	    float j = float(y/100);
		int size = 10*j;
		int lenkey = key.size();
		int sault = this->Controlsum(key);
		for (int i = 0; i < lenkey/2; i++) { key += this->SimbCodeANSI(key[i] + key[i + 1]); }
		int maxsault = this->Controlsum(key);
		int maxlenkey = key.size();
		while (key.size() <= size) {
			for (int i = 0, cen = key.size() / 2; i < cen; i++) { this->hash += this->SimbCodeANSI(key[cen - i] + key[cen + i]); }
			key += this->hash;
			this->hash.clear();
		}
		char ansisault = this->SimbCodeANSI(sault);
		char ansimaxsault = this->SimbCodeANSI(maxsault);
		for (int i = 0; this->hash.size() <= size-4;) {
			this->hash += this->SimbCodeANSI(key[i] + key[++i]);
		}
		this->hash += sault;
		this->hash += ansisault;
		this->hash += maxsault;
		this->hash += ansimaxsault;

		return this->hash;
	}
//}
#endif // HASH

