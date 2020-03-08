#include <algorithm>
#include <cstdio>
#include <vector>

#define RIGHT 131072
#define SIZE 262144

using namespace std;

struct T
{
    int am, l, r;
    T(int a, int b, int c) : am(a), l(b), r(c) {};
};

int N, Q, Last;
int Root[100005];
vector< pair<int,int> > A;
vector<T> V(2100000, T(0, 0, 0));

int newNode(int n)
{
    V[++Last].am = V[n].am;
    V[Last].l = V[n].l;
    V[Last].r = V[n].r;
    return Last;
}

int insert(int idx, int v, int n, int a, int b)
{
    if(a > v || b < v)
        return idx;
    
    idx = newNode(idx);
    
    if(a == v && b == v)
    {
        V[idx].am++;
        return idx;
    }
    
    int mid = (a+b) / 2;
    V[idx].l = insert(V[idx].l, v, 2*n, a, mid);
    V[idx].r = insert(V[idx].r, v, 2*n + 1, mid + 1, b);
    
    V[idx].am = V[V[idx].l].am + V[V[idx].r].am;
    return idx;
}

int query(int idx, int l, int r, int n, int a, int b)
{
    if(a >= l && b <= r)
        return V[idx].am;
    if(b < l || a > r)
        return 0;
    
    int mid = (a+b) / 2;
    return query(V[idx].l, l, r, 2*n, a, mid) + query(V[idx].r, l, r, 2*n + 1, mid + 1, b);
}

int main()
{
    scanf("%d %d", &N, &Q);
    
    for(int i = 1; i <= N; i++)
    {
        int x;
        scanf("%d", &x);
        A.push_back(make_pair(x, i));
    }
    
    sort(A.begin(), A.end());
    
    for(int i = 1; i <= A.size(); i++)
        Root[i] = insert(Root[i-1], A[i-1].second, 1, 1, RIGHT);
    
    while(Q--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        
        int a = 1, b = N;
        int p = (a+b) / 2;
        
        while(b > a+1)
        {
            if(query(Root[p], l, r, 1, 1, RIGHT) < k)
                a = p;
            else
                b = p;
            
            p = (a+b) / 2;
        }
        
        if(query(Root[a], l, r, 1, 1, RIGHT) == k)
            printf("%d\n", A[a-1].first);
        else
            printf("%d\n", A[b-1].first);
    }
}
