#include <bits/stdc++.h>
using namespace std;
int main () {
    int a,b=0;
    char t1,t2,t3,t4,s;
    cin>>a;
    if(a%2==0){
        a++;
    }
    //cin>>s>>t1>>t2>>t3>>t4;                 //in bardashte beshe
    s='D';t1='*';t2='*';t3='*';t4='*';   // ino bezar

    for(int j=0;a/2>j;j++){
        b=0;
        for(int i=j;(a-1)/2>i;i++){
            cout<<t2;
            b++;
        }
        for(int i=0;a-(b*2)>i;i++)
        cout<<s;

        for (int i=j;(a-1)/2>i;i++){
            cout<<t1;
        }
        cout<<endl;
    }
    for(int i=0;a>i;i++){
        cout<<s;
    }
        cout<<endl;
    for(int j2=0;a/2>j2;j2++){
        b=0;
        int m=(((a-1)/2)-j2);
        for(int i2=m;(a-1)/2>=i2;i2++){
            cout<<t3;
            b++;
        }
        for(int i3=0;a-(b*2)>i3;i3++)
            cout<<s;

        for (int i4=m;(a-1)/2>=i4;i4++){
            cout<<t4;
        }
        cout<<endl;
    }




    }
