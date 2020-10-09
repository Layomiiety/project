#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6,M=31;
int n,f[M],dp[N],ans=0;
int main(){
    scanf("%d",&n);
    memset(f,0,sizeof f);
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        int x,pos=0;
        scanf("%d",&x);
        while(x){
            if(x%2){
                dp[i]=max(dp[i],dp[f[pos]]+1);
                f[pos]=i;
                //printf("%d %d %d\n",dp[i],i,x);
            }
            x/=2;
            pos++;
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}