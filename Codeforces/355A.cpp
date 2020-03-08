//   ||^_^||     don't try to see my code     ||^_^||   //
#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, d;
    cin >> k >> d;
    if (d == 0){
        if (k == 1)
            cout << "0\n";
        else
            cout << "No solution\n";
        return 0;
    }
    cout << d;

    for (int i = 1; i < k; i++)
        cout << 0;

    return cout << '\n' , 0;
}