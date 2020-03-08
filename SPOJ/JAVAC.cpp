#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin >> s){
        bool underline = 0;
        bool capital = 0;
        if (s[0] == '_' || (s[0] >='A' && s[0]<='Z')){
            underline = 1;
            capital = 1;
        }
            
        for ( int i = 0 ; i < s.size() ; i++)
        {
            if ( s[i] == '_'){
                underline = true;
                if (s[i+1] == '_')
                    capital = true;
                
            }
            if ( s[i]>='A' && s[i] <='Z')
                capital = true;
        }
        if ( capital && underline){
            cout << "Error!\n";
        }
        else if (capital){
            
            
            for ( int i = 0 ; i < s.size() ; i++){
                
                if ( s[i] >= 'A' && s[i]<= 'Z')
                    cout << '_' << char(tolower(s[i]));
                else
                cout << s[i] ;
            }
            cout << '\n';
        }
        else {
            if ( s[s.size()-1] == '_'){
                cout << "Error!\n";
                goto hell;
            }
            for ( int i = 0 ; i < s.size() ; i++){
                if ( s[i] == '_'){
                    s[i+1]=toupper(s[i+1]);
                    continue;
                }
                cout << s[i] ;
                
            }
            cout << '\n';
        }
    hell:
        int alaki;
    }
}
