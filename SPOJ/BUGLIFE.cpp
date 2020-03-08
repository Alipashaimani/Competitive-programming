#include <bits/stdc++.h>
using namespace std;
vector<int> vec[2010];
pair<bool,pair<bool,bool> > mark[2010];
bool EX = 0;
int a,b;

void dfs(int vertex){
    mark[vertex].first = true;
    for ( int i = 0 ; i <vec[vertex].size() ; i++){
        if (mark[vec[vertex][i]].second.first == 0){
            mark[vec[vertex][i]].second.first = 1;
            mark[vec[vertex][i]].second.second = !mark[vertex].second.second;
        }
        else if ( mark[vec[vertex][i]].second.first && mark[vec[vertex][i]].second.second == mark[vertex].second.second){
            if(!EX)
                printf("Suspicious bugs found!\n");
            EX = true;
        }
        
        if (mark[vec[vertex][i]].first == 0){
            dfs(vec[vertex][i]);
        }
    }
}
int connected (){
    for ( int i = 1 ; i <= a ; i++){
        if (mark[i].first == 0)
            return i;
    }
    return -1;
}
int main(){
    int t;
    int cnt = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        for ( int i = 0 ; i < b ; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        printf("Scenario #%d:\n",cnt++);
        dfs(1);
        while(connected()!= -1){
            dfs(connected());
        }
        if (!EX)
            printf("No suspicious bugs found!\n");
        
        for ( int i = 0 ; i < 2010 ; i++){
            vec[i].clear();
            mark[i].first = false;
            mark[i].second.first = false ;
            mark[i].second.second = false;
        }
        EX = 0;
    }
}
