//in the name of God
#include <bits/stdc++.h>
using namespace std;
string conv_string(int n){
    int x = n;
    string s2;
    while(x) {
        s2 += ((x%10) + '0');
        x /= 10;
    }
    reverse(s2.begin(), s2.end());
    return s2;
}
int main(){
    int a;
    cin>>a;
    string ss;
    for ( int i = a+1 ; ; i++){
        ss=conv_string(i);
        if ( ss[0]!=ss[1] && ss[0]!=ss[2] && ss[0]!=ss[3] && ss[1]!=ss[2]&&ss[1]!=ss[3] && ss[2]!= ss[3]){
            cout<<i;
            break;
        }
    }
}
