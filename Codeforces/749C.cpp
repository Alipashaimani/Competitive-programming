#include <bits/stdc++.h>
using namespace std;

queue<int> qR, qD;
char c;
int n;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> c;

        if(c == 'D')
            qR.push(i);

        else
            qD.push(i);
    }

    while(1){

        if (qR.empty() || qD.empty() )
            break;

        if(qR.front() < qD.front()){
            qD.pop();
            qR.pop();
            qR.push(n);
        }
        else{
            qR.pop();
            qD.pop();
            qD.push(n);
        }
        n++;
    }
	cout << (qR.empty()?"R":"D") << '\n';
	return 0;
}
