#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1000;

int n, k, a, m, sh;
set <pair<int, int > > st;

int f(int l, int r) {return (r - l + 2) / (a + 1);}

int main(){

    cin >> n >> k >> a >> m;
    st.insert({n, 1});

    sh = f(1, n);

    for (int i = 0 ; i < m ; i++){
        int x;  cin >> x;

        auto it = st.lower_bound({x, -1});

        int l = it -> second, r = it -> first;
        sh -= f(l, r);

        if(x + 1 <= r)
            sh += f(x + 1, r);

        if(x - 1 >= l)
            sh += f(l, x - 1);

        if(sh < k)
            return cout << i + 1 << '\n', 0;

        st.erase(it);

        if(x + 1 <= r)
            st.insert({r, x + 1});

        if(x - 1 >= l)
            st.insert({x - 1, l});

    }
    return cout << -1 << '\n', 0;
}