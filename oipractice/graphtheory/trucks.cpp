//P1967 
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
const int N=1e4+5,M=1e5+5;
int n,m,q;
int f[N];
int depth[N],fa[N][14],idx[N],cid=0,maa[N][14];
int h[N],to[M],nex[M],w[M],cnt=1;
struct edge{
    int x,y,z;
}e[M];
il bool cmp(edge x,edge y){return x.z>y.z;}
il void add(int x,int y,int z){to[cnt]=y,w[cnt]=z,nex[cnt]=h[x],h[x]=cnt++;}
il int ff(int x){return x==f[x]?x:f[x]=ff(f[x]);}
il void dfs(int x){
    for(int i=h[x];i;i=nex[i]){
        int j=to[i];
        if(depth[j])continue;
        idx[j]=cid;
        depth[j]=depth[x]+1;
        fa[j][0]=x;
        maa[j][0]=w[i];
        for(int k=1;k<=13;k++){
            int ff=fa[j][k-1];
            fa[j][k]=fa[ff][k-1];
            maa[j][k]=min(maa[j][k-1],maa[ff][k-1]);
        }
        dfs(j);
    }
}
il int lca(int x,int y){
    int res=0x3f3f3f3f;
    if(depth[x]<depth[y])swap(x,y);
    for(int k=13;k>=0;k--){
        if(depth[fa[x][k]]>=depth[y]){
            res=min(res,maa[x][k]);
            x=fa[x][k];
            }
    }
    if(x==y)return res;
    for(int k=13;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            res=min(res,min(maa[x][k],maa[y][k]));
            x=fa[x][k],y=fa[y][k];
        }
    }
    res=min(res,min(maa[x][0],maa[y][0]));
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        e[i]={x,y,z};
    }
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++){
        int x=e[i].x,y=e[i].y,z=e[i].z;
        int fx=ff(x),fy=ff(y);
        if(fx!=fy){
            add(x,y,z);
            add(y,x,z);
            f[fx]=fy;
        }
    }
    memset(maa,0x3f,sizeof maa);
    for(int i=1;i<=n;i++){
        if(!depth[i]){
            idx[i]=++cid;
            depth[i]=1;
            dfs(i);
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(idx[x]!=idx[y])puts("-1");
        else printf("%d\n",lca(x,y));
    }
    return 0;
}