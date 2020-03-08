#include <bits/stdc++.h>
using namespace std;
vector<int> vec[20010];
bool mark[20010];
int a,b;
void dfs(int vertex){
    mark[vertex] = 1;
    for ( int i = 0 ; i <vec[vertex].size() ; i++){
        if (mark[vec[vertex][i]]== 0){
            dfs(vec[vertex][i]);
        }
    }
}
bool connected (){
    for ( int i = 1 ; i <= a ; i++){
        if (mark[i] == 0)
            return 0;
    }
    return 1;
}
int main(){
    cin >> a >> b ;
    for ( int i = 0 ; i < b ; i++){
        int x,y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(1);
    if ( connected() && a - 1 == b){
        cout << "YES\n";
        return 0;
        
    }
    cout << "NO\n";
}
