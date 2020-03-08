#include <bits/stdc++.h>
using namespace std;

// alipasha
void perm (deque <int> &d) {
    int now = d.front();
    d.pop_front();
    d.push_back(now);
}
int n22, m22;
// alipasha
int main() {

    cin >> n22 >> m22;

    deque <int> v1(n22);
    deque <int> v2(n22);
    deque <int> w1;
    deque <int> w2;

    for (int i=0 ; i < n22;++i)
        cin >> v1[i];

    for (int i=0 ; i < n22;++i)
        cin >> v2[i];

    for(int i = 0; i < v1.size() - 1; ++i) {
        w1.push_back(abs(v1[i] - v1[i + 1]));
        w2.push_back(abs(v2[i] - v2[i + 1]));
    }

    w2.push_back(m22 - v2[v2.size() - 1] + v2[0]);
    w1.push_back(m22 - v1[v1.size() - 1] + v1[0]);

   //alipasha

    for(int i = 0; i < n22; ++i) {
        if(w1 != w2)
            perm(w1);
        else
            return cout << "YES\n", 0;
    }
    cout << "NO\n";
    return 0;
    //alipasha
}