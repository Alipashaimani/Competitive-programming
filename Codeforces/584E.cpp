#include<bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " " << x << endl;

const int MAXN = 1e4 + 100;
int n, a[MAXN], b[MAXN], pos[MAXN], cnt;
vector<pair<int,int> > ans;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);


    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
        pos[b[i]] = i;
    }

    for (int i = 0; i < n; i++){
        int _pos = 0;
        for (int j = i; j < n; j++)
            if (a[j] == b[i])
                _pos = j;

        for (int j = _pos-1; j>=i ;j--)
            if (pos[a[j]] >= _pos){
                ans.push_back({_pos, j});
                cnt += _pos - j;
                swap(a[_pos], a[j]);
                _pos = j;
            }
    }
    cout << cnt << '\n' << ans.size() << '\n';

    for (auto i:ans)
        cout << i.first+1 <<" "<< i.second+1 << '\n';

    return 0;
}
