#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    char A[1000];
    cin>>s;
    for(int i=0;s.size()>i;i+=2){
        A[(i/2)]=s[i];

    }
    sort(A,A + (s.size() + 1)/ 2);
    for(int j=0;(s.size() + 1) / 2>j;j++){
        cout<< A[j];
        if (j < (s.size() + 1) / 2 - 1)
            cout << '+';
    }
}