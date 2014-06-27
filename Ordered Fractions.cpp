/*
ID: bornawe1
PROG: frac1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct frac
{
    int x;
    int y;
};

int gcd(int a, int b)
{
    if(b == 0) 
        return a;
    
    else 
        return gcd(b, a%b);

}
    
bool check(frac m, frac n)
{
    float a;
    float b;
    float c;
    float d;

    a = m.x;
    b = m.y;

    c = n.x;
    d = n.y;

    if(b/a > d/c) {
        return 1;
    }

    else {
        return 0;
    }

}


    


int main()
{
    vector <frac> a;
    int n;
    frac temp;
    
    fstream fcin;
    fstream fcout;

    fcin.open("frac1.in", ios::in);
    fcout.open("frac1.out", ios::out);

    fcin>>n;

    for (int i = 1; i <=n; i++) {
        for (int j = n; j > 0; j--) {

            if(i == 1) {
                temp.x = i;
                temp.y = j;
                a.push_back(temp);
               
            }


            else { 
                if(i/j < 1) {
                if(gcd(i, j) == 1) {
                temp.x = i;
                temp.y = j;
                a.push_back(temp);
                }
                }

            }

        }

    }

  sort(a.begin(), a.end(), check);
  fcout<<0<<"/"<<1<<endl;
  for (int i = 0; i < a.size(); i++) {
      fcout<<a[i].x<<"/"<<a[i].y<<endl;
  }


}
   

