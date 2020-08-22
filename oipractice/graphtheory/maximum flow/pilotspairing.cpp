//acw2175
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int N=210,M=20010;
int m,n;
int h[N],to[M],nex[M],f[M],idx;
int cur[N],d[N],q[N];
inline void add(int u,int v,int w){
    to[idx]=v,nex[idx]=h[u],f[idx]=w,h[u]=idx++;
    to[idx]=u,nex[idx]=h[v],f[idx]=0,h[v]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    d[0]=0;
    int hh=0,tt=1;
    q[0]=0;
    cur[0]=h[0];
    while(hh!=tt){
        int x=q[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(!f[i]||d[j]!=-1)continue;
            d[j]=d[x]+1;
            cur[j]=h[j];
            if(j==n+1)return true;
            q[tt++]=j;
        }
    }
    return false;
}
inline int find(int x,int limit){
    if(x==n+1)return limit;
    int res=0;
    for(int i=cur[x];~i&&res<limit;i=nex[i]){
        int j=to[i];
        cur[x]=i;
        if(d[j]==d[x]+1&&f[i]){
            int s=find(j,min(limit-res,f[i]));
            if(s){
                res+=s;
                f[i]-=s;
                f[i^1]+=s;
            }
            else d[j]=-1;
        }
    }
    return res;
}
int main(){
    scanf("%d%d",&m,&n);
    memset(h,-1,sizeof h);
    int i,j;
    while(cin>>i>>j,~i)add(i,j,1);
    for(int i=1;i<=m;i++)add(0,i,1);
    for(int i=m+1;i<=n;i++)add(i,n+1,1);
    int flow=0,res=0;
    while(bfs())while(flow=find(0,500000))res+=flow;
    printf("%d\n",res);
    for(int i=0;i<idx;i+=2){
        if(!f[i]){
            if(!to[i^1])break;
            printf("%d %d\n",to[i^1],to[i]);
        }
    }
    return 0;
}