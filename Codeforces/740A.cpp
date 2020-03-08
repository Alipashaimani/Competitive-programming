#include <iostream>
using namespace std;
long long MINX = 3e9;
long long n,a,b,c;
int main() {
    cin >> n >> a >> b >> c;
    for ( long long i = 0 ; i <= 20L ; i++){
        for ( long long j = 0 ; j<= 20L ; j++){
            for ( long long k = 0 ; k<= 20L ; k++){
                if ((i+2*j+3*k+n)%4 == 0)
                    MINX = min( MINX , i*a+j*b+k*c);
            }
        }
    }
    cout << MINX;
}