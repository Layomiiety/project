//acw1148
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=1e4+5;
int n,m,h[M<<1],nex[M<<1],to[M<<1],w[M<<1],cnt=1,fa[N],maxl[2][N][N];
ll res=0,ans=1e18;
bool vis[N];
struct edge{
    int a,b,w;
    bool in=false;
    bool operator<(const edge &t)const{
        return w<t.w;
    }
}edd[M];
inline int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
inline void add(int a,int b,int ww){
    to[cnt]=b,nex[cnt]=h[a],w[cnt]=ww,h[a]=cnt++;
}
inline void dfs(int cur,int s,int maxx,int smax){
    vis[cur]=true;
    for(int i=h[cur];i;i=nex[i]){
        int j=to[i],ww=w[i];
        if(vis[j])continue;
        if(ww>maxx){
            maxl[0][s][j]=ww;
            maxl[1][s][j]=maxx;
            dfs(j,s,ww,maxx);
        }
        else if(ww<maxx&&ww>smax){
            maxl[0][s][j]=maxx;
            maxl[1][s][j]=ww;
            dfs(j,s,maxx,ww);
        }
        else {
            maxl[0][s][j]=maxx;
            maxl[1][s][j]=smax;
            dfs(j,s,maxx,smax);
        }
    }
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&edd[i].a,&edd[i].b,&edd[i].w);
    sort(edd+1,edd+m+1);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int a=ff(edd[i].a),b=ff(edd[i].b);
        if(a!=b){
            fa[a]=b,res+=(ll)edd[i].w,edd[i].in=true;
            add(edd[i].a,edd[i].b,edd[i].w);
            add(edd[i].b,edd[i].a,edd[i].w);
            }
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        dfs(i,i,0,0);
        }
    for(int i=1;i<=m;i++){
        if(edd[i].in)continue;
        int x=edd[i].a,y=edd[i].b,ww=edd[i].w;
        //printf("%d %d %d %d %d\n",x,y,ww,maxl[0][x][y],maxl[1][x][y]);
        if(ww>maxl[0][x][y])ans=min(ans,res-maxl[0][x][y]+ww);
        else if(ww==maxl[0][x][y]&&ww>maxl[1][x][y])ans=min(ans,res-maxl[1][x][y]+ww);
    }
    printf("%lld",ans);
    return 0;
}