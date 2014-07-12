/*
ID: bornawe1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int n;
    int one;
    int two;
    int three;
int main()
{
    int count = 0;
    fstream fcin;
    fstream fcout;

    fcin.open("sort3.in", ios::in);
    fcout.open("sort3.out", ios::out);

    fcin>>n;

    int a[1000];

    for (int i = 0; i < n; i++) {
        fcin>>a[i];
        if(a[i]==1)
            one++;
        if(a[i]==2)
            two++;
    }

    for (int i =  0; i < one; i++) {
        for (int j = one; j < (one + two); j++) {
            if(a[i] == 2 and a[j] == 1) {
                count++;
                swap(a[i], a[j]);
            }
        }
    }

    for (int i = one; i < n; i++) {
        for (int j = 0; j < one; j++) {
            if(a[i] == 1 and a[j] != 1) {
                swap(a[i], a[j]);
                count++;
            }
        }
    }

    for (int j = (one + two); j < n; j++) {
        if(a[j] == 2) 
            count++;
    }


    fcout<<count<<endl;

}







        


    

