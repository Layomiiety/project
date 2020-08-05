//acw1310
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
typedef long long LL;
int m,n,infac,fac;
il LL C(int x){
    if(x<3)return 0;
    else return (LL)(x-1)*x/2*(x-2)/3;
}
il int gcd(int a,int b){return a?gcd(b%a,a):b;}
int main(){
    scanf("%d%d",&n,&m);
    m++,n++;
    LL res=C(m*n)-n*C(m)-m*C(n);
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            int x=gcd(i,j);
            res-=2*(x-1)*(n-i)*(m-j);
        }
    }
    printf("%lld",res);
    return 0;
}