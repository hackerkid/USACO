#include <iostream>
#include <limits.h>
#include <fstream>
int a[500];
int n;
int big;
using namespace std;

int trav(int i)
{
    int p;
    if((2*i + 1) <=  n) {
        trav(2*i);
        trav(2*i +1);
    }

    p = i/2;

    if(a[p]+a[i] > a[i]) {
        a[i] = a[p] + a[i];
        
    }

    if(a[i] > big) {
        big = a[i];
    }


}




    

    


int main()
{
    fstream fcin;
    fcin.open("numtri.in", ios::in);
    int i;
    int t;
    int x;
    big = INT_MIN;

    fcin>>t;

    n = (t*(t+1))/2;

    a[0] = 0;

    for (i = 1; i <= n; i++) {
        fcin>>x;
        a[i] = x;
    }

    trav(1);
    cout<<big<<endl;

}






