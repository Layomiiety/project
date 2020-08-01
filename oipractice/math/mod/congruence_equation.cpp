//acw203
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
il int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main(){
    LL a,b;
    scanf("%lld%lld",&a,&b);
    int x,y;
    exgcd(a,b,x,y);
    printf("%d",(x%b+b)%b);
    return 0;
}