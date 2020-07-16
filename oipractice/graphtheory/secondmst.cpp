//acw356
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
const int N=1e5+5,M=3e5+5,inf=0x3f3f3f3f;
int h[N],nex[M],to[M],ww[M],cnt=1,n,m,x,y,z,fa[N],depth[N],d1[N][17],d2[N][17],p[N][17],d[2*N];
LL sum=0,res=1e18;
struct edge {
    int u,v,w;
    bool inn;
    bool operator <(const edge &t)const{
        return w<t.w;
    }
}e[M];
inline void add(int x,int y,int z){to[cnt]=y,ww[cnt]=z,nex[cnt]=h[x],h[x]=cnt++;}
inline int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
inline void dfs(int cur,int father){
    for(int i=h[cur];i;i=nex[i]){
        int j=to[i];
        if(j==father)continue;
        depth[j]=depth[cur]+1;
        p[j][0]=cur;
        d1[j][0]=ww[i],d2[j][0]=-inf;
        for(int k=1;k<=16;k++){
            int anc=p[j][k-1];
            p[j][k]=p[anc][k-1];
            int dd[4]={d1[j][k-1],d2[j][k-1],d1[anc][k-1],d2[anc][k-1]};
            //d1[j][k]=d2[j][k]=-inf;
            for(int i=0;i<4;i++){
                if(dd[i]>d1[j][k]){d2[j][k]=d1[j][k],d1[j][k]=dd[i];}
                else if(dd[i]!=d1[j][k]&&dd[i]>d2[j][k])d2[j][k]=dd[i];
            }
        }
        dfs(j,cur);
    }
}
inline int lca(int a,int b, int w){
    int cnt=0;
    if(depth[a]<depth[b])swap(a,b);
    for(int k=16;k>=0;k--){
        if(depth[p[a][k]]>=depth[b]){
            d[cnt++]=d1[a][k];
            d[cnt++]=d2[a][k];
            a=p[a][k];
        }
    }
    if(a!=b){
        for(int k=16;k>=0;k--){
            if(p[a][k]!=p[b][k]){
                d[cnt++]=d1[a][k];
                d[cnt++]=d2[a][k];
                d[cnt++]=d1[b][k];
                d[cnt++]=d2[b][k];
                //printf("%d %d %d %d %d\n",a,b,k,d1[a][k],d1[b][k]);
                a=p[a][k],b=p[b][k];
            }
        }
        d[cnt++]=d1[a][0];
        d[cnt++]=d1[b][0];
    }
    int mm=-inf,sm=-inf;
    for(int i=0;i<cnt;i++){
        int cd=d[i];
        if(cd>mm){sm=mm,mm=cd;}
        else if(cd!=mm&&cd>sm)sm=cd;
    }
    if(w>mm)return w-mm;
    if(w>sm)return w-sm;
    return inf;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        e[i]={x,y,z};
        }
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e,e+m);
    for(int i=0;i<m;i++){
        x=ff(e[i].u),y=ff(e[i].v),z=e[i].w;
        if(x!=y){
            fa[x]=y;
            sum+=z;
            e[i].inn=true;
            add(e[i].u,e[i].v,z);
            add(e[i].v,e[i].u,z);
            }
        }
    depth[1]=1,depth[0]=0;
    dfs(1,0);
    for(int i=0;i<m;i++){
        if(!e[i].inn){
            res=min(res,sum+lca(e[i].u,e[i].v,e[i].w));
        }
    }
    printf("%lld",res);
    return 0;
}
