#include <bits/stdc++.h>
using namespace std;
vector<long long> a,a2,a3,a4;
long long n,m,k,s,x;
int main(){

    cin >> n >> m >> k >> x >>s;
    a.push_back(x);
    a2.push_back(0);
    a3.push_back(0);
    a4.push_back(0);
    for (int i = 0; i < m; i++){
        long long x;
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++){
        long long x;
        cin>>x;
        a2.push_back(x);
    }

    for (int i = 0; i < k; i++){
        long long x;
        cin>>x;
        a3.push_back(x);
    }

    for (int i=0; i<k; i++){
        long long x;
        cin>>x;
        a4.push_back(x);
    }
    long long M=-1;
    for (int i=0; i<=m; i++)
    {
        if(a2[i]>s)
            continue;
        long long p=s-a2[i];
        long long ind = upper_bound (a4.begin(), a4.end(), p)-a4.begin();
        ind--;
        long long time=(n-a3[ind])*a[i];
        if(time<M || M==-1) M=time;
    }
    cout<<M<<endl;
}