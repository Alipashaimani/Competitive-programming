#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;

vector<pair<int,pair<int,int > > > vec;
pair<int, int> query[N];

int tree[N], ans[N];
int n;
void add(int i){
    for (;i <= n;i+=i&-i)
        tree[i]++;
}
int sum(int i){
    int s = 0;
    for (;i >= 1;i-=i&-i)
        s+=tree[i];
    return s;
}
int main(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        int x;  cin >> x;
        vec.push_back({x,{1,i}});
    }
    int q;  cin >> q;
    for (int i = 1 ; i <= q ; i++){
        int b,e,x;
        cin >> b >> e >> x ;
        query[i] = {b,e};
        vec.push_back({x,{2,i}});
    }
    
    sort(vec.begin(), vec.end(),greater<pair<int,pair<int,int > > >());
    
    for (auto i : vec){
        if (i.second.first == 1){
            add(i.second.second);
        }
        else{
            ans[i.second.second] = sum(query[i.second.second].second) - sum(query[i.second.second].first -1);
        }
    }
    for (int i = 1 ; i <= q ;i++){
        cout << ans[i] <<'\n';
    }
}

