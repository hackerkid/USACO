
/*
ID: bornawe1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int a[15];
int primer(long int x);
int bro(int n, long int x);
fstream fcout;
int main()
{
    
    fstream fcin;

    fcin.open("sprime.in", ios::in);
    fcout.open("sprime.out", ios::out);
    int n;
    fcin>>n;

    bro(n, 0);

}


int bro(int n, long int x)
{
    long int temp;
    if(n > 0) {
        for (int i = 0; i <= 9; i++) {
            temp = i + 10 * x;
            if(primer(temp)) {
                bro(n-1, temp);
            }

        }


    } else {

        fcout<<x<<endl;
    }

}

int primer(long int x)
{
    if(x == 1)
        return 0;
    if(x == 2)
        return 1;
    if( x % 2 == 0)
        return 0;


    for (int i = 3; i *i <= x; i =  i + 2) {
        if(x % i == 0)
            return 0;

    }

    return 1;

}











