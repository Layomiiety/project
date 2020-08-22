#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm> 
using namespace std;
const int N=205, M=5005<<1,inf=0x3f3f3f3f;
int n,m,s,t;
int h[N],f[M],to[M],nex[M],idx;
int cur[N],d[N],q[N];
inline void add(int u,int v,int w){
    to[idx]=v,nex[idx]=h[u],f[idx]=w,h[u]=idx++;
    to[idx]=u,nex[idx]=h[v],f[idx]=0,h[v]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=1;
    q[0]=s;
    cur[s]=h[s];
    d[s]=0;
    while(hh!=tt){
        int x=q[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(d[j]==-1&&f[i]){
                cur[j]=h[j];
                d[j]=d[x]+1;
                if(j==t)return true;
                q[tt++]=j;
            }
        }
    }
    return false;
}
inline int find(int x,int limit){
    if(x==t)return limit;
    int res=0;
    for(int i=cur[x];~i&&res<limit;i=nex[i]){
        cur[x]=i;
        int j=to[i];
        if(d[j]==d[x]+1&&f[i]){
            int flow=find(j,min(f[i],limit-res));
            if(flow){
                res+=flow;
                f[i]-=flow;
                d[i^1]+=flow;
            }
            else{
                d[j]=-1;
            } 
        }
    }
    return res;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    int flow=0,res=0;
    while(bfs())while(flow=find(s,inf))res+=flow;
    printf("%d",res);
    return 0;
}
