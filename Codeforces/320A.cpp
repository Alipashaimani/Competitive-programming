#include <bits/stdc++.h>
using namespace std;
int main(){
    bool flag=false;
    string s;
    cin>>s;
    for ( int i = 0 ; s.size() > i ; i++){
        if ( s[i]=='1'){
            if ( s[i+1]=='4'){
                i++;
                if ( s[i+1]=='4'){
                    i++;
                }
            }
            continue;
        }
        else {
            flag=true;
            break;
        }

    }
    cout<<(flag==false?"YES":"NO");
}
