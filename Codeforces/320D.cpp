#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;

int n, arr[MAXN], ans[MAXN];
stack<int>st;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    st.push(0);
    ans[0] = -1;
    int mx = 0;

    for (int i = 1; i < n; i++) {
        int cur = 0;

        while (!st.empty() && arr[i] >= arr[st.top()]) {
            cur = max(cur, ans[st.top()] + 1);
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;

        else
            ans[i] = cur;

        st.push(i);
        mx = max(mx, ans[i] + 1);
    }
    return cout << mx << '\n' ,0;
}
