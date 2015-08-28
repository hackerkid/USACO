/*
ID: bornawe1
PROG: ratios
LANG: C++
*/
#include <queue>
#include <fstream>
using namespace std;
struct node {
	int a;
	int b;
	int c;
};

node r1;
node r2;
node r3;
node targ;
int vis[110][110][110];
fstream cout;
fstream cin;



bool check(int x1, int x2, int x3)
{
	ios_base::sync_with_stdio(false);

	int asum;
	int bsum;
	int csum;
	int a;
	int b;
	int c;

	a = 0;
	b = 0; 
	c = 0;

	


	
	asum = x1 * r1.a + x2 * r2.a + x3 * r3.a;
	bsum = x1 * r1.b + x2 * r2.b + x3 * r3.b;
	csum = x1 * r1.c + x2 * r2.c + x3 * r3.c;
	
	if(targ.a == 0) {
		if(asum != 0) {
			return 0;
		}
		a = 1;
	}

	else {
		if(asum == 0) {
			return 0;
		}
	}
	
	if(targ.b == 0) {
		if(bsum != 0) {
			return 0;
		}
		b = 1;
	}

	else {
		if(bsum == 0)
			return 0;
	}
	
	if(targ.c == 0) {
		if(csum != 0) {
			return 0;
		}
		c = 1;
	}

	else {
		if(csum == 0)
			return 0;
	}

//	cout << asum << " " << bsum << " " << csum << endl;
	

	if((a || b || (asum / targ.a) == (bsum / targ.b)) and (b || c || (bsum / targ.b) == (csum / targ.c))) {
		if((!a and (asum % targ.a != 0)) or (!b and (bsum % targ.b != 0)) or (!c and (csum % targ.c != 0))) {
			return 0;
		}
		cout << x1 << " " << x2 << " " << x3 <<" " << bsum / targ.b << "\n";
		return 1;
	}

	return 0;



}
int main()
{
	
	int a;
	int b;
	int c;
	ios_base::sync_with_stdio(false);

	cin.open("ratios.in", ios::in);
	cout.open("ratios.out", ios::out);



	cin >> targ.a >> targ.b >> targ.c;
	cin >> r1.a >> r1.b >> r1.c;
	cin >> r2.a >> r2.b >> r2.c;
	cin >> r3.a >> r3.b >> r3.c;
	
	
	node temp;
	temp.a = 0;
	temp.b = 0;
	temp.c = 0;
	

	for (int a = 0; a < 100; a++) {
		for (int b = 0; b < 100; b++) {
			for (int c = 0; c < 100; c++) {
				if(check(a, b, c)) {
					return 0;
				}
			}
		}
	}

	cout << "NONE\n";



}

