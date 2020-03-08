#include <iostream>

using namespace std;


bool alipasha(char c) {
    char imani[ ] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < 6; i++)
    {
        if (c == imani[i])
        {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
        if (!alipasha(s[i]))
        {
            cout << "." << s[i];
        }
    }
     cout <<endl;
}