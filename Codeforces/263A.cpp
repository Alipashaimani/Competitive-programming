
#include <iostream>

using namespace std;

int main() {
    int a=25;
    int b[a];
    for(int i=0;25>i;i++){
        cin>>b[i];
    }
    if(b[7]==1||b[11]==1||b[13]==1||b[17]==1)
        cout<<"1";
    else if ( b[12]==1)
        cout<<"0";
    else if (b[2]==1||b[6]==1||b[8]==1||b[16]==1||b[18]==1||b[22]==1||b[10]==1||b[14]==1)
        cout<<"2";
    else if ( b[0]==1||b[4]==1||b[20]==1||b[24]==1)
        cout<<"4";
    else
        cout<<"3";

}