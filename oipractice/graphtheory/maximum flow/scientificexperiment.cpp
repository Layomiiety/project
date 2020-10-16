//acw2176
#include <bits/stdc++.h>
using namespace std;
const int N=55,M=N*N,inf=1e9;
int n,m,S,T,h[N<<1],nex[M],to[M],c[M],st[N<<1],idx;
int d[N<<1],cur[N<<1],q[N<<1];
inline void add(int u,int v,int w){
    to[idx]=v,nex[idx]=h[u],c[idx]=w,h[u]=idx++;
    to[idx]=u,nex[idx]=h[v],c[idx]=0,h[v]=idx++;
}
bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=0;
    q[hh]=S,d[S]=0,cur[S]=h[S];
    while(hh<=tt){
        int x=q[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(d[j]==-1&&c[i]){
                d[j]=d[x]+1;
                cur[j]=h[j];
                if(j==T)return true;
                q[++tt]=j;
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
        if(d[j]==d[x]+1&&c[i]){
            int s=find(j,min(limit-res,c[i]));
            if(s){
                res+=s;
                c[i]-=s;
                c[i^1]+=s;
            }
            else d[j]=-1;
        }
    }
    return res;
}
int dinic(){
    int res=0,flow;
    while(bfs())while(flow=find(S,inf))res+=flow;
    return res;
}
void dfs(int x){
    st[x]=true;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(c[i]&&!st[j])dfs(j);
    }
}
int main(){
    scanf("%d%d",&m,&n);
    S=0,T=n+m+1;
    memset(h,-1,sizeof h);
    getchar();
    int pos=0;
    for(int i=1;i<=m;i++){
        string line;
        int v,id;
        getline(cin,line);
        stringstream ssin(line);
        ssin>>v;
        pos+=v;
        add(S,i,v);
        while(ssin>>id)add(i,m+id,inf);
    }
    for(int i=1;i<=n;i++){
        int v;
        scanf("%d",&v);
        add(i+m,T,v);
    }
    int mc=dinic();
    dfs(S);
    for(int i=1;i<=m;i++){if(st[i])printf("%d ",i);}
    puts("");
    for(int i=m+1;i<=m+n;i++){if(st[i])printf("%d ",i-m);}
    puts("");
    printf("%d",pos-mc);
    return 0;
}