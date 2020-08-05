//acw202
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef unsigned long long LL;
il LL qmul(LL a,LL b,LL mod){
    LL res=0;
    for(;b;b>>=1){
        if(b&1)res=(res+a)%mod;
        a=(a+a)%mod;
    }
    return res;
}
il LL qpow(LL base, LL p,LL mod){
    LL res=1;
    for(;p;p>>=1){
        if(p&1)res=qmul(res,base,mod);
        base=qmul(base,base,mod);
    }
    return res;
}
int main(){
    LL l;
    int t=1;
    while(cin>>l,l){
        for(int i=0;i<3;i++){
            if(l%2)break;
            l/=2;
        }
        l*=9;
        if(!(l%2)||!(l%5)){
            printf("Case %d: %lld\n",t++,0);
            continue;
        }
        LL phi=l,x=l;
        for(LL i=2;i*i<=l;i++){
            if(!(l%i)){
                while(!(l%i))l/=i;
                phi=phi/i*(i-1);
            }
        }
        if(l>1)phi=phi/l*(l-1);
        LL ans=1e18;
        for(LL i=1;i*i<=phi;i++){
            if(!(phi%i)){
                if(qpow(10,i,x)==1){
                    ans=i;
                    break;
                }
                if(qpow(10,phi/i,x)==1){
                    ans=min(ans,phi/i);
                }
            }
        }
        printf("Case %d: %lld\n",t++,ans);
    }
    return 0;
}