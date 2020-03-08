#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, num = 0, inp;
    scanf("%lld",&N);
    for(int i = 0 ; i < N ; i++){
        
        scanf("%lld",&inp);
        num ^= inp;
    }
    
    printf("%lld\n",num);
    return 0;
}
