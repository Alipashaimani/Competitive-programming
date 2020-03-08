#include <bits/stdc++.h>
using namespace std;

deque<long long> dq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    --m;
    dq.push_back(n);
    while (--n) {
        if (m & 1)
            dq.push_back(n);
        else
            dq.push_front(n);

        m /= 2;
    }

    for(auto a:dq)
        cout << a << " ";

    return cout << '\n' , 0;
}