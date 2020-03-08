#include <bits/stdc++.h>
using namespace std;

struct node {
    node *child[10];
    bool exist;
    node(){
        memset(child, 0, sizeof(child));
        exist = false;
    }
};

void erase(node *n) {
    if (!n)
        return;
    for (int i = 0; i < 10; ++i)
        if (n->child[i]) {
            erase(n->child[i]);
            delete n->child[i];
        }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        char s[11];
        bool ans = true;
        node *head = new node();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            if (!ans)
                continue;
            node *n = head;
            for (char *p = s; *p; ++p) {
                if (n->exist) {
                    ans = false;
                    break;
                }
                if (!n->child[*p - '0'])
                    n->child[*p - '0'] = new node();
                n = n->child[*p - '0'];
            }
            n->exist = true;
            for (int i = 0; i < 10; ++i)
                if (n->child[i] && n->child[i]->exist)
                    ans = false;
        }
        cout << (ans? "YES": "NO") << '\n';
    }
    return 0;
}
