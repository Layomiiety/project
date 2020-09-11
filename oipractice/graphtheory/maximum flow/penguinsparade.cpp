//acw2278
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=205,M=50005,inf=1e8;
const double eps=1e-8;
int ca,n,S,T;
double md;
int h[N],to[M],nex[M],f[M],idx;
int cur[N],d[N],q[N];
struct ice{
    int x,y,p,m;
}ma[N];
inline void add(int a,int b,int c){
    to[idx]=b,nex[idx]=h[a],f[idx]=c,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],f[idx]=0,h[b]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    d[S]=0,q[0]=S,cur[S]=h[S];
    int hh=0,tt=1;
    while(hh!=tt){
        int x=q[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(d[j]==-1&&f[i]){
                cur[j]=h[j];
                d[j]=d[x]+1;
                if(j==T)return true;
                q[tt++]=j;
            }
        }
    }
    return false;
}
inline int find(int x,int limit){
    if(x==T)return limit;
    int res=0;
    for(int i=cur[x];~i&&res<limit;i=nex[i]){
        int j=to[i];
        cur[x]=i;
        if(d[j]==d[x]+1&&f[i]){
            int flow=find(j,min(f[i],limit-res));
            if(flow){
                res+=flow;
                f[i]-=flow;
                f[i^1]+=flow;
            }
            else d[j]=-1;
        }
    }
    return res;
}
inline int dinic(){
    int res=0,flow;
    while(bfs())while(flow=find(S,inf))res+=flow;
    return res;
}
inline bool ck(ice x,ice y){
    int dx=x.x-y.x,dy=x.y-y.y;
    if(sqrt(dx*dx+dy*dy)<md+eps)return true;
    return false;
}
inline void init(int t){
    memset(h,-1,sizeof h);
    idx=0;
    T=t;
    for(int i=0;i<n;i++){
        if(ma[i].p)add(S,i,ma[i].p);
        for(int j=0;j<n;j++){
            if(j==i)add(j,j+n,ma[i].m);
            else if(ck(ma[i],ma[j]))add(j+n,i,inf);
        }
    }
}
int main(){
    scanf("%d",&ca);
    S=N-1;
    while(ca--){
        scanf("%d%lf",&n,&md);
        int pp=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            int x,y,p,m;
            scanf("%d%d%d%d",&x,&y,&p,&m);
            pp+=p;
            ma[i]={x,y,p,m};
            }
        for(int i=0;i<n;i++){
            init(i);
            if(dinic()==pp){
                printf("%d ",i);
                flag=true;
            }
        }
        if(!flag)printf("-1");
        puts("");
    }
    return 0;
}