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
inline void write(ull a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
int m,n,sta[400],pas[13],cnt;
ull dp[2][400],ans=0;
const int mod=1e8;
int main(){
    m=read(),n=read();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            pas[i]<<=1;
            pas[i]+=!(read());
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(!(i&i<<1)){
            sta[++cnt]=i;
            if(!(i&pas[1]))dp[1][cnt]=1;
            }
        }
    for(int i=2;i<=m;i++){
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(re int p=1;p<=cnt;p++){
            if(sta[p]&pas[i-1])continue;
            for(re int q=1;q<=cnt;q++){
                if(sta[q]&pas[i]||sta[q]&sta[p])continue;
                ull x=dp[i&1][q]=(dp[i&1][q]+dp[!(i&1)][p])%mod;
                //printf("%lld %d %d %d\n",x,q,p,i);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        if(!(sta[i]&pas[m]))ans=(ans+dp[m&1][i])%mod;
    }
    printf("%lld",ans);
    return 0;
}
