#include <bits/stdc++.h>
using namespace std;

set<int> st;

int main(){
    int n;  cin >> n;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(st.upper_bound(x)!=st.end())
            st.erase(st.upper_bound(x));
        st.insert(x);
    }
    cout << st.size() << endl;
    return 0;
}
