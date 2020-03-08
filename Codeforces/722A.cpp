#include <bits/stdc++.h>
using namespace std ;

int h , m , n ;
int main (){
    scanf("%d%d:%d", &n, &h, &m) ;
    if (n == 24) {if (h > 23) h = h % 10 ;}
    else{
        if (h > 12 || h == 0){

            if (!(h % 10))
                h = 10 ;
            else
                h = h % 10 ;
        }
    }
    if (m >= 60)
        m = m % 10 ;
    printf("%02d:%02d" , h , m) ;
}