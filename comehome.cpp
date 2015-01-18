/*
ID: bornawe1
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <limits.h>
#include <string.h>

using namespace std;

int main()
{
	fstream fcin;
	fstream fcout;
	int p;
	int val;
	char a;
	char b;
	int aa;
	int bb;
	



	fcin.open("comehome.in", ios::in);
	fcout.open("comehome.out", ios::out);
	
	long long  x[70][70];

	for (int i = 0; i <= 52; i++) {
		for (int j = 0; j <= 52; j++) {
			x[i][j] = INT_MAX;
		}
	}


	fcin >> p;

	for (int i = 0; i < p; i++) {
		fcin >> a;
		fcin >> b;
		fcin >> val;

		if(isupper(a)) {
			aa = a - 'A' + 26;
		}

		else {
			aa = a - 'a';
		}

		if(isupper(b)) {
			bb = b - 'A' + 26;
		}

		else {
			bb = b - 'a';
		}
		//cout << val << endl;
		if(x[aa][bb] > val) {
			x[aa][bb] = val;
			x[bb][aa] = val;
		}
	}



	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			for (int k = 0; k < 52; k++) {
				if(x[j][i] + x[i][k] < x[j][k]) {
					x[j][k] = x[j][i] + x[i][k];
				}

			}

		}

	}

	long long min = INT_MAX;
	int ans;
	char f;

	for (int i = 26; i < 51; i++) {
		if(x[i][51] <= min) {
			min = x[i][51];
			ans = i;
		}

	}

	if(ans >= 26) {
		ans = ans - 26;
		f = ans + 'A';
	}



	fcout << f <<" "<< min << endl;
}



