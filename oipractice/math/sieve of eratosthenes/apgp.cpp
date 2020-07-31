//acw1289
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
const LL mod=200907;
LL t,a,b,c,k;
il LL pow(){
    LL base=b/a;
    k-=1;
    LL ans=a%mod;
    for(;k;k>>=1){
        if(k&1)ans=ans*base%mod;
        base=base*base%mod;
    }
    return ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        if(a+c==2*b){
            LL ans=a+(k-1)%mod*(b-a)%mod;
            printf("%lld\n",ans%mod);
        }
        else {
            printf("%lld\n",pow());
        }
    }
    return 0;
}