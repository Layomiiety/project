#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rr register
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
int n,c,p,sup[55],d[55],dp[55][55][2];
int main(){
    n=read(),c=read();
    for(int i=1;i<=n;i=-~i){
        d[i]=read(),p=read();
        sup[i]=sup[i-1]+p;
        }
    memset(dp,0x7f,sizeof(dp));
    dp[c][c][0]=dp[c][c][1]=0;
    for(rr int le=2;le<=n;le=-~le){
        for(rr int l=max(1,c-le+1),r=l+le-1;r<=c+le-1;l=-~l,r=-~r){
            dp[l][r][0]=min(dp[l+1][r][0]+(d[l+1]-d[l])*(sup[n]-sup[r]+sup[l]),dp[l+1][r][1]+(d[r]-d[l])*(sup[n]-sup[r]+sup[l]));
            dp[l][r][1]=min(dp[l][r-1][1]+(d[r]-d[r-1])*(sup[n]-sup[r-1]+sup[l-1]),dp[l][r-1][0]+(d[r]-d[l])*(sup[n]-sup[r-1]+sup[l-1]));
        }
    }
    printf("%d",min(dp[1][n][0],dp[1][n][1]));
    return 0;
}