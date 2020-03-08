#include<bits/stdc++.h>
using namespace std;

string s;
int a,adj[100000];
int main(){
    cin >> s >> a;
    for ( int i = 1 ; i < s.size() ; i++){
        if ( s[i] == s[i-1])
            adj[i]++;
        if ( i >= 1)
        adj[i]+=adj[i-1];
    }
    for ( int i = 0 ; i < a; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        cout <<adj[y]-adj[x]<< '\n';
    }
}