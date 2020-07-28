//acw2171
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define il inline
#define LL long long
using namespace std;
const int N=1010,M=20010,inf=1e8;
int n,m,S,T;
int h[N],nex[M],cap[M],to[M],idx;
int d[N],pre[N],q[N];
int st[N];
il void add(int a,int b,int c){
    to[idx]=b,cap[idx]=c,nex[idx]=h[a],h[a]=idx++;
    to[idx]=a,cap[idx]=0,nex[idx]=h[b],h[b]=idx++;
}
il bool bfs(){
    int hh=0,tt=0;
    memset(st,false,sizeof st);
    d[S]=inf;
    q[0]=S;
    st[S]=true;
    while(hh<=tt){
        int cur=q[hh++];
        for(int i=h[cur];~i;i=nex[i]){
            int ver=to[i];
            if(!st[ver]&&cap[i]){
                st[ver]=true;
                d[ver]=min(cap[i],d[cur]);
                pre[ver]=i;
                if(ver==T)return true;
                q[++tt]=ver;
            }
        }
    }
    return false;
}
int ek(){
    int res=0;
    while(bfs()){
        res+=d[T];
        for(int i=T;i!=S;i=to[pre[i]^1]){
            cap[pre[i]]-=d[T],cap[pre[i]^1]+=d[T];
        }
    }
    return res;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&S,&T);
    memset(h,-1,sizeof h);
    while(m--){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        add(u,v,c);
    }
    printf("%d",ek());
    return 0;
}