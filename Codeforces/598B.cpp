#include<bits/stdc++.h>
using namespace std;

string s;
int n;
void rot(string &s){
    s = s[s.size()-1]+s;
    s.pop_back();
}
void rote(int l, int r, int k){
    string s2 ="";

    for (int i = l ; i <= r ; i++)
        s2+=s[i];

    k %= (r-l)+1;

    while(k--)
        rot(s2);

    int j = 0 ;

    for (int i = l ; i <= r ; i++)
        s[i] = s2[j++];
}
int main(){
    cin >> s >> n;
    for ( int i = 0 ; i < n ; i++){
        int l,r,k;
        cin >> l >> r >> k;
        if ( l != r)
            rote(l-1,r-1,k);
    }
    cout << s << endl;
}