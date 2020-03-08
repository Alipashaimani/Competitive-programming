#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
bool issign(char in)
{
    return in == '#' || in == '*' || in == '&';
}

char table[MAXN][MAXN];
int abcd[MAXN][3];

int main(){
    int a2, a3;
    scanf("%d%d", &a2, &a3);

    for (int i = 0; i < a2; i++)
        scanf("%s", table[i]);


    memset(abcd, 10, sizeof abcd);

    for (int i = 0; i < a2; i++)
    {
        for (int j = 0; j < a3; j++)
        {
            if (isdigit(table[i][j])) abcd[i][0] = min(min(j, a3 - j), abcd[i][0]);
            if (islower(table[i][j])) abcd[i][1] = min(min(j, a3 - j), abcd[i][1]);
            if (issign(table[i][j])) abcd[i][2] = min(min(j, a3 - j), abcd[i][2]);
        }
    }
    int re = 0x3f3f3f3f;

    for (int i22 = 0; i22 < a2; i22++)
        for (int j22 = i22 + 1; j22 < a2; j22++)
            for (int k22 = j22 + 1; k22 < a2; k22++)
            {
                int ayur = abcd[i22][0] + abcd[j22][1] + abcd[k22][2];
                ayur = min(ayur, abcd[i22][0] + abcd[j22][2] + abcd[k22][1]);
                ayur = min(ayur, abcd[i22][1] + abcd[j22][0] + abcd[k22][2]);
                ayur = min(ayur, abcd[i22][1] + abcd[j22][2] + abcd[k22][0]);
                ayur = min(ayur, abcd[i22][2] + abcd[j22][0] + abcd[k22][1]);
                ayur = min(ayur, abcd[i22][2] + abcd[j22][1] + abcd[k22][0]);
                re = min(re, ayur);
            }

    printf("%d\n", re);
}
