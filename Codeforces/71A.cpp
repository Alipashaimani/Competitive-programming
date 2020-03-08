
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    string a;
    char b,d;
    int m;
    cin>>m;
    vector<string>r;
    for (int i1=0;i1<=m;i1++){
        getline(cin,a);
        r.push_back(a);
    }


    for(int i=0;i<=m;i++){
        if(r[i].size()<=10){
            cout<<r[i]<<endl;
                }
        else{
            b=r[i].at(0);
            d=r[i].at(r[i].length()-1);
            cout<<b<<r[i].length()-2<<d<<endl;
        }

    }
    return 0;
}