/*
ID: bornawe1
PROG: skidesign
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
long long int cal(int i, int j);
int mind;
int a[500];
int maxd;

bool wow(int a, int b)
{
	if( a > b)
		return 1;

	return 0;
}

int main()
{
	fstream fcin;
	fstream fcout;

	fcin.open("skidesign.in", ios::in);
	fcout.open("skidesign.out", ios::out);
	long long ans;
	long long temp;
	long long half;
	int x;
	int n;

	ans = 0;

	mind = 1000;
	maxd = -1000;
	fcin >> n;
	for (int i = 0; i < n; i++) {
		fcin >> x;
		a[i] = x;
		mind = min(mind, x);
		maxd = max(maxd, x);
	}
	sort(a, a +n, wow);
	for (int i = 0, j = n-1; i  < n; i++, j--) {
		if(a[i] >= maxd || a[j] <= mind) {
			maxd = max(a[i], maxd);
			mind = min(mind,a[j]);
			ans += cal(i, j );
		}


	}



	fcout << ans<<endl;
}




long long int cal( int i, int j)
{
	long long ans;
	long long half;
	long long temp;
	if(maxd - mind > 17) {
		ans = (maxd - mind) - 17;
		temp = ans / 2;
		half = ans - temp;
		ans = half * half + temp * temp;
		mind = mind + half;
		maxd = maxd + temp;
		a[i] = maxd;
		a[j] = mind;
	}

	else {
		if(maxd - mind < 17) {
			half = 17 - mind;
			temp = half - maxd;
			ans = mind * mind + temp * temp;
			mind = 0;
			maxd = half;
			a[i] = maxd;
			a[j] = mind;
		}

		else {
			ans = 0;
		}

	}


	return ans;
}


			




	


