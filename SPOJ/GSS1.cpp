#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
int sums[ MAX + 1 ], arr[ MAX + 1 ];
struct no {
    int lsum, rsum, msum, sum;
};

no tree[ 4 * MAX + 1 ];

void build( int node, int i, int j ) {
    if ( i == j )
        tree[ node ] = ((no){ arr[ i ], arr[ i ], arr[ i ], arr[ i ] } );
    
    else {
        build( node * 2, i, ( i + j ) / 2 );
        build( node * 2 + 1, ( i + j ) / 2 + 1, j );
        no left = tree[ node * 2 ], right = tree[ node * 2 + 1 ];
        tree[ node ].lsum = max( left.lsum, left.sum + right.lsum );
        tree[ node ].rsum = max( right.rsum, right.sum + left.rsum );
        tree[ node ].msum = max( left.msum, max( right.msum, left.rsum + right.lsum ) );
        tree[ node ].sum = left.sum + right.sum;
    }
}

void update( int node, int pos, int val, int a, int b ) {
    if ( a == b && a == pos ) {
        tree[ node ] = ( ( no ) { val, val, val, val } );
        return;
    }
    else if ( pos <= ( a + b ) / 2 )
        update( node * 2, pos, val, a, ( a + b ) / 2 );
    
    else if ( pos > ( a + b ) / 2 )
        update( node * 2 + 1, pos, val, ( a + b ) / 2 + 1, b );
    
    no left = tree[ node * 2 ], right = tree[ node * 2 + 1 ];
    
    tree[ node ] = ( ( no ) {
        max( left.lsum, left.sum + right.lsum ),
        max( right.rsum, right.sum + left.rsum ),
        max( left.msum, max( right.msum, right.lsum + left.rsum ) ),
        left.sum + right.sum } );
}

no query( int node, int a, int b, int i, int j ) {
    if ( i == a && j == b )
        return tree[ node ];
    
    if ( j <= ( a + b ) / 2 )
        return query( node * 2, a, ( a + b ) / 2, i, j );
    
    if ( i > ( a + b ) / 2 )
        return query( node * 2 + 1, ( a + b ) / 2 + 1, b, i, j );
    
    no left = query( node * 2, a, ( a + b ) / 2, i, ( a + b ) / 2 );
    no right = query( node * 2 + 1, ( a + b ) / 2 +  1, b, ( a + b ) / 2 + 1, j );
    return ( ( no ) {
        max( left.lsum, left.sum + right.lsum ),
        max( right.rsum, right.sum + left.rsum ),
        max( left.msum, max( right.msum, right.lsum + left.rsum ) ),
        left.sum + right.sum } );
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, N, q, op, l, r;
    cin >> N;
    for ( i = 0; i < N; ++i )
        cin >> arr[i];
    
    build( 1, 0, N - 1 );
    
    cin >> q;
    for ( i = 0; i < q; ++i ) {
        cin >> l >> r;
            cout << query( 1, 0, N - 1, l - 1, r - 1 ).msum << '\n';
    }
    return 0;
}


