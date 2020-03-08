#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1000;
int a[MAXN], b[MAXN], c[MAXN];
stack<int> st;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;  cin >> x;
        a[x]++;
    }

    for(int i=0;i<n;i++){
        int x;  cin >> x;
        b[x]++;
    }

    for(int k = 0; k < 100;k++)
        for(int i=0;i<m;i++){
            while(a[i]>0){
                st.push(i);
                a[i]--;
            }
            while(st.size() && b[m-i-1]>0){
                c[(m-i-1 + st.top())%m]++;
                b[m-i-1]--;
                st.pop();
            }
        }

    for (int i = m-1 ;i>=0; i--){
        while(c[i]>0)
            cout << i << " ", c[i]--;
    }
    return 0;
}