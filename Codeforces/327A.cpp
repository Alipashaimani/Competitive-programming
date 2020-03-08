#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int m ;
bool arr[MAXN];
int ans = 0 ;

int main(){
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    for (int i = 0; i < m; i++)
        for (int j = i; j < m; j++){
            int cnt = 0;
            for ( int k = 0; k < m; k++)
                if (k <= j && k >= i && arr[k] == false)
                    cnt++;

                else if (!(k <= j && k >= i) && arr[k] == true)
                    cnt++;

            ans = max(ans, cnt);
        }
    return cout << ans << '\n' , 0 ;
}