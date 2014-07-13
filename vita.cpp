/*
ID: bornawe1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

fstream fcin;
fstream fcout;
int a[100][100];
int mini[100];
int ar[100];
int row;
int col;
int ok;


int check(int limit)
{
    int sum;
    int t;
    int bla;

    for (int i = 0; i <= limit; i++) {
        for (int j = i+1; j <= limit; j++) {
            if(ar[i] == ar[j]) {
                return 0;
            }
        }
    }

    bla = 0;
    for (int i = 0; i < col; i++) {
        sum = 0;
        for (int j = 0; j <= limit; j++) {
            t = ar[j];
            sum = sum + a[t][i];
        }

        if(sum >= mini[i]) {
            bla++;
        } 
        
        else {
            return 0;
        }

    }

    if(bla == col) {
        return 1;
    }

    else {
        return 0;
    }

}


int bro(int limit, int count, int sum)
{
    
    int temp;

    if(ok) 
        return 1;

    if(limit < count) {
       if(sum >= mini[0]) {
        if(check(limit)) {
            ok = 1;

            fcout<<limit+1<<" ";
            for (int i = 0; i <= limit; i++) {
                fcout<<ar[i]+1;
                if(i != limit) {
                    fcout<<" ";
                }
            }

            fcout<<endl;
            return 1;
        }
        return 1;
       }
    }

    for (int i = 0; i < row; i++) {
        if(count != 0) {
            if(ar[count-1] >= i) {
                continue;
            }
        }



        temp = sum + a[i][0];
        ar[count] = i;
        bro(limit, count+1, temp);
    }

}



int main()
{

    ok = 0;

    fcin.open("holstein.in", ios::in);
    fcout.open("holstein.out", ios::out);

    fcin >> col;

    for (int i = 0; i < col; i++) {
        fcin >> mini[i];
    }

    fcin >> row;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fcin >> a[i][j];
        }

    }

    for (int i = 0; i < row; i++) {
        bro(i, 0, 0);
    }
}




