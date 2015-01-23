/*
ID: bornawe1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;

int main()
{

	int a[120][120];

	fstream fcin;
	fstream fcout;

	fcin.open("agrinet.in", ios::in);
	fcout.open("agrinet.out", ios::out);

	int n;
	int dis[120];
	int source[120];
	int count;
	int inTree[120]; 
	int min;
	int cost;
	int val;
	
	fcin >> n;

	for (int i = 0; i < n; i++) {
		dis[i] = INT_MAX;
		source[i] = -1;
		inTree[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fcin >> a[i][j];
		}
	}



	dis[0] = 0;
	count = 0;
	cost = 0;


	while(count < n) {
		min = INT_MAX;
		for (int i = 0; i < n; i++) {
			if(inTree[i] == 0 and dis[i] < min) {
				val = i;
				min = dis[i];
			}

		}


		count++;
		inTree[val] = 1;

		cost += min;

		for (int i = 0; i < n; i++) {
			if(inTree[i] == 0 and a[val][i] < dis[i] and a[val][i] != 0) {
				dis[i] = a[val][i];
				source[i] = min;
			}

		}



	}

	fcout << cost << endl;


}



