#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 100;
int n, m;
pair<string, string>a[MAXN];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;

    for(int i = 0; i <  n;i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++)
            if(s == a[j].first || s == a[j].second){

                if(a[j].first.size() <= a[j].second.size())
                    cout << a[j].first << " ";
                else
                    cout << a[j].second << " ";
            }
    }
    return 0;
}