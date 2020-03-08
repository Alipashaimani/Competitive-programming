#include <bits/stdc++.h>
using namespace std;

int taxi = 0, pizza = 0, girl = 0;
vector< string > t, p, g;

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; ++i){
        int m; string name;

        cin >> m >> name;

        vector< int > cnt(3);
        for(int j = 0; j < m; ++j){
            string number; cin >> number;
            int x = -1;
                int nott = 0, notp = 0;
                for(int k = 0, prev = '9' + 1; k < number.size(); ++k){
                    if(number[k] == '-') continue;
                    nott |= number[k] != number[0];
                    notp |= number[k] >= prev;
                    prev = number[k];
                }
                if(not nott) x = 0;
                else if(not notp) x = 1;
                else x = 2;

            ++cnt[x];
        }
        if(cnt[0] > taxi){taxi = cnt[0]; t.clear();}

        if(cnt[1] > pizza){ pizza = cnt[1]; p.clear();}

        if(cnt[2] > girl){ girl = cnt[2]; g.clear();}

        if(cnt[0] == taxi) t.emplace_back(name);

        if(cnt[1] == pizza) p.emplace_back(name);

        if(cnt[2] == girl) g.emplace_back(name);
    }

    cout << "If you want to call a taxi, you should call: ";
    for(int i = 0; i < t.size(); ++i){
        cout << t[i];
        if(i + 1 != t.size())
            cout << ", ";
        else
            cout << ".\n";
    }

    cout << "If you want to order a pizza, you should call: ";
    for(int i = 0; i < p.size(); ++i){
        cout << p[i];
        if(i + 1 != p.size())
            cout << ", ";
        else
            cout << ".\n";
    }
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i = 0; i < g.size(); ++i){
        cout << g[i];
        if(i + 1 != g.size())
            cout << ", ";
        else
            cout << ".\n";
    }
    return 0;
}
