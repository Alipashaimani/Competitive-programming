#include <iostream>

using namespace std;

const int MAXN = 1e6 + 1;
long long  ha[MAXN], p = 999070999, pp[MAXN], ans = -1;
string s;

int main(){
    cin >> s;
    pp[0] = 1;
    ha[0] = s[0];
    int sz = (int)s.size();

    for(int i = 1; i < sz; i++){
        pp[i] = pp[i-1] * p;
        ha[i] = ha[i-1] + (s[i] * pp[i] );
    }

    for(int i = sz-2; ~i; i--){
        if (ha[i] * pp[sz - i - 1] == ha[sz - 1] - ha[sz - i - 2]) {

            for (int j = 1; j+i+1 < sz; j++){

                if (ha[j + i] - ha[j - 1] == ha[i] * pp[j]){

                    for(int k = 0; k <= i; k++)
                        cout << s[k];

                    return cout<<"\n", 0;
                }
            }
        }
    }
    return cout<<"Just a legend\n", 0;
}