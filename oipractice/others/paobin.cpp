#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline ll read() {
    char ch=getchar();
    register ll x=0;
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
int n,m,a[105],stt[70],cnt,num[65],dp[3][65][65],ans;
char land[15];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",&land);
        for(int j=0;j<m;j++){
            a[i]<<=1;
            a[i]+=(land[j]=='H')?1:0;
        }
        //printf("%d\n",a[i]);
    }
    for(int i=0;i<(1<<m);i++){
        if((i&i<<2)||(i&i<<1))continue;
        for(int j=i;j;j>>=1)num[cnt]+=(j&1);
        stt[cnt++]=i;
        //printf("%d %d %d\n",cnt-1,stt[cnt-1],num[cnt-1]);
    }
    for(int i=0;i<cnt;i++){
        if(a[1]&stt[i])continue;
        dp[1][i][0]=num[i];
        //printf("%d %d\n",stt[i],dp[1][i][0]);
        }
    for(int i=0;i<cnt;i++){
        if(a[2]&stt[i])continue;
        for(int j=0;j<cnt;j++){
            if((stt[i]&stt[j])||(stt[j]&a[1]))continue;
            dp[2][i][j]=num[i]+num[j];
            //printf("%d %d %d\n",stt[i],stt[j],dp[2][i][j]);
        }
    }
    for(int i=3;i<=n;i++){
        for(int now=0;now<cnt;now++){
            if(a[i]&stt[now])continue;
            for(int last=0;last<cnt;last++){
                if((a[i-1]&stt[last])||(stt[last]&stt[now]))continue;
                for(int k=0;k<cnt;k++){
                    if((a[i-2]&stt[k])||(stt[k]&stt[last])||(stt[k]&stt[now]))continue;
                    dp[i%3][now][last]=max(dp[i%3][now][last],dp[(i-1)%3][last][k]+num[now]);
                }
            }
        }
    }
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            if(stt[i]&stt[j])continue;
            ans=max(ans,dp[n%3][i][j]);
            //printf("%d %d %d\n",stt[i],stt[j],dp[n%3][i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}