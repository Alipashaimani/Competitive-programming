#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int s=0,a1=0,a2=0,a3=0,a4=0,a31=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){a1++;}
        if(a[i]==2){a2++;}
        if(a[i]==3){a3++;}
        if(a[i]==4){a4++;}
    }
    s+=a4;
    if(a1>a3){
        a31=a1-a3;
        if(a2%2==0){
            s+=a2/2;
            s+=a3;
            if(a31%4==0)
                s+=a31/4;
            else
                s+=a31/4+1;
        }
        else{
            s+=a2/2;
            s+=a3;
            if(a31<=2)
                s+=1;
            else{
                s+=1;
                a31-=2;
                if(a31%4!=0)
                    s+=1;
                s+=a31/4;
            }
        }
    }
    else if(a1==a3){
        s+=a1;
        if(a2%2==0){
            s+=a2/2;
        }
        else
            s+=a2/2+1;
    }
    else if(a1<a3){
        s+=a3;
        if(a2%2==0)
            s+=a2/2;
        else
            s+=a2/2+1;
    }
    cout<<s;
}