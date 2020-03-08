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

const int maxn = 150;
bool u[maxn][maxn];
ll scr[maxn][maxn];
int n, m;
string s;
int dir=0;
ll ans=0;

int main(){
	ios_base::sync_with_stdio(false);
    cin>>n>>m;
    FOR(i, 1, n){
        FOR(j, 1, m){
            char c;
            cin>>c;
            scr[i][j]=c-48;
        }
    }
    cin>>s;
    pie p=mp(1, 1);
    rep(i, s.size()){
        if(s[i]=='L')
            dir--;
        else if(s[i]=='R')
            dir++;
        else{
            if(dir==0){
                if(u[p.p1][p.p2])
                    ans+=scr[p.p1][p.p2]/2;
                else
                    ans+=scr[p.p1][p.p2];
                if(u[p.p1-1][p.p2])
                    ans+=scr[p.p1-1][p.p2]/2;
                else
                    ans+=scr[p.p1-1][p.p2];
                u[p.p1][p.p2]=true;
                u[p.p1-1][p.p2]=true;
                p.p2++;
            }
            else if(dir==1){
                if(u[p.p1][p.p2])
                    ans+=scr[p.p1][p.p2]/2;
                else
                    ans+=scr[p.p1][p.p2];
                if(u[p.p1][p.p2-1])
                    ans+=scr[p.p1][p.p2-1]/2;
                else
                    ans+=scr[p.p1][p.p2-1];
                u[p.p1][p.p2]=true;
                u[p.p1][p.p2-1]=true;
                p.p1++;
            }
            else if(dir==2){
                if(u[p.p1-1][p.p2-1])
                    ans+=scr[p.p1-1][p.p2-1]/2;
                else
                    ans+=scr[p.p1-1][p.p2-1];
                if(u[p.p1][p.p2-1])
                    ans+=scr[p.p1][p.p2-1]/2;
                else
                    ans+=scr[p.p1][p.p2-1];
                u[p.p1-1][p.p2-1]=true;
                u[p.p1][p.p2-1]=true;
                p.p2--;
            }
            else{
                if(u[p.p1-1][p.p2-1])
                    ans+=scr[p.p1-1][p.p2-1]/2;
                else
                    ans+=scr[p.p1-1][p.p2-1];
                if(u[p.p1-1][p.p2])
                    ans+=scr[p.p1-1][p.p2]/2;
                else
                    ans+=scr[p.p1-1][p.p2];
                u[p.p1-1][p.p2-1]=true;
                u[p.p1-1][p.p2]=true;
                p.p1--;
            }
        }
        dir+=4;
        dir%=4;
    }
    cout<<ans<<endl;
	return 0;
}
