#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL unsigned long long
#define il inline
const int N=1e5+5,M=60;
const LL maxx=2e16;
int n,cnt[M],mm[M],q,dp[M][2],ans[M];
LL ai,m,minn[M][2];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&ai);
        for(int pos=1;ai;ai>>=1,pos++){
            if(ai&1)cnt[pos]++;
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=52;i++){
        dp[i][0]=cnt[i];
        dp[i][1]=n-cnt[i];
        if(!cnt[i])minn[i][0]=min(minn[i-1][0],minn[i-1][1]);
        else minn[i][0]=min(min(minn[i-1][0],minn[i-1][1])+dp[i][0]*(1ll<<(i-1)),maxx);
        if(minn[i-1][1]==maxx)minn[i][1]=maxx;
        else minn[i][1]=min(min(minn[i-1][0],minn[i-1][1])+dp[i][1]*(1ll<<(i-1)),maxx);
        //printf("%d %lld %lld\n",i,minn[i][0],minn[i][1]);
    }
    while(q--){
        memset(mm,0,sizeof mm);
        scanf("%lld",&m);
        int pos=log2(m)+1;
        bool ch=false;
        for(int i=52;i>0;i--){
            if(minn[i][1]<=m){
                ans[i]=1;
                m-=dp[i][1]*(1ll<<(i-1));
            }
            else if(minn[i][0]<=m){
                ans[i]=0;
                m-=dp[i][0]*(1ll<<(i-1));
            }
            else {
                puts("-1");
                ch=true;
                break;
            }
        }
        if(!ch){
            LL res=0,base=1;
            for(int i=1;i<=52;i++,base<<=1){
                if(ans[i])res+=base;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}
