//acw1290
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
#define ULL unsigned long long
const ULL mod=100003;
ULL m,n;
int main(){
    scanf("%lld%lld",&m,&n);
    ULL base=(m-1)%mod,ans=m%mod,tt=1,bb=m%mod;
    for(ULL i=n;i;i>>=1){
        if(i&1)tt=tt*bb%mod;
        bb=bb*bb%mod;
    }
    n-=1;
    for(;n;n>>=1){
        if(n&1)ans=ans*base%mod;
        base=base*base%mod;
    }
    printf("%lld",(tt-ans+mod)%mod);
    return 0;
}