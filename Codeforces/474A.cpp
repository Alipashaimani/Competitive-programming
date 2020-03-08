#include <iostream>
using namespace std;
int main(){
    string s="qwertyuiopasdfghjkl;zxcvbnm,./";
    char c;cin>>c;
    string ss;cin>>ss;
    if ( c =='R'){
    for ( int i = 0 ; ss.size()>i;i++){
        cout<<s[s.find(ss[i])-1];
    }
    }
    else
        for ( int i = 0 ; ss.size()>i;i++){
            cout<<s[s.find(ss[i])+1];
        }

}