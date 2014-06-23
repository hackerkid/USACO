
/*
ID: bornawe1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int a[60];
int b[60];
int c[60];
int x[60];
int count;
int n;

int boy(int i);
int ok(int i, int j, int k);
fstream fcin;
fstream fcout;

int main()
{   
    fcin.open("checker.in", ios::in);
    fcout.open("checker.out", ios::out);
    fcin>>n;
    boy(0);
    fcout<<count<<endl;
}


int boy(int i)
{
    if(i < n) {

        for (int j = 0; j <n; j++) {

            if(ok(i-j + (n - 1), i+j,j)) {
                a[i-j+(n-1)] = 1;
                b[i+j] = 1;
                c[j] = 1;
                x[i] = j+1;

                boy(i+1);

                a[i-j+(n-1)] = 0;
                b[i+j] = 0;
                c[j] = 0;

            }

        }

    } else {

        count++;
       if(count <= 3) {
        for (int k = 0; k < n; k++) {
            fcout<<x[k];
            if(k != n-1)
                fcout<<" ";
        }
        fcout<<endl;
        }

    }

}

int ok(int i, int j, int k)
{

    if((a[i] == 0) && (b[j] == 0) && c[k] == 0)
        return 1;

    return 0;

}

