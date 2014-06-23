/*
ID: bornawe1
PROG: pprime
LANG: C++
*/
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int length(int x);
int boy(int size, int ii);
int st[100];

int primer(int x);
vector <long int> a;
vector <long int> b;

int main()
{

    int aa;
    int bb;
    int la;
    int lb;
    int sta;
    int i;
    b.push_back(5);
    b.push_back(7);
    fstream fcin;
    fstream fcout;
    fcin.open("pprime.in", ios::in);
    fcout.open("pprime.out", ios::out);
    fcin>>aa;
    fcin>>bb;

    la = length(aa);
    lb = length(bb);
    
    for(int i = 2; i <= lb; i++) {
        boy(i, 1);
    }

    for (int i = 0; i < a.size(); i++) {
        if(primer(a[i]) == 1) {
            b.push_back(a[i]);
           
           
        }
    }

  for (i = 0; i < b.size(); i++) {
        if(b[i] <= bb && b[i] >= aa) {
        fcout<<b[i]<<endl;
        }
    }


/*    for (int i = sta; i < b.size(); i++) {
        if(b[i] <= bb) {
            fcout<<b[i]<<endl;
        }
    }
*/




}


int primer(int x)
{
    if(x%2 == 0)
        return 0;

    for (int i = 3; i*i <= x; i = i +2) {
        if((x%i) == 0) {
            return 0;
        }

    }


    return 1;
}



int length(int x)
{

    int size;
    size = 0;

    while(x) {
        x = x/10;
        size++;
    }


    return size;
}


int boy(int size, int ii) 
{
    
    int i;
    int sz;
    long int temp;
    sz = size - 1;

    i = ii - 1;

  //  if((size -ii != ii-1) && (size - ii != ii - 2)) {
      if((sz - i) >= i) {
        for (int j = 0; j <= 9; j++) {
            
            if(ii == 1 && j %2 == 0) {
                continue;
            }


            st[i] = j;
            st[sz-i] = j;
/*            if(i == (sz - i)) {
                cout<<"lol"<<endl;
            }
            
 */
            boy(size, ii+1); 
        }


    } else {
        
        temp = 0;
        for (int i = 0; i < size; i++) {
            temp = temp + (st[i] * pow(10, i));
        }

        a.push_back(temp);
    }






}








