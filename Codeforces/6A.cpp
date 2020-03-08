#include <bits/stdc++.h>
using namespace std;

int a[4];

int main(){

    for (int i = 0 ; i < 4 ; i++)
        cin >> a[i];

    sort(a,a + 4);

    if(a[0] + a[1] > a[2] || a[1] + a[2] > a[3])
        return cout<<"TRIANGLE\n", 0;

    if(a[0] + a[1] == a[2] || a[1] + a[2] == a[3])
        return cout<<"SEGMENT\n", 0;

    return cout<<"IMPOSSIBLE\n", 0;
}