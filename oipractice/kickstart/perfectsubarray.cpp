//2020roundCqn3
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f,M=1e8+5;
int T,pre[N],ps[M],x,n,minpre,maxpre;
int main(){
    scanf("%d",&T);
    for (int t=1;t<=T;t++){
        int res=0;
        memset(ps,0,sizeof ps);
        minpre=inf;
        maxpre=-inf;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&pre[i]);
            pre[i]+=pre[i-1];
            minpre=min(minpre,pre[i]);
            maxpre=max(maxpre,pre[i]);
        }
        for(int i=1;i<=n;i++)ps[pre[i]-minpre]++;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                res+=ps[i*i-minpre+pre[j]];
                }
            }
        printf("Case #%d: %d\n",t,res);
    }
    return 0;
}