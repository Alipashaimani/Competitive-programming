#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int main(){
    string s;   cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    return cout << (st.empty() ? "YES" : "NO") << '\n' , 0;
}