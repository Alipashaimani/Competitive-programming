#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x <<  " " << x << endl;

int idx = 0, be = 0, msz = 0, pos = 0;
string arr[15];

bool cmp(string a, string b){return a.size() < b.size();}

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(0);     cout.tie(0);
    string s; cin >> s;
    int n;  cin >> n;

    for (int i = 0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n, cmp);

    for (int i = 0; i < s.size(); i++){
        bool flag = false;
        for (int j = 0; j<n; j++){
            if (be + arr[j].size() - 1 <= i && s.substr(i-arr[j].size()+1, arr[j].size()) == arr[j]){
                idx = j;
                flag = true;
                break;
            }
        }
        if (flag){
            int sz = i - be;
            if (sz > msz){
                pos = be;
                msz = sz;

            }
            be = i - arr[idx].size() + 2;
        }
    }
    int len = s.size() - be;
    if (len > msz){
        pos = be;
        msz = len;
    }
    return cout << msz << " " << pos <<'\n', 0;
}