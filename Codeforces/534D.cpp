#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1000;
vector<int> arr[MAXN], ans;
int cnt = 0 ;

int main(){
    int n;  cin >> n;
    for (int i = 0; i < n; i++){
        int x;  cin >> x;
        arr[x].push_back(i+1);
    }

    while (cnt >= 0){
        if(arr[cnt].size()){
            ans.push_back(arr[cnt].back());
            arr[cnt++].pop_back();
        }
        else
            cnt -= 3;
    }

    if (ans.size() == n){
        cout << "Possible\n";

        for (auto i : ans)
            cout << i << " ";

        return cout << endl, 0;
    }
    return cout << "Impossible" << endl ,0;
}