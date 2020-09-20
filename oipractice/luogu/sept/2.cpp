#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1005;
int n,m,a,b,c,w[N][N];
LL aa[N][N],bb[N][N],cc[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
bool vis[N][N];
struct node{
    int x,y;
    LL dis;
    bool operator <(const node& a)const
    {
        return dis>a.dis;
    }
};
inline void bfs(LL dis[][N],int x,int y){
    priority_queue<node>q;
    memset(vis,0,sizeof vis);
    dis[x][y]=(LL)w[x][y];
    q.push({x,y,dis[x][y]});
    while(!q.empty()){
        node t=q.top();
        q.pop();
        int nx=t.x,ny=t.y;
        if(vis[nx][ny])continue;
        vis[nx][ny]=true;
        LL nd=t.dis;
        for(int i=0;i<4;i++){
           int xx=nx+dx[i],yy=ny+dy[i];
           if(xx<1||xx>n||yy<1||yy>m)continue;
           LL xd=(LL)w[xx][yy]+nd;
           if(xd<dis[xx][yy]){ 
                dis[xx][yy]=xd;
                q.push({xx,yy,xd});
           }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&w[i][j]);
            aa[i][j]=bb[i][j]=cc[i][j]=1e18;
        }
    }
    bfs(aa,1,a);
    bfs(bb,n,b);
    bfs(cc,n,c);
    LL ans=1e18;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=min(ans,aa[i][j]+bb[i][j]+cc[i][j]-2LL*w[i][j]);
        }
    }
    printf("%lld",ans);
    return 0;
}