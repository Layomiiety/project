//acw2172
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=10005,M=200100,inf=1e8;
int h[N],nex[M],to[M],f[M],idx;
int q[N],cur[N],d[N];
int n,m,s,t;
inline void add(int a,int b,int c){
    to[idx]=b,nex[idx]=h[a],f[idx]=c,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],f[idx]=0,h[b]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=0;
    q[tt++]=s;
    d[s]=0;
    cur[s]=h[s];
    while(hh!=tt){
        int u=q[hh++];
        for(int i=h[u];~i;i=nex[i]){
            int j=to[i];
            if(d[j]==-1&&f[i]){
                d[j]=d[u]+1;
                cur[j]=h[j];
                if(j==t)return true;
                q[tt++]=j;
            }
        }
    }
    return false;
}
inline int find(int u,int limit){
    if(u==t)return limit;
    int res=0;
    for(int i=cur[u];~i&&res<limit;i=nex[i]){
        cur[u]=i;
        int j=to[i];
        if(d[j]==d[u]+1&&f[i]){
            int s=find(j,min(f[i],limit-res));
            if(!s)d[j]=-1;
            else {
                f[i]-=s;
                f[i^1]+=s;
                res+=s;
            }
        }
    }
    return res;
}
int dinic(){
    int flow,res=0;
    while(bfs())while(flow=find(s,inf))res+=flow;
    return res;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    printf("%d",dinic());
    return 0;
}
