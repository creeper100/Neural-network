#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;
double lf(double x) {
	return 1 / 1 + pow(2.71828182845904523536, -x);
}
class NEURALNET {
private:
	vector<vector<double>> whide;
	vector<vector<double>> wout;
	int in, hi, ou;
public:
	NEURALNET(int inp,int out,int hide) {
		in = inp;
		ou = out;
		hi = hide;
		for (int in = 0;in < inp;in++)
			for (int hi = 0; hi < hide;hi++)
				whide[in][hi] = cos(rand() % 180);
		for (int hi = 0; hi < hide;hi++)
			for (int ou = 0; ou < out;ou++)
				wout[hi][ou] = cos(rand() % 180);
	}
	vector<double> work(vector<double>inp) {
		vector<double> hide;
		for (int i = 0;i < hi;i++) {
			int add;
			for (int k = 0;k < in;k++)
				add += inp[k] * whide[k][i];
			hide.push_back(lf(add));
		}
		vector<double> out;
		for (int i = 0;i < ou;i++) {
			int add;
			for (int k = 0;k < in;k++)
				add += hide[k] * wout[k][i];
			out.push_back(lf(add));
			return out;
		}
	}
};

int main() {
	return 0;
}
	

