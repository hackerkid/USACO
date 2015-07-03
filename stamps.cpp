/*
ID: bornawe1
PROG: stamps
LANG: C++
 */


#include <fstream>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	fstream fcin;
	fstream fcout;
	
	fcin.open("stamps.in", ios::in);
	fcout.open("stamps.out", ios::out);

	int maxi;
	int n;
	int t;

	unsigned int a[10000 * 201];
	int val[100];
	memset(a, 1, sizeof(a));
	
	fcin >> maxi;
	fcin >> n;
	
	for (int i = 0; i < n; i++) {
		fcin >> val[i];
	}

	a[0] = 0;

	int i;
	for (i = 1; 1; i++) {
		for (int j = 0; j < n; j++) {
			t = i - val[j];
			if(t >= 0) {
				a[i] = min(a[i], a[t]+1);
			}

		}

		if(a[i] > maxi) {
			break;
		}

	}

	i--;

	fcout << i << endl;

}






