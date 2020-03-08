#include <bits/stdc++.h>
using namespace std;
int d = 0;
char c1[60][60];
bool mark[60][60];
void dfs1(char c1[60][60], int a, int c, int i) {
	mark[a][i] = 1;
	if (mark[a][i + 1] == 0 && c1[a][i + 1] == 'A' + c) {
		dfs1(c1, a, c + 1, i + 1);
	}
	if (mark[a][i - 1] == 0 && c1[a][i - 1] == 'A' + c) {
		dfs1(c1, a, c + 1, i - 1);
	}
	if (mark[a + 1][i] == 0 && c1[a + 1][i] == 'A' + c) {
		dfs1(c1, a + 1, c + 1, i);
	}
	if (mark[a + 1][i + 1] == 0 && c1[a + 1][i + 1] == 'A' + c) {
		dfs1(c1, a + 1, c + 1, i + 1);
	}
	if (mark[a + 1][i - 1] == 0 && c1[a + 1][i - 1] == 'A' + c) {
		dfs1(c1, a + 1, c + 1, i - 1);
	}
	if (mark[a - 1][i] == 0 && c1[a - 1][i] == 'A' + c) {
		dfs1(c1, a - 1, c + 1, i);
	}
	if (mark[a - 1][i + 1] == 0 && c1[a - 1][i + 1] == 'A' + c) {
		dfs1(c1, a - 1, c + 1, i + 1);
	}
	if (mark[a - 1][i - 1] == 0 && c1[a - 1][i - 1] == 'A' + c) {
		dfs1(c1, a - 1, c + 1, i - 1);
	}
	d = max(d, c);
}


int main() {
    int a, b, cnt = 1;
    cin >> a >> b;
    while(1){
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                cin >> c1[i][j];
            }
        }
        cout << "Case " << cnt++ << ": ";
        for (int i = 1; i <= a; ++i) {
        	for (int j = 1; j <= b; ++j) {
        		if (c1[i][j] == 'A') {
        			dfs1(c1, i, 1, j);
        		}
        	}
        }
        cout << d << '\n';
        int p, q;
        cin >> p >> q;
        if (p == 0 && q == 0) {
            return 0;
        }
		else {
			a = p;
			b = q;
        }
		for (int i = 0; i < 60; ++i) {
        	for (int j = 0; j < 60; ++j) {
        		c1[i][j] = 0;
				mark[i][j] = 0;
        	}
        }
        d = 0;
    }
}

