#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read(){
    char ch=getchar();
    register int x=0;
    int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
const int inf=0x3f3f3f3f;
int n,c,hei[100005],dp[105],f[105],g[105],ans=inf,maxh=0;
int main(){
    n=read(),c=read();
    memset(dp,63,sizeof dp);
    for(re int i=1;i<=n;i++){hei[i]=read();maxh=max(maxh,hei[i]);}
    for(re int i=hei[1];i<=maxh;i++)dp[i]=(i-hei[1])*(i-hei[1]);
    g[maxh+1]=f[0]=inf;
    for(re int j=2;j<=n;j++){
        for(re int i=1;i<=maxh;i++)f[i]=min(f[i-1],dp[i]-c*i);
        for(re int i=maxh;i>=1;i--)g[i]=min(g[i+1],dp[i]+c*i);
        memset(dp,63,sizeof dp);
        for(re int i=hei[j];i<=maxh;i++)dp[i]=(i-hei[j])*(i-hei[j])+min(g[i]-c*i,f[i]+c*i);
        //for(int i=1;i<=maxh;i++)printf("%d %d %d\n",f[i],g[i],dp[i]);
    }
    for(re int i=hei[n];i<=maxh;i++)ans=min(ans,dp[i]);
    write(ans);
    return 0;
}