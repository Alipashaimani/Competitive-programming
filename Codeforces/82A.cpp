#include <bits/stdc++.h>
#define B begin()
#define E end()
#define pp push_back
using namespace std;
int n;
string name[]{"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main() {
    cin>>n;
    while (n>5) {
        n=(n/2)-2;
    }
    cout<<name[n-1];
}