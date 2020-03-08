#include<bits/stdc++.h>
using namespace std;
string s[1010][2];
int n;
bool flag = false;
int main(){
    cin >> n;
    for ( int i = 0 ; i < n ; i++){
        string x ;
        cin >> x;
        string s1 ="";
        s1 += x[0]; s1 += x[1];
        s[i][0] = s1;
        s1 = "";
        s1 += x[3];s1+=x[4];
        s[i][1] = s1;
    }

    for ( int i = 0 ; i < n ; i++){
        if ( s[i][0] == "OO"){
            s[i][0] = "++";
            flag = true;
            break;
        }
        else if ( s[i][1] == "OO"){
            s[i][1] ="++";
            flag = true;
            break;
        }
    }
    if (!flag)
        return cout <<"NO\n" , 0;
    cout << "YES\n";
    for ( int i = 0 ; i < n ; i++)
        cout << s[i][0] << '|' << s[i][1] << '\n';
    return 0;
}