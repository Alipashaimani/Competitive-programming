#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        vector<int>L,S;
        vector<int>NA;
        int minN = 0,maxN = 0;
        cin >> b;
        if ( b == 1){
            cout << "! 1 1\n" << flush;
            continue;
        }
        for ( int j = 0 ; j < b ; j+= 2){
            cout << "? " << j+1 <<" "<<j+2 << '\n' << flush;
            char c;
            cin >> c;
            if (c == '>'){
                L.push_back(j+1);
                S.push_back(j+2);
            }
            else if ( c == '<'){
                S.push_back(j+1);
                L.push_back(j+2);
            }
            else if ( c == '='){
                S.push_back(j+1);
                L.push_back(j+2);
            }
            if ( b % 2 == 1){
                if ( j+4 >= b){
                    NA.push_back(j+3);
                    break;
                }
            }
        }

        int AL = 0;
        for ( int i = 1 ; i < L.size(); i++){
            if ( AL == i){
                continue;
            }
            cout << "? " << L[AL] <<" "<<L[i]<<'\n' << flush;
            char c ;
            cin >> c;
            if (c == '<'){
                AL = i;
            }
        }
        maxN = L[AL];
        int AS = 0;
        for ( int i = 1 ; i < S.size(); i++){
            if ( AS == i){
                continue;
            }
            cout << "? " << S[AS] <<" "<<S[i]<<'\n' << flush;
            char c ;
            cin >> c;
            if (c == '>'){
                AS = i;
            }
        }
        minN = S[AS];
        char c ;
        if ( NA.size() == 1){
            cout <<"? "<<NA[0] <<" "<<minN << '\n' << flush;
            cin >> c;
            if ( c == '<'){
                minN = NA[0];
            }
            cout <<"? "<<NA[0] <<" "<<maxN << '\n' << flush;
            cin >> c;
            if ( c == '>'){
                maxN = NA[0];
            }
        }
        cout << "! " << minN << " " << maxN << '\n' << flush;
        minN = 0;
        maxN = 0;
        NA.clear();
        S.clear();
        L.clear();
        AL = 0;
        AS = 0;
    }
}