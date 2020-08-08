//acw214
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define il inline
const int N=50050;
int pr[N>>1],mu[N],cnt;
bool st[N];
int n,a,b,d;
void init(){
    mu[1]=1;
    for(int i=2;i<=50000;i++){
        if(!st[i]){
            pr[cnt++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<cnt&&pr[j]*i<=50000;j++){
            int t=pr[j]*i;
            st[t]=true;
            if(i%pr[j])mu[t]=-mu[i];
            else {
                mu[t]=0;
                break;
            }
        }
        mu[i]+=mu[i-1];
    }
}
int main(){
    init();
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&d);
        LL res=0;
        a=a/d,b=b/d;
        for(int l=1,r;l<=min(a,b);l=r+1){
            r=min(a/(a/l),b/(b/l));
            res+=(LL)(a/l)*(b/l)*(mu[r]-mu[l-1]);
        }
        printf("%lld\n",res);
    }
    return 0;
}