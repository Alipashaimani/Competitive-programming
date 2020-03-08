#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>b>>a;
    for (int i=0;a>i;i++){cout<<"#";}
    cout<<endl;
    for ( int m=0;b-((b+1)/2)>m;m++){

        if ((m+1)%2==1  ){
    for(int j=0;(a-1)>j;j++){cout<<".";}
    cout<<"#"<<endl;
        }
        else{
            cout<<"#";
            for(int j=0;(a-1)>j;j++){cout<<".";}
            cout<<endl;
        }

    for (int i=0;a>i;i++){cout<<"#";}
    cout<<endl;

    }



}
