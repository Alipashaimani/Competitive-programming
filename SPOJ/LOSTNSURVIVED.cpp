#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int par[100009];
int val[100009];
multiset<int> s;
ll maxi=1,mini=1;
int Find(int v) { return v == par[v]? v: par[v] = Find(par[v]);}
void unin(int a,int b){par[Find(b)]=Find(a);}
int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        val[i]=1,par[i]=i,s.insert(1);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        ll a = Find(x);
        ll b = Find(y);
        if(a!=b){
            s.erase(s.find(val[a]));
            s.erase(s.find(val[b]));
            val[a]+=val[b];
            val[b]=0;
            s.insert(val[a]);
            unin(x,y);
        }
        cout<<*(--s.end())- *s.begin() <<endl;
    }
    return 0;
}
