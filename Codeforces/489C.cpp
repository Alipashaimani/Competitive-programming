#include <iostream>
using namespace std;
int main(){
    int a,b,t;
    string s = "1";
    cin >> a >> t;
    if (a == 0)
        return cout << ( b == 0 ? "0 0" : "-1 -1") , 0;

    b = t;
    b--;
    for ( int i = 0 ; i < a-1 ; i++)
        s+='0';

    for ( int i = int(s.size()) -1  ; i != -1 ; i--){
        if ( b >= 9){
            s[i] =((s[i]-'0')+9)+'0';
            b-=9;
            if (!(s[i]>= '0' && s[i]<= '9'))
                return cout <<"-1 -1\n" , 0;
        }
        else {
            s[i] =((s[i]-'0')+b)+'0';
            if (!(s[i]>= '0' && s[i]<= '9'))
                return cout <<"-1 -1\n" , 0;
            break;
        }



    }
    cout << s << " ";
    s="";
    for ( int i = 0 ; i < a ; i++)
        s+='0';

    for ( int i = 0 ; i < a ; i++){
        if ( t >= 9){
            s[i] =((s[i]-'0')+9)+'0';
            t-=9;
        }
        else{
            s[i] =((s[i]-'0')+t)+'0';
            break;
        }
    }
    cout << s << '\n';
    return 0;
}