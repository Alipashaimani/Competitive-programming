#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p1=0, p2=0, cnt = 0;

int main(){
    ll n; cin >> n;

    for(ll i = 2;i * i <= n;i++){
        if(n%i==0){
            cnt++;
            if(p1==0)
                p1 = i;
            else if(p2==0)
                p2 = i;
            n/=i;
            while(n%i==0) n/=i, cnt++;
        }
    }
    if(n!=1){
        cnt++;
        if(p1==0)
            p1 = n;
        else if(p2==0)
            p2 = n;
    }

    if(cnt<=1)
        cout << "1\n0\n";

    else if(cnt==2)
        cout << "2\n";

    else{
        if(p2==0)
            p2 = p1;
        cout << "1\n" << p1*p2 << "\n";
    }
    return 0;
}
