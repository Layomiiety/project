//acw2179
#include <bits/stdc++.h>
using namespace std;
const int N=500,M=N*N;
int m,n,S,T;
int h[N],nex[M],to[M],f[M],idx;
int cur[N],d[N],q[N];
inline void add(int x,int y,int w){
    to[idx]=y,nex[idx]=h[x],f[idx]=w,h[x]=idx++;
    to[idx]=x,nex[idx]=h[y],f[idx]=0,h[y]=idx++;
}
inline bool bfs(){
    int hh=0,tt=1;
    memset(d,-1,sizeof d);
    q[0]=S,cur[S]=h[S],d[S]=0;
    while(hh!=tt){
        int x=q[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(d[j]==-1&&f[i]){
                d[j]=d[x]+1;
                cur[j]=h[j];
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
            int flow=find(j,min(limit-res,f[i]));
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
int main(){
    scanf("%d%d",&m,&n);
    memset(h,-1,sizeof h);
    S=0,T=m+n+1;
    int sum=0;
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        add(S,i,x);
        sum+=x;
        for(int j=m+1;j<=m+n;j++)add(i,j,1);
    }
    for(int i=m+1;i<=m+n;i++){
        int x;
        scanf("%d",&x);
        add(i,T,x);
    }
    int res=0,flow;
    while(bfs())while(flow=find(S,30000))res+=flow;
    if(res==sum){
        puts("1");
        for(int i=1;i<=m;i++){
            for(int j=h[i];~j;j=nex[j]){
                int k=to[j];
                if(!f[j]&&k){
                    printf("%d ",k-m);
                }
            }
            puts("");
        }
    }
    else puts("0");
    return 0;
}