/*
ID: bornawe1
PROG: money
LANG: C++
*/


#include <iostream>
#include <fstream>


using namespace std;
long long a[10001][26];
long long x[40];
int main()
{
    long long v;
    long long n;

    fstream fcin;
    fstream fcout;

    fcin.open("money.in", ios::in);
    fcout.open("money.out", ios::out);

    fcin >> v;
    fcin >> n;

    for (int i = 1; i <= v; i++) {
        fcin >> x[i];
    }

    for (long long i = 1; i <= v; i++) {
        a[0][i] = 1;
    }

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= v; j++) {
            if(i - x[j] >= 0) {
                a[i][j] = a[i][j-1] + a[i-x[j]][j];
            }

            else {
                a[i][j] = a[i][j-1];
            }

        }

    }



    fcout<<a[n][v]<<endl;

    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <= v; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


    

}
