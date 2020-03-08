#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e6 + 100;
char c[MAXN];
int a[MAXN],ans[3], n;

int main(){
    cin >> n;
    for (int i = 0 ; i < n; i++){
        char x;
        cin >> x >> a[i];
        c[i] = x;
    }
    for ( int i = 0 ; i < 10 ; i++){
        int x = 0,y =1;
        int  bi = 1 << i;
        for (int i = 0 ; i < n ;i++){
            int gp = a[i] & bi;

            if(gp)
                gp = 1;

            if(c[i]=='&'){
                x &= gp;
                y &= gp;
            }
            else if(c[i]=='|'){
                x |= gp;
                y |= gp;
            }
            else{
                x ^= gp;
                y ^= gp;
            }
        }

        if(!x&&!y);
        else if((x==0) && (y ==1)){
            ans[0]+= bi;
        }
        else if((x==1) && (y ==0)){
            ans[0]+= bi;
            ans[1]+= bi;
        }
        else{
            ans[0]+= bi;
            ans[2]+= bi;
        }
    }
    cout << "3\n";
    cout << "& " << ans[0] << '\n';
    cout << "^ " << ans[1] << '\n';
    cout << "| " << ans[2] << '\n';
    return 0;
}