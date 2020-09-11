//acw2277
#include <bits/stdc++.h>
using namespace std;
const int N=205,M=80005;
int n,p,t,S,T;
int h[N],to[M],nex[M],f[M],l[M],idx;
int q[N],cur[N],d[N];
inline void add(int a,int b,int c){
    to[idx]=b,nex[idx]=h[a],l[idx]=c,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],l[idx]=c,h[b]=idx++;
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
                res+=flow;
                f[i]-=flow;
                f[i^1]+=flow;
            }
            else d[j]=-1;
        }
    }
    return res;
}
inline int dinic(int x){
    for(int i=0;i<idx;i++){
        if(l[i]>x)f[i]=0;
        else f[i]=1;
    }
    int res=0,flow;
    while(bfs())while(flow=find(S,1e8))res+=flow;
    return res;
}
int main(){
    scanf("%d%d%d",&n,&p,&t);
    S=1,T=n;
    memset(h,-1,sizeof h);
    while(p--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int lb=0,rb=1e6;
    while(lb<rb){
        int mid=lb+rb>>1;
        if(dinic(mid)>=t)rb=mid;
        else lb=mid+1;
    }
    printf("%d",rb);
    return 0;
}
