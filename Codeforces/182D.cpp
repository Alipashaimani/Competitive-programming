#include <bits/stdc++.h>
using namespace std;

string a,b,c;
int ans = 0 ;
bool flag = false;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    c=a+b;

    for (int i = 1; i <= min(a.size(), b.size());i++)
        if (a.size() % i == 0 && b.size() % i== 0){
            flag = false;
            for (int j = i; j <= c.size() - i; j+=i)
                if(c.substr(0, i) != c.substr(j, i))
                    flag = true;
            if (!flag)
                ans++;
        }
    cout << ans;
    return 0;
}
