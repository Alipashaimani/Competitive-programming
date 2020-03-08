#include <iostream>
using namespace std;
int a[101];
long long n,max2 = 0 ,maxi = 0 ,min2 = 1000 ,mini = 0, sum;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max2){

            max2 = a[i];
            maxi = i;
        }
        if(min2 >= a[i]){

            min2 = a[i];
            mini = i;
        }
    }
    sum = maxi + ( n - mini - 1);
    if(maxi > mini)
        sum--;

    cout<<sum;
}