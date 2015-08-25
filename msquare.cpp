/*
ID: bornawe1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <queue>
#include <map>
#include <fstream>
using namespace std;

struct node{
	string x;
	string track;
};
string ta(string x)
{
	string ans;

	ans = x.substr(4, 4) + x.substr(0, 4);

	return ans;
}

string tb(string x)
{
	string ans;

	ans = x[3] + x.substr(0, 3) + x[7] + x.substr(4, 3);

	return ans;
}

string tc(string a)
{
	string b;
	b = a;

	b[1] = a[5];
	b[2] = a[1];
	b[5] = a[6];
	b[6] = a[2];

	return b;
}


int main()
{

	string x;
	string y;
	string hol;
	char c;

	fstream cin;
	fstream cout;

	cin.open("msquare.in", ios::in);
	cout.open("msquare.out", ios::out);

	for (int i = 0; i < 8; i++) {
		cin >> c;
		hol = hol + c;
	}

	y = hol.substr(0, 4);

	for (int i = 7; i >= 4; i--) {
		y = y + hol[i];
	}

	x = "12348765";

	queue <node> q;
	map <string, int> p;
	
	node temp;
	temp.x = x;
	q.push(temp);
	p[x] = 1;

	string st;

	while(!q.empty()) {
		temp = q.front();
		q.pop();		
		if(temp.x == y) {
			cout << temp.track.length() << endl;
			cout << temp.track << endl;
			return 0;
		}

		st = ta(temp.x);
//		cout <<"ta " << st << endl;

		if(p.count(st) == 0) {
			node wow;
			wow.x = st;
			wow.track = temp.track + 'A';
			q.push(wow);
			p[st] = 1;
		}

		
		st = tb(temp.x);
//		cout <<"tb " << st << endl;
		if(p.count(st) == 0) {
			node wow;
			wow.x = st;
			wow.track = temp.track + 'B';
			q.push(wow);
			p[st] = 1;
		}


		
		st = tc(temp.x);
//		cout <<"tc " << st << endl;
		if(p.count(st) == 0) {
			node wow;
			wow.x = st;
			wow.track = temp.track + 'C';
			q.push(wow);
			p[st] = 1;
		}

	}



}


