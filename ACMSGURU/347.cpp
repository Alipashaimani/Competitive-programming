#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 110;
string s[maxn];
vector<int> adj[maxn];
int indeg[maxn];
int n;
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i != j)
				if(s[i] + s[j] < s[j] + s[i])
					adj[i].PB(j), indeg[j]++;
	for(int i = 0; i < n; i++)
		if(!indeg[i])
			Q.push(i);
	string ret;
	while(Q.size()){
		int v = Q.front();
		ret += s[v];
		for(int i = 0; i < adj[v].size(); i++){
			indeg[adj[v][i]]--;
			if(indeg[adj[v][i]] == 0)
				Q.push(adj[v][i]);
		}
		Q.pop();
	}
	cout << ret << endl;
	return 0;
}
