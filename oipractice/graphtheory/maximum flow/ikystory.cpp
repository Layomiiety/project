//acw2236
#include <bits/stdc++.h>
using namespace std;
const int N=505,M=10005,inf=1e8;
int n,m,S,T;
int h[N],to[M],nex[M],f[M],idx;
int cur[N],q[N],d[N];
bool sts[N],stt[N];
inline void add(int a,int b,int c){
    to[idx]=b,f[idx]=c,nex[idx]=h[a],h[a]=idx++;
    to[idx]=a,f[idx]=0,nex[idx]=h[b],h[b]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=0;
    d[S]=0,cur[S]=h[S],q[tt++]=S;
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
                f[i]-=flow;
                f[i^1]+=flow;
                res+=flow;
            }
            else d[j]=-1;
        }
    }
    return res;
}
inline void dfs(int x,bool st[],int ed){
    st[x]=true;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(!st[j]&&f[i^ed])dfs(j,st,ed);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    S=0,T=n-1;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int res=0,flow;
    while(bfs())while(flow=find(S,inf))res+=flow;
    dfs(S,sts,0);
    dfs(T,stt,1);
    int cnt=0;
    for(int i=0;i<idx;i+=2){
        if(!f[i]&&sts[to[i^1]]&&stt[to[i]])cnt++;
    }
    printf("%d",cnt);
    return 0;
}