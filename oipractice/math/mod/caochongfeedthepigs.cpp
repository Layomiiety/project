//acw1298
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
int n,a[10],b[10];
il void exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
int main(){
    scanf("%d",&n);
    LL A=1;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        A*=a[i];
    }
    LL res=0;
    for(int i=0;i<n;i++){
        LL mi=A/a[i],x,y;
        exgcd(mi,a[i],x,y);
        res=(res+mi*x*b[i])%A;
    }
    printf("%lld",(res%A+A)%A);
    return 0;
}