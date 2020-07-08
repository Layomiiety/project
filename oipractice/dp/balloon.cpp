#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rr register
#define inf 0x3f3f3f3f
inline int read() {
    char ch=getchar();
    int x=0,f=1;
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
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int n,x0,ys=0;
double dp[1005][1005][2],minloss,vs[1005];
struct balloon{
    int x,v;
};
bool cmp(balloon a,balloon b){
    return a.x==b.x?a.v<b.v:a.x<b.x;
}
int main(){
    n=read(),x0=read();
    balloon b[n+1];
    for (int i=0;i<n;i++)b[i].x=read();
    for (int j=0;j<n;j++)ys+=read();
    for (int k=0;k<n;k++)b[k].v=read();
    b[n].x=x0,b[n].v=0;
    sort(b,b+n+1,cmp);
    for (int i=1;i<=n+1;i++)vs[i]=vs[i-1]+b[i-1].v;
    memset(dp,0x7f,sizeof(dp));
    int l=0,r=n,s;
    while(l<=r){
        s=(l+r)>>1;
        if(b[s].x==x0){
            if(b[s].v==0)break;
            b[s].v<0?l=s+1:r=s-1;
        }
        else b[s].x<x0?l=s+1:r=s-1;
    }
    dp[s][s][0]=dp[s][s][1]=0;
    for(int le=2;le<=n+1;le++){
        for(int l=max(0,s-le+1),r=l+le-1;r<=min(n,s+le-1);l=-~l,r=-~r){
            dp[l][r][0]=min(dp[l+1][r][0]+(b[l+1].x-b[l].x)*(vs[n+1]-vs[r+1]+vs[l+1]),dp[l+1][r][1]+(b[r].x-b[l].x)*(vs[n+1]-vs[r+1]+vs[l+1]));
            dp[l][r][1]=min(dp[l][r-1][0]+(b[r].x-b[l].x)*(vs[n+1]-vs[r]+vs[l]),dp[l][r-1][1]+(b[r].x-b[r-1].x)*(vs[n+1]-vs[r]+vs[l]));
        }
    }
    minloss=min(dp[0][n][0],dp[0][n][1]);
    printf("%.3f",0.001*(ys-minloss));
    return 0;
}