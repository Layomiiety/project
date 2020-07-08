#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int maxn=40005;
int n,tw,v,w,m,dp[maxn],q[maxn],hq[maxn],ans;
int main(){
    scanf("%d%d",&n,&tw);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&v,&w,&m);
        if(v==0)continue;
        if(w==0)ans+=v*m;
        if(m==1){
            for(int j=tw;j>=w;j--){
                dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
        if(m*w>=tw){
            for(int j=w;j<=tw;j++){
                dp[j]=max(dp[j],dp[j-w]+v);
            }
        }
        else{
            for(int r=0;r<w;r++){
                int head=0,tail=0,k=(tw-r)/w;
                for(int i=0;i<=k;i++){
                    int n=dp[i*w+r]-i*v;
                    while(head<tail&&hq[tail-1]<n)tail--;
                    hq[tail]=n;
                    q[tail]=i;
                    tail++;
                    if(i-q[head]>m)head++;
                    dp[i*w+r]=hq[head]+i*v;
                }
            }
        }
    }
    printf("%d",ans+dp[tw]);
    return 0;
}