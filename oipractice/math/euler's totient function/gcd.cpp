//acw220
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
const int N=1e7+5;
int n,c;
int pr[N>>1];
LL phi[N],cnt;
void init(){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!phi[i]){
            pr[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<cnt&&pr[j]*i<=n;j++){
            if(!(i%pr[j])){
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
            phi[i*pr[j]]=phi[i]*(pr[j]-1);
        }
        phi[i]+=phi[i-1];
    }
}
int main(){
    scanf("%d",&n);
    init();
    LL res=0;
    for(int i=0;i<cnt;i++){
        res+=(LL)(2*phi[(n/pr[i])]-1);
    }
    printf("%lld",res);
    return 0;
}