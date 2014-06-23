/*
ID: bornawe1
PROG: numtri
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <limits.h>
#include <stdlib.h>
using namespace std;
fstream fcout;
int big;
int n;
int trav(int i, int j, int sum);
int a[1001][1001];
int b[1001][1001];
int main()
{
    big = INT_MIN;

    fstream fcin;

    fcin.open("numtri.in", ios::in);
    fcout.open("numtri.out", ios::out);
    
    fcin >> n ;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            fcin >> a[i][j];
        }

    }

    
/*    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout<< a[i][j];
        }

        cout<<endl;

    }

    

*/
    trav(1, 1, 0);
    fcout<<big<<endl;

}



int trav(int i, int j, int sum)
{

    sum = sum + a[i][j];

    if(big < sum) {
        big = sum;
    }

    
    if((i+1) <=  n) {
        trav(i+1, j, sum);
        trav(i+1, j+1, sum);
    }



}


