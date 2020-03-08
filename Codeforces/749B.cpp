#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
pair<int,int>dot[3];
int main(){
    for ( int i = 0 ; i < 3 ; i++)
        cin >> dot[i].first >> dot[i].second;

    cout << "3 \n";
    cout << dot[0].F + (dot[1].F - dot[2].F) << " " << dot[0].S + (dot[1].S - dot[2].S) << '\n';
	cout << dot[2].F + (dot[0].F - dot[1].F) << " " << dot[2].S + (dot[0].S - dot[1].S) << '\n';
    cout << dot[1].F + (dot[2].F - dot[0].F) << " " << dot[1].S + (dot[2].S - dot[0].S) << '\n';

    return 0;
}
