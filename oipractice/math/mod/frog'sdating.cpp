//acw203
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
LL x,y,m,n,l;
il LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    LL d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main(){
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    LL a,b;
    LL d=exgcd(n-m,l,a,b);
    if((x-y)%d){
        puts("Impossible");
    }
    else {
        l=abs(l/d);
        printf("%lld",(a*(x-y)/d%l+l)%l);
    }
    return 0;
}