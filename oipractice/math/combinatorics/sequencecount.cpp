//acw1307
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
typedef unsigned long long LL;
const LL mod=1000003;
int T;
LL n,l,r;
il LL qp(LL base,LL p){
    LL res=1;
    for(;p;p>>=1){
        if(p&1)res=res*base%mod;
        base=base*base%mod;
    }
    return res;
}
il LL C(LL a,LL b){
    LL up=1,down=1;
    for(LL i=1,j=b;i<=a;i++,j--){
        up=up*j%mod;
        down=down*i%mod;
    }
    return up*qp(down,mod-2)%mod;
} 
il LL lucas(LL a,LL b){
    if(a<mod&&b<mod)return C(a,b);
    return C(a%mod,b%mod)*lucas(a/mod,b/mod);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&l,&r);
        printf("%lld\n",(lucas(n,r-l+n+1)-1+mod)%mod);
    }
    return 0;
}