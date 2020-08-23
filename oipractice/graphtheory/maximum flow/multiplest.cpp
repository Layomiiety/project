//acw2234
#include <bits/stdc++.h>
using namespace std;
const int N=10005,M=3e5,inf=1e9;
int n,m,sc,tc,S,T;
int h[N],to[M],nex[M],f[M],idx;
int cur[N],d[N],q[N];
inline void add(int u,int v,int c){
    to[idx]=v,f[idx]=c,nex[idx]=h[u],h[u]=idx++;
    to[idx]=u,f[idx]=0,nex[idx]=h[v],h[v]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=0;
    q[tt++]=S,d[S]=0,cur[S]=h[S];
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
        cur[x]=i;
        int j=to[i];
        if(d[j]==d[x]+1&&f[i]){
            int flow=find(j,min(f[i],limit-res));
            if(flow){
                f[i]-=flow;
                f[i^1]+=flow;
                res+=flow;
            }
            else d[j]=-1;
        }
    }
    return res;
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d%d%d",&n,&m,&sc,&tc);
    S=0,T=n+1;
    for(int i=0;i<sc;i++){
        int s;
        scanf("%d",&s);
        add(S,s,inf);
    }
    for(int i=0;i<tc;i++){
        int t;
        scanf("%d",&t);
        add(t,T,inf);
    }
    for(int i=0;i<m;i++){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        add(u,v,c);
    }
    int flow,res=0;
    while(bfs())while(flow=find(S,inf))res+=flow;
    printf("%d",res);
    return 0;
}