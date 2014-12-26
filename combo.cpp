/*
ID: bornawe1
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;


	
bool check(int i, int a, int n) 
{
	
	
	int ii;
	int one;

	one = 0;
	ii = i;

	if(i == a)
		one = 1;

	i++;

	if(i == n+1)
		i = 1;

	if(i == a)
		one = 1;
	i++;
	if(i == n+1)
		i = 1;

	if(i == a)
		one = 1;

	ii--;
	if(ii == 0)
		ii = n;

	if(ii == a)
		one = 1;

	ii--;
	if(ii == 0)
		ii = n;

	if(ii == a)
		one = 1;

	return one;

}

int ok(int i, int j, int k, int a, int b, int c, int n)
{

	if(check(i, a, n) and check(j, b, n) and check(k, c, n))
		return 1;

	else 
		return 0;

}

int main()
{

	fstream fcin;
	fstream fcout;

	fcin.open("combo.in", ios::in);
	fcout.open("combo.out", ios::out);

	int n;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;

	int count = 0;
	
	fcin >> n;
	fcin >> a;
	fcin >> b;
	fcin >> c;
	fcin >> d;
	fcin >> e;
	fcin >> f;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if(ok(i, j, k, a, b, c, n) || ok(i, j, k, d, e, f, n)) {
					count++;
				}

			}

		}

	}

	fcout << count << endl;
}





