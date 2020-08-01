//acw1294
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
const int N=1e6+5,mod=1e9+7;
int n,pr[N>>1],cnt,po;
bool st[N];
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&pr[j]*i<=n;j++){
            st[i*pr[j]]=1;
            if(!(i%pr[j]))break;
        }
    }
    LL ans=1;
    for(int i=0;i<cnt;i++){
        po=0;
        for(int j=n;j;j/=pr[i]){
            po+=j/pr[i];
        }
        ans=ans*(2*po+1)%mod;
    }
    printf("%lld",ans);
}