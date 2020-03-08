#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MAXN = 100 + 10;
int n,m;
pair<int,pair<int,int> > val[MAXN];
bool check (int mid){
	int n2 = n;
	pair<int,pair<int,int> > val2[MAXN];

	for ( int i = 0 ; i < m ; i++)
		val2[i] = val[i];


	bool item[7];
	fill(item,item+7,false);


	sort(val2,val2+m);

	for ( int i = 0 ; i < m ; i++){
		if (item[val2[i].X] == false && val2[i].Y.Y >= mid){
			item[val2[i].X] = true;
			n2-=val2[i].Y.X;
			if ( n2 < 0)
				return 0;
		}
	}
	for ( int i = 1 ; i <= 6 ; i++){
		if ( item[i] == false)
			return 0;
	}
	return 1;
}
int main(){
cin >> m >> n;
	for ( int i = 0 ; i < m ; ++i ) 
		cin >> val[i].X >> val[i].Y.X >> val[i].Y.Y;
	 int l = 0 ,r = 1e9+1;
        while(l+1<r){
            int mid = ( l + r) /2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        cout << l << '\n';

}

