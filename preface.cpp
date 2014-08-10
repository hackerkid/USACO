#include <iostream>
using namespace std;

int a[7];
int main()
{
    int x;
    int val[7];

    val[0] = 1000;
    val[1] = 500;
    val[2] = 100;
    val[3] = 50;
    val[4] = 10;
    val[5] = 5;
    val[6] = 1;

    cin>>x;

    while(x) {
        for (int i = 0; i < 7; i++) {
            if(x - val[i] >= 0) {
                x = x- val[i];
                a[i]++;
                if(a[i] == 4) {
                    a[i] = 1;
                    a[i-1]++;
                }
            }

        }

    }

    for (int i = 0; i < 7; i++) {
        cout<<val[i]<<" is"<<a[i]<<endl;
    }

}





