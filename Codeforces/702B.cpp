#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0, a;
map <long long , long long> mp;
int main (){
    cin>>n;

    while (n--){
        cin>>a;
        for (int i=0;i<=32;i++)
            ans+=mp[pow(2,i)-a];

        mp[a]++;
    }
    return cout<< ans << "\n" , 0;
}