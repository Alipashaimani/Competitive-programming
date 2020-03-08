/*
 ID: apiv2002
 PROG: cowtour
 LANG: C++14
 */
#include <bits/stdc++.h>

using namespace std;

double Matrix[155][155];
vector < pair<int, int> > pos;
vector <double> ans;
char s[155][155];
int n;
double answer = 1e9;

double dist(pair<int, int> Ps, pair<int, int> Pd)
{
    int psa = Ps.first, psb = Ps.second, pda = Pd.first, pdb = Pd.second;
    return sqrt((psa - pda) * (psa - pda) + (psb - pdb) * (psb - pdb));
}
void Floyd_Warshall()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                Matrix[i][j] = 0;
            else if (s[i][j] == '1')
                Matrix[i][j] = dist(pos[i], pos[j]);
            else
                Matrix[i][j] = 1e9;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (Matrix[i][k] + Matrix[k][j] < Matrix[i][j])
                    Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
            }
        }
    }
}

int main()
{
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pos.push_back(make_pair(0, 0));
        cin >> pos[i].first >> pos[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    }
    Floyd_Warshall();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(0);
        for (int j = 0; j < n; j++)
        {
            if (Matrix[i][j] != 1e9 && Matrix[i][j] > ans[i])
                ans[i] = Matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || Matrix[i][j] != 1e9)
                continue;
            answer = min(answer , ans[i] + ans[j] + dist(pos[i], pos[j]));
        }
    }
    for (int i = 0; i < n; i++)
        answer = max(answer, ans[i]);
    cout << fixed << setprecision(6) << answer << '\n';
    return 0;
}
