#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

string n;

void dev(){
    int m = 0;
    for(int i = 0; i < n.size(); i++){
        int t = n[i] % 2;
        n[i] = 48 + (n[i] - 48 + 10 * m) / 2;
        m = t;
    }
}

void mins(){
    n[n.size() - 1]--;
    int i = n.size() - 1;
    while(n[i] < 48){
        n[i - 1]--;
        n[i] += 10;
        i--;
    }
}

void print(){
    bool x = false;
    for(int i = 0; i < n.size(); i++){
        if(n[i] > 48)
            x = true;
        if(x)
            cout << n[i];
    }
    cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n;
    if(n.size()==1){
        char c = n[0];
        switch(c){
        case '3':
            cout << 1 << endl;
            return 0;
        case '4':
            cout << 1 << endl;
            return 0;
        case '5':
            cout << 2 << endl;
            return 0;
        case '6':
            cout << 1 << endl;
            return 0;
        case '7':
            cout << 3 << endl;
            return 0;
        case '8':
            cout << 3 << endl;
            return 0;
        case '9':
            cout << 4 << endl;
            return 0;
        }
    }
    else{
        int a = (n[n.size() - 1] - 48) + 10 * (n[n.size() - 2] - 48);
        if(a % 4 == 2){
            dev();
            mins();
            mins();
        }
        else{
            dev();
            if(a % 2 == 0)
                mins();
        }
        print();
    }
	return 0;
}
