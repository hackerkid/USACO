#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    vector <int> a;

    int m;
    int n;
    int i;
    int j;
    float dmax;
    int d;
    int r;


    cin>>n;
    cin>>m;

    a.push_back(1);
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {

            r = i*i + j*j;

            a.push_back(r);

        }

    }


    sort(a.begin(), a.begin()+ a.size());
/*    for (i = 0; i < a.size(); i++) {
        cout<<a[i]<<endl;
    }
*/

    dmax = ((m*m - 1)/n);
    int k;
    cout<<a.size();
    for (int d = 1; d <= n; d++) {
        for (i = 0; i < a.size(); i++) {
            k = 0;
            for (j = 1; (j <= n) && (k < a.size()); j++) {
                cout<<j*d<<endl;
                while ((a[k] != (a[i] + j*d)) && (k < a.size())) {
                    k++;
                }

            }
//            cout<<k<<endl;
            if( k < a.size()) {
               cout<<a[i]<<" "<<d<<endl;
            }

        }


    }


}






