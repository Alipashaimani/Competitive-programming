#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 100;
int a[MAXN];
vector <int> vec;
double x;

int main(){
    int n,m;    cin >> n >> m;
	for (int i = 0 ; i < n ; i++)
        cin >> a[i] >> x;

	for (int i = 0 ; i < n ; i++){
		int ind = upper_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
		if (ind == vec.size())
			vec.push_back(a[i]);
		else
			vec[ind] = a[i];
	}
	return cout << n - vec.size() ,0;
}