#include <iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    while(a--){
        int x;
        cin >> x;
        if ( x == 1)
            return cout << -1 ,0 ;
    }
    return cout << 1,0;
}