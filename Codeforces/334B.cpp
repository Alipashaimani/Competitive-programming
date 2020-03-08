#include <bits/stdc++.h>
using namespace std;
vector<int>X,Y;
vector<pair<int, int > >XY;
map<int,int>cntx, cnty;
map<pair<int, int> , int> cntxy;
int main(){
    for (int i = 0 ; i < 8 ; i++){
        int x, y;   cin >> x >> y;
        if (cntx[x] == 0)
            X.push_back(x);
        if (cnty[y] == 0)
            Y.push_back(y);
        if (cntxy[{x,y}] == 0)
            XY.push_back({x,y});
        cntx[x]++;
        cnty[y]++;
        cntxy[{x,y}] ++;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
//    cout << X.size() << " " << Y.size() << " " << XY.size() << "\n";
    if (cntxy[{X[1],Y[1]}] == 0 && X.size() == 3 && Y.size() == 3 && XY.size() == 8)
        return cout << "respectable\n" ,0;
    return cout << "ugly\n",0;
}