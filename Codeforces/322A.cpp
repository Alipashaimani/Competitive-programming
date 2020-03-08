#include <bits/stdc++.h>
using namespace std ;

int main (){

    int n, m;   cin >> n >> m;

    if(m == 0 || n == 0)
        return cout << 0  << endl ,0;

        cout << m + n - 1 << endl;

        for(int i = 1; i <= n; i++)
            cout << i << " " << 1 << endl;

        for(int i = 2; i <= m; i++)
            cout<< 1 << " " << i << endl;
}
