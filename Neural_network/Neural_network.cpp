#include "pch.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;
double lf(double x) {
	return 1 / (1 + pow(2.71828182845904523536, -x));
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
		for (int inpu = 0;inpu < inp;inpu++) {
			whide.push_back(vector<double>());
			for (int hid = 0; hid < hide;hid++) 
				whide[inpu].push_back((inpu+1)*0.1+(hid+1)*0.01); //cos(rand() % 180);
		}
		for (int hid = 0; hid < hide;hid++) {
			wout.push_back(vector<double>());
			for (int outp = 0; outp < out;outp++)
				wout[hid].push_back((hid + 1)*0.1 + (outp + 1)*0.01); //cos(rand() % 180);
		}
	}
	vector<double> work(vector<double>inp) {
		vector<double> hide;
		for (int i = 0;i < hi;i++) {
			double add=0;
			for (int k = 0;k < in;k++) 
				add =add+ inp[k] * whide[k][i];
			hide.push_back(lf(add));
		}
		vector<double> out;
		for (int i = 0;i < ou;i++) {
			double add=0;
			for (int k = 0;k < in;k++)
				add += hide[k] * wout[k][i];
			out.push_back(lf(add));
		}
		return out;
	}
	void getiweight() {
		for (int i =0 ;i < in;i++) {
			for (int k = 0;k < hi;k++)
				cout << whide[i][k]<<" ";
			cout << endl;

		}
	}
};

int main() {
	NEURALNET nn(2, 2, 2);
	vector<double> res;
	vector<double> inp;
	for (int i = 1;i <= 2;i++)
		inp.push_back(i);
	res = nn.work(inp);
	for (int i = 0;i < 2;i++)
		cout << res[i] << endl;
	cout << "done!";
	cout << lf(0.2) << endl << lf(0.21);
	return 0;
}
	

