//acw2187
#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=800,M=2*N*N,inf=1e8;
struct ship{
    int cap,r;
    int s[25];
}ss[25];
int n,m,k,S,T;
int h[N],to[M],nex[M],f[M],idx;
int cur[N],d[N],q[N];
int fa[25];
il int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
il int get(int sta,int day){
    return sta+day*(n+2);
}
il void add(int a,int b,int c){
    to[idx]=b,nex[idx]=h[a],f[idx]=c,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],f[idx]=0,h[b]=idx++;
}
il bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=0;
    cur[S]=h[S],d[S]=0,q[tt++]=S;
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
    while(bfs())while(flow=find(S,inf))res+=flow;
    return res;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    memset(h,-1,sizeof h);
    S=N-2,T=N-1;
    for(int i=0;i<=n+1;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&ss[i].cap,&ss[i].r);
        int x;
        for(int j=0;j<ss[i].r;j++){
            scanf("%d",&x);
            if(x==-1)x=n+1;
            ss[i].s[j]=x;
        }
        for(int j=1;j<ss[i].r;j++){
            fa[ff(ss[i].s[j])]=ff(ss[i].s[0]);
        }
    }
    if(ff(0)!=ff(n+1))puts("0");
    else {
        add(S,get(0,0),inf);
        int day=1,res=0;
        while(true){
            for(int i=0;i<=n;i++)add(get(i,day-1),get(i,day),inf);
            add(get(n+1,day),T,inf);
            for(int i=1;i<=m;i++){
                int r=ss[i].r,c=ss[i].cap;
                add(get(ss[i].s[(day-1)%r],day-1),get(ss[i].s[day%r],day),c);
            }
            res+=dinic();
            if(res>=k){
                printf("%d",day);
                break;
            }
            day++;
        }
    }
    return 0;
}