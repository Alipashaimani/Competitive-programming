#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int t = 1;
int l[MAXN], r[MAXN];

int main(){

    ios::sync_with_stdio(0);

    int n, m, s, f; cin >> n >> m >> s >> f;

    for (int i = 0; i < m; i ++){
        int x; cin >> x;
        if (x > MAXN)
            cin >> x >> x;
        else
            cin >> l[x] >> r[x];
    }
    if(s < f){
        while(s < f){
            if(l[t] <= s + 1 && r[t] >= s){
                cout << 'X';
                t ++;
            } else{
                cout << 'R';
                t ++;
                s ++;
            }
        }
        return cout << endl, 0;
    }

    while(f < s){
        if(l[t] <= s && r[t] >= s - 1) {
            cout << 'X';
            t ++;
        }else{
            cout << 'L';
            t ++;
            s --;
        }
    }
    return cout << endl, 0;
}