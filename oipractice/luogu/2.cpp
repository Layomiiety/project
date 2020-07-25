#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=2e5+5,mod=998244353;
int a[N],n,pre[N],maxn=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        maxn=max(x,maxn);
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=maxn;i++)pre[i]=a[i]+pre[i-1];
    LL res=0;
    for(int i=1;i<=maxn;i++){
        if(a[i]>=2){
            LL cb=(LL)(a[i]-1)*a[i]/2;
            if(a[i]>=3)res=(res+cb*(a[i]-2)/3)%mod;
            res=(res+cb*(pre[max(2*i-1,maxn)]-a[i]))%mod;
        }
    } 
    printf("%lld",res);
    return 0;
}

