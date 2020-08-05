//acw1307
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
typedef long long LL;
const int mod=100003,N=2005;
int fact[N],infac[N];
int a,b,c,d,k;
il int qp(int x,int p){
    int res=1;
    for(;p;p>>=1){
        if(p&1)res=((LL)res*x)%mod;
        x=(LL)x*x%mod;
    }
    return res;
}
il int P(int a,int b){
    if(a>b)return 0;
    return (LL)fact[b]*infac[b-a]%mod;
}
il int C(int a,int b){
    return (LL)P(a,b)*infac[a]%mod;
}
int main(){
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
    fact[0]=infac[0]=1;
    for(int i=1;i<max(a+c+1,b+d+1);i++){
        fact[i]=(LL)fact[i-1]*i%mod;
        infac[i]=qp(fact[i],mod-2);
    }
    int res=0;
    for(int i=0;i<=k;i++){
        res=(res+(LL)C(i,b)*P(i,a)%mod*C(k-i,d)%mod*P(k-i,a+c-i))%mod;
        //printf("%d %d %d %d\n",C(i,b),P(i,a),C(k-i,d),P(k-i,a+c-i));
    }
    printf("%d",res);
    return 0;
}