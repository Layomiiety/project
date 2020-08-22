#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=210,M=25000,inf=1e9;
int n,m,s,t,S,T;
int h[N],to[M],nex[M],f[M],idx;
int cur[N],q[N],d[N],in[N];
il void add(int a,int b,int c){
    to[idx]=b,f[idx]=c,nex[idx]=h[a],h[a]=idx++;
    to[idx]=a,f[idx]=0,nex[idx]=h[b],h[b]=idx++;
}
il bool bfs(){
    int tt=0,hh=0;
    memset(d,-1,sizeof d);
    q[tt++]=S,d[S]=0,cur[S]=h[S];
    while(hh<tt){
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
il int find(int x,int limit){
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
il int dinic(){
    int res=0,flow;
    while(bfs()){
        while(flow=find(S,inf))res+=flow;
    }
    return res;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    memset(h,-1,sizeof h);
    add(t,s,inf);
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,d-c);
        in[a]-=c,in[b]+=c;
    }
    int tot=0;
    S=0,T=n+1;
    for(int i=1;i<=n;i++){
        if(in[i]>0){
            add(S,i,in[i]);
            tot+=in[i];
            }
        else if(in[i]<0)add(i,T,-in[i]);
    }
    if(dinic()!=tot)puts("No Solution");
    else {
        int res=f[1];
        f[0]=f[1]=0;
        S=s,T=t;
        printf("%d",res+dinic());
    }
    return 0;
}