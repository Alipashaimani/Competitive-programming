#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

const string S[2]={"DOWN", "UP"};
string s;
bool u, d;
stack <int> st;

int main(){
	ios_base::sync_with_stdio(false);
	st.push(-1);
	getline(cin, s);
	rep(i, s.size()){
        if(s[i]=='<'){
            if(i+5<s.size() && s[i+1]=='D' && s[i+2]=='O' && s[i+3]=='W' && s[i+4]=='N' && s[i+5]=='>'){
                st.push(0);
                i+=5;
                continue;
            }
            else if(i+6<s.size() && s[i+2]=='D' && s[i+3]=='O' && s[i+4]=='W' && s[i+5]=='N' && s[i+6]=='>' && s[i+1]=='/'){
                if(st.top()==0)
                    st.pop();
                i+=6;
                continue;
            }
            else if(i+3<s.size() && s[i+1]=='U' && s[i+2]=='P' && s[i+3]=='>'){
                st.push(1);
                i+=3;
                continue;
            }
            else if(i+4<s.size() && s[i+1]=='/' && s[i+2]=='U' && s[i+3]=='P' && s[i+4]=='>'){
                if(st.top()==1)
                    st.pop();
                i+=4;
                continue;
            }
        }
            if(st.top()==1)
                if(s[i]>='a')
                    cout<<char(s[i]-'a'+'A');
                else
                    cout<<s[i];
            else if(st.top()==0)
                if(s[i]>='a')
                    cout<<s[i];
                else
                    cout<<char(s[i]-'A'+'a');
            else
                cout<<s[i];
	}
	cout<<endl;
	return 0;
}

