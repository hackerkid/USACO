/*
ID: bornawe1
PROG: zerosum 
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
char a[20];
int n;
fstream fcin;
fstream fcout;
int wow(int i, int sum)
{
    
    int temp;
    if(i > n) {
        if(sum == 0) {
            for (int i = 1; i <= n; i++) {
                if(i != 1)
                fcout<<a[i];
                fcout<<i;
            }
            fcout<<endl;

        }

    return 0;

    }
    if(a[i-1] != ' ') {
        temp = sum;
        if(a[i-1] == '+') {
            temp = temp -  (i - 1);
            temp = temp + (i - 1) * 10;
            temp = temp + (i);
            a[i] = ' ';
            wow(i + 1, temp);
        }

        else {
            temp = temp +  (i-1);
            temp = temp - (i -1) * 10;
            temp = temp - (i);
            a[i] = ' ';
            wow(i+1, temp);
        }


    }

    a[i] = '+';
    wow(i + 1, sum + i);
    a[i] = '-';
    wow(i + 1, sum - i);


}

int main()
{
    a[0] = 1;
    a[1] = '+';


    fcin.open("zerosum.in", ios::in);
    fcout.open("zerosum.out", ios::out);


    fcin >> n;

    wow(2, 1);

}



   
