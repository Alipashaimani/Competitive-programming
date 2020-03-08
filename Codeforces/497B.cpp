#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
int w1[MAXN], w2[MAXN];
int c1, c2, pos;
pair<int,int> ans[MAXN];
int id = 0;
//int OUT = 0;
//bool flag = true;

int find(int b, int e, int num) {
    int mid = (b + e)/2;
    if (b - e == -1) {
        if (((w1[b] - w1[pos]) == num) or ((w2[b] - w2[pos]) == num ))
            return b;
        return -1;
    }
    if (((w1[mid - 1] - w1[pos])< num) and ((w2[mid - 1] - w2[pos]) < num))
        return find (mid, e, num);
    return find (b, mid, num);
}

int main(){
    int n;  cin >> n;
    for (int i = 1; i <= n; i++){
        int x;  cin >> x;   x--;
        w1[i] = w1[i-1];    w2[i] = w2[i-1];
        if (x)
            w2[i]++;
        else
            w1[i]++;
    }
    for (int i = 1; i <= n; i++){
         pos = c1 = c2 = 0;
        while (pos < n){
          //  cerr << c1 << " "  << c2 << '\n';

            int loc = find(pos+1, n+1, i);

            if (loc == -1)
                break;

            if (loc != n){
                if (w1[loc] - w1[pos] == i)
                    c1++;
                else
                    c2++;
            }
            else {
                if (w1[loc] - w1[pos] == i){
                    if (c1 >= c2)
                        c1++;
                    else
                        loc = -1;

                }
                else{
                    if (c2 >= c1)
                        c2++;
                    else
                        loc = -1;

                }
            }
            pos = (loc == -1 ? MAXN : loc);
        }
        if (c1 != c2 && n == pos){
            ans[id].first = max(c1, c2);
            ans[id++].second = i;
        }
    }

    cout << id << '\n';
    sort(ans,ans+id);
    for (int i = 0 ; i < id ; i++){
        cout << ans[i].first << " " << ans[i].second <<'\n';
    }

    return 0;

}