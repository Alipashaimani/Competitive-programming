#include <bits/stdc++.h>
using namespace std;
char check[]{'A','E','I','O','U','Y'};
string s;
int main(){
    getline(cin,s);
    reverse(s.begin(),s.end());
    for(int i = 0 ; i < s.size() ; i++){
        if (s[i]!='?' && s[i]!= ' '){
            s[i]=toupper(s[i]);
            for (int j = 0 ; j < 6 ; j++)
                if ( s[i] == check[j])
                    return cout << "YES\n" , 0;
            return cout << "NO\n" , 0;
        }
    }
    return cout << "NO\n" , 0;
}