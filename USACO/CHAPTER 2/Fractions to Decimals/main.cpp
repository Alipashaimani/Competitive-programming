/*
 ID: apiv2002
 PROG: fracdec
 LANG: C++14
 */
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6;
int fseen[MAXN];
int fsd[MAXN];
int as, ad, dotpoint = 1e8;
vector <int> answer;

void kcheck(int k){
    if (k % 76 == 0 && k != 0)
        cout << endl;
}

void oou(int z , int &k){
    
    string ans = "";
    while (true){
        if (z < 10){
            
            ans += 48 + z;
            break;
        }
        ans += z % 10 + 48;
        z /= 10;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        
        cout << ans[i];
        k++;
        kcheck(k);
    }
}

int main()
{
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    cin >> as >> ad;
    for (int i = 0; ; i++)
    {
        int am = as / ad;
        answer.push_back(am);
        as %= ad;
        if (as < ad){
            as *= 10;
            if (dotpoint == 1e8 && as != 0)
                dotpoint = i;
        }
        fsd[as] += 1;
        if (fsd[as] == 1)
            fseen[as] = i;
        if (as == 0){
            int k = 0;
            for (int j = 0; j < answer.size(); j++){
                oou(answer[j], k);
                if (j == dotpoint && dotpoint != 1e8)
                {
                    cout << '.';
                    k++;
                    kcheck(k);
                }
            }
            if (dotpoint == 1e8){
                cout << '.';
                k++;
                kcheck(k);
                cout << '0';
            }
            cout << endl;
            return 0;
        }
        if (fsd[as] == 2){
            int k = 0;
            for (int j = 0; j < answer.size(); j++){
                oou(answer[j], k);
                if (j == dotpoint && dotpoint != 1e8){
                    cout << '.';
                    k++;
                    kcheck(k);
                }
                if (j == fseen[as])
                {
                    cout << '(';
                    k++;
                    kcheck(k);
                }
            }
            cout << ')' << endl;
            return 0;
        }
    }
}


