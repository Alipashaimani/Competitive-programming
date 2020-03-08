#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 100;

int mx[MAXN * 4];
int idindex[MAXN * 4];
pair<int,int> result;
int r2;
void change(int index, int value, int lo, int hi, int id) {
    if (lo == hi) {
        mx[id] = value;
        idindex[id] = index;
        return;
    }
    int mid = (lo + hi) / 2;
    if (index <= mid) {
        change(index, value, lo, mid, 2 * id);
    } else {
        change(index, value, mid + 1, hi, 2 * id + 1);
    }
    
    if ( mx[2 * id] > mx[2 * id + 1]){
        mx[id] = mx[2*id];
        idindex[id] = idindex[2*id];
    }
    else {
        mx[id] = mx[2*id+1];
        idindex[id] = idindex[2*id+1];
    }
    
}

pair<int,int> query(int l, int r, int lo, int hi, int id) {
    if (r < lo || hi < l) {
        return {0,0};
    }
    if (l <= lo && hi <= r) {
        return {mx[id],idindex[id]};
    }
    int mid = (lo + hi) / 2;
    if (query(l, r, lo, mid, 2 * id) > query(l, r, mid + 1, hi, 2 * id + 1)){
        return query(l, r, lo, mid, 2 * id);
    }
    else
        return query(l, r, mid+1, hi, 2 * id + 1);
}

int main() {
    int n;
    cin >> n;
    
    for ( int i = 0 ; i < n ; i++){
        int x ; cin >> x;
        change(i+1, x, 1, n, 1);
    }
    
    char type;
    int m;  cin >> m;
    
    for ( int i = 0 ; i < m ; i++){
        cin >> type;
        
        if (type == 'U') {
            int index, value;
            cin >> index >> value;
            change(index, value, 1, n, 1);
            
        }
        
        else if (type == 'Q') {
            int left, right;
            cin >> left >> right;
            
            result = {0,0};
            result = query(left, right, 1, n, 1);
            
            change(result.second, 0, 1, n, 1);
            
            
            r2 = 0;
            r2 = query(left, right, 1, n, 1).first;
            
            
            change(result.second, result.first, 1, n, 1);
            
            
            
            cout << r2 + result.first;
            
        }
        
        cout << endl;
    }
    return 0;
}

