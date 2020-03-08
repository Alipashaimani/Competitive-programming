//InTheNameOfGod
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    pair<int,int>card[100];
    for ( int i = 0 ; i < a ; i++ ) {
        cin >> card[i].first ;
        card[i].second=(i+1);
    }
    sort(card,card+a);
    for ( int i = 0 ; i < (a/2) ; i++ ) {
        cout<<card[i].second<<" "<<card[a-i-1].second<<'\n';
    }
}