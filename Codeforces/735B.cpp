#include <bits/stdc++.h>
using namespace std;
int m;
long double a,b;
long double ans1,ans2 ;
vector<int>vi;
string s;
int main(){
    cin >> m >> a >> b;
    for (int i = 0 ; i < m ; i++){
        int x;
        cin >> x;
        vi.push_back(x);
    }
    sort(vi.begin(),vi.end());
    if ( a > b )
        swap(a,b);
    for ( int i = m-a ; i < m ; i++){
        ans1 += vi[i];
    }
    ans1/=a;

    for ( int i = m-a-b ; i < m-a ; i++){
        ans2+=vi[i];
    }
    ans2/=b;

    cout << fixed << setprecision(6) << (ans2+ans1) << '\n';

}