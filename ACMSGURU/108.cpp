#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MP make_pair
#define L first
#define R second

bool arr[100];
int ans[5000], digsum[500000];
pii que[5000];
int n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> que[i].L;
		que[i].R = i;
	}
	for(int i = 1; i < 500000; i++)
		digsum[i] = digsum[i / 10] + (i % 10);
	sort(que, que + k);
	int cnt = 0, pos = 0;
	for(int i = 1; i <= n; i++){
		cnt += !arr[i % 100];
		arr[i % 100] = 0;
		while(pos < k and que[pos].L == cnt)
			ans[que[pos].R] = i, pos++;
		int sum = 0, an = i;
		while(an >= 500000)
			sum += an % 10, an /= 10;
		sum += digsum[an];
		arr[(i + sum) % 100] = true;
	}
	cout << cnt << '\n';
	for(int i = 0; i < k; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
