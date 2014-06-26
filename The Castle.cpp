/*
ID: bornawe1
PROG: castle
LANG: C++
*/

//USACO Training Gateway THe Castle IOI'94-Day 1 : Vishnu KS
#include <fstream>
#include <iostream>
int a[100][100];
int nei[100][100];
int size[10000];
int count;
int m;
int n;

int ii;
int jj;
char loc;
using namespace std;

fstream fcin;
fstream fcout;

int go()
{
    int temp = 0;
    int t;

    do {
        temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j] == -2) {
                    temp++;
                    a[i][j] = count;
                    t = nei[i][j];
                        
                        if(t == 0||t == 2 || t == 4 || t == 1 || t == 5 || t == 6 || t == 3 || t == 7)

                        if(a[i+1][j]== 0) {
                            a[i+1][j] = -2;
                        }


                        if(t == 0||t == 2 || t == 4 || t == 8 || t == 6|| t == 10 || t == 12|| t == 14)

                        if(a[i][j-1] == 0) {
                            a[i][j-1] = -2;
                        }

                        if(t == 0||t == 1 || t == 2|| t == 8  || t == 3|| t == 10 || t == 11|| t == 9)

                        if(a[i][j+1] == 0) {
                            a[i][j+1] = -2;
                        }

                        if(t == 0||t == 1|| t == 4|| t == 8 || t == 5|| t == 12 || t == 9|| t == 13)

                        if(a[i-1][j] == 0) {
                            a[i-1][j] = -2;
                        }


                }


            }


        }



    } while(temp);


}


int findBIG()
{
    int t;
    int big = -100;
    int temp = 0;

    for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
           

            t = nei[i][j];
            if(i != 0) {
                if(t == 2 || t == 3|| t == 6 || t == 10|| t == 11||t == 7 || t == 14|| t == 15) {
                    if(a[i][j] != a[i-1][j]) {
                        
                        temp = size[a[i][j]] + size[a[i-1][j]];
                        if(temp > big){
                            big = temp;
                            ii = i+1;
                            jj = j+1;
                            loc = 'N';
                        }
                    }

                }
            }


            if(j+1 != m) {

                if(t == 4 || t == 6|| t == 5 || t == 12|| t == 7||t == 14|| t == 13|| t == 15) {
                    if(a[i][j] != a[i][j+1]) {
                        temp = size[a[i][j]]+ size[a[i][j+1]];
                        if(temp > big){
                            cout<<endl<<" e "<<" temp "<<temp <<" big"<<big<<endl; 
                            big = temp;
                            ii = i+1;
                            jj = j+1;
                            loc = 'E';


                        }


                    }

                }

            }

        }

    }


    fcout<<big<<endl;
    fcout<<ii<<" "<<jj<<" "<<loc<<endl;


}

int trans()
{
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[j][i];
        }

    }

}
int main()
{
    int k;
    fcin.open("castle.in", ios::in);
    fcout.open("castle.out", ios::out);

    fcin>>m;
    fcin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fcin>>nei[i][j];
        }

    }

    trans();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if(a[i][j] == 0) {
                count++;
                a[i][j] = -2;
                go();
            }

        }

    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            k = a[i][j];
            size[k]++;      
        }
    }


    int min = -1;
    for (int i = 1; i <= count; i++) { 
       if(size[i] > min) {
           min = size[i];
       }
    }

    fcout<<count<<endl;
    fcout<<min<<endl;

    findBIG();




}


