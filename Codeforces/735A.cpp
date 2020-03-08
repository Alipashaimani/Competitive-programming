#include <bits/stdc++.h>
using namespace std;
int m,n,a,b;
string s;
int main(){
    cin >> n >> m >> s;
    for (int i = 0 ; i < s.size() ; i++){
        if ( s[i] == 'G')
            a = i;
        else if ( s[i] == 'T')
            b = i;
    }
    if ( abs(b - a ) % m == 0 ){
        if ( b < a){
            swap(s[a],s[b]);
            swap(a,b);
        }
        if ( a < b){
            for ( int i = a ; i <= b ; i+= m){
                if ( s[i] == '#'){
                    cout << "NO\n";
                    return 0;
                }
            }
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}