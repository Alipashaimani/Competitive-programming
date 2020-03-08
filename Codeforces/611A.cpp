#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    string s;
    cin >> a >> s >> s ;
    if (s == "week") {

        if (a == 6 || a == 5)
            cout << "53";
        else
            cout << "52";

        return 0;
    }
    if (a <= 29)
        cout << "12";
    if (a == 30)
        cout << "11";
    if (a == 31)
        cout << "7";

    return 0;
}