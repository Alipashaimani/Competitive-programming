//soal A
#include <bits/stdc++.h>
using namespace std ;

int main (){
    int x, A = 0 , B = 0 ;
    string s ;
    cin >> x >> s ;
    for (int i = 0 ; i < s.size() ; i++){
        if (s[i] == 'A')
            A++ ;
        else
            B++ ;
    }

    if (A > B)
        cout << "Anton" << endl ;
    else if (B > A)
        cout << "Danik" << endl ;
    else
        cout << "Friendship" << endl ;

}