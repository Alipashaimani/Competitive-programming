#include <bits/stdc++.h>
using namespace std;
int n, c, k;
deque<pair<int,int >>mx,mn;
bool flag = false;
int mn2,mx2;
int main(){
    cin >> n >> c >> k;
    for (int i = 0 ; i < n ; i++){
        int x ; cin >> x;
        if (mx.empty())
            mx.push_back({x,i});
        else {
            while(!mx.empty() && mx.back().first < x)
                mx.pop_back();
            
            mx.push_back({x,i});
        }
        if ( i+1 >= c){
        while(!mx.empty() && mx.front().second <= i - c)
            mx.pop_front();
            mx2 = mx.front().first;
        }

        if (mn.empty())
            mn.push_back({x,i});
        else{
            while(!mn.empty() && mn.back().first > x)
                mn.pop_back();
            mn.push_back({x,i});
        }
        if (i+1 >= c){
            while(!mn.empty() && mn.front().second <= i-c)
                mn.pop_front();
            mn2 = mn.front().first;
        }
        if ( i+1 >= c && (mx2 - mn2) <= k){
            flag = true;
            cout << i-c+2 << endl;
        }
    }
    if (!flag)
        cout << "NONE\n";
    return 0;
}
