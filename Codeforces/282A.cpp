#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    string a;
    int m,n=0;
    cin>>m;
    vector<string>r;
    for (int i1=0;i1<=m;i1++){
        getline(cin,a);
        r.push_back(a);
    }
    for(int i=1;i<=m;i++){
        if(r[i]=="X++" || r[i]=="++X"){n++;}
        else
            n--;

}
    cout << n;
    }
