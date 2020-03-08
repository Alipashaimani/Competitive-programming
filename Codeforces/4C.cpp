#include<bits/stdc++.h>
using namespace std;
map<string,int>msi;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string x;
        cin >> x;
        msi[x]++;
        if (msi[x] == 1)
            cout << "OK\n";
        else
            cout << x << msi[x] - 1<<'\n';
    }
    return 0;

}
