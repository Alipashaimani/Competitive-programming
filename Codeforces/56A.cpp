#include <bits/stdc++.h>
using namespace std;
int a, sum = 0 , number = 0 , ans = 0 ;
string ss[29]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE" ,"0" ,"1" , "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "10" , "11" , "12" , "13" , "14" , "15" , "16" , "17"};
int main() {

    cin >> a;
    for ( int i = 0 ; i < a ; i++){
        string s;
        cin >> s;
            for ( int i = 0 ; i < 29 ; i++ ){
                if ( ss[i] == s){
                    ans ++;
                    break;
                }
            }
    }
    cout << ans << '\n' ;
}
