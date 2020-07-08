#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
int n,m,h[505][505],dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},lb[505][505],rb[505][505],vis[505][505],cnt=0;
bool can=true;
inline void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m||h[xx][yy]>=h[x][y])continue;
        if(!vis[xx][yy])dfs(xx,yy);
        lb[x][y]=min(lb[xx][yy],lb[x][y]);
        rb[x][y]=max(rb[x][y],rb[xx][yy]);
    }
    return;
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)h[i][j]=read();
    }
    memset(lb,0x3f,sizeof(lb)),memset(rb,0,sizeof(rb));
    for(int i=1;i<=m;i++)lb[n][i]=rb[n][i]=i;
    for(int i=1;i<=m;i++)dfs(1,i);
    for(int i=1;i<=m;i++)if(!vis[n][i])can=false,cnt++;
    if(!can){
        printf("0\n%d",cnt);
        return 0;
    }
    int starter=1,end=0;
    while(starter<=m){
        for(int i=1;i<=m;i++){
            if(lb[1][i]<=starter)end=max(end,rb[1][i]);
        }
        cnt++,starter=end+1;
    }
    printf("1\n%d",cnt);
    return 0;
}