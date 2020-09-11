//acw2180
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1005,M=50005,inf=1e8;
int n,S,T,a[N];
int h[N],to[M],nex[M],f[M],idx;
int cur[N],d[N],q[N];
inline void add(int a,int b,int c){
    to[idx]=b,nex[idx]=h[a],f[idx]=c,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],f[idx]=0,h[b]=idx++;
}
inline bool bfs(){
    memset(d,-1,sizeof d);
    d[S]=0,q[0]=S,cur[S]=h[S];
    int hh=0,tt=1;
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
                res+=flow;
                f[i]-=flow;
                f[i^1]+=flow;
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
int main(){
    scanf("%d",&n);
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int lis[N],cnt=0;
    S=0,T=N-1;
    for(int i=1;i<=n;i++){
        add(i,i+n,1);
        lis[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<=a[i])lis[i]=max(lis[j]+1,lis[i]);
        }
        for(int j=1;j<i;j++){if(a[j]<=a[i]&&lis[i]==lis[j]+1)add(j+n,i,1);}
        cnt=max(cnt,lis[i]);
        if(lis[i]==1)add(S,i,1);
    }
    printf("%d\n",cnt);
    if(cnt==1)printf("%d\n%d",n,n);
    else{
        for(int i=1;i<=n;i++){if(lis[i]==cnt)add(i+n,T,1);}
        int ans=dinic();
        printf("%d\n",ans);
        add(S,1,inf),add(1,n+1,inf);
        if(lis[n]==cnt){add(n,2*n,inf);add(2*n,T,inf);}
        printf("%d",ans+dinic());
        }
    return 0;
    }