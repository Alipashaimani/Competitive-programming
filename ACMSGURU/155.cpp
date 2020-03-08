 #include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int in[50000 + 100];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	pair <pie, int> a[n + 1];
	reu(i, 1, n){
		cin >> a[i].p1.p1 >> a[i].p2;
		a[i].p1.p2 = i;
	}
	sort(a + 1, a + n + 1);
	int P[n + 1];
	pie Ch[n + 1];
	mset(P, 0);
	reu(i, 0, n)
		Ch[i] = mp(0, 0);
	stack <pair<pie, int> > S;
	S.push(mp(mp(0, 0), -1000000000 - 10));
	reu(i, 1, n){
		in[a[i].p1.p2] = i;
		while(S.top().p2 > a[i].p2)
			S.pop();
		P[a[i].p1.p2] = S.top().p1.p2;
		P[Ch[S.top().p1.p2].p2] = a[i].p1.p2;
		Ch[a[i].p1.p2].p1 = Ch[S.top().p1.p2].p2;
		Ch[S.top().p1.p2].p2 = a[i].p1.p2;
		S.push(a[i]);
	}
	cout << "YES" << endl;
	reu(i, 0, 50000 + 10){
		if(in[i] != 0){
			int x = in[i];
			cout << P[a[x].p1.p2] << ' ' << Ch[a[x].p1.p2].p1 << ' '
				<< Ch[a[x].p1.p2].p2 << endl;
		}
	}
	return 0;
}
