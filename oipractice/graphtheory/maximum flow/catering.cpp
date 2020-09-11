//acw2240
#include <bits/stdc++.h>
using namespace std;
const int N=405,M=45000;
int n,c,d,S,T;
int h[N],to[M],nex[M],f[M],idx;
int q[N],cur[N],dd[N];
inline void add(int a,int b,int x){
    to[idx]=b,nex[idx]=h[a],f[idx]=x,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],f[idx]=0,h[b]=idx++;
}
inline bool bfs(){
    memset(dd,-1,sizeof dd);
    int hh=0,tt=0;
    q[tt++]=S,dd[S]=0,cur[S]=h[S];
    while(hh!=tt){
        int x=q[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(dd[j]==-1&&f[i]){
                cur[j]=h[j];
                dd[j]=dd[x]+1;
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
        if(dd[j]==dd[x]+1&&f[i]){
            int flow=find(j,min(f[i],limit-res));
            if(flow){
                res+=flow;
                f[i]-=flow;
                f[i^1]+=flow;
            }
            else dd[j]=-1;
        }
    }
    return res;
}
int main(){
    scanf("%d%d%d",&n,&c,&d);
    S=0,T=n+c+d+n+1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=c;i++)add(S,i+2*n,1);
    for(int i=1;i<=d;i++)add(i+2*n+c,T,1);
    for(int i=1;i<=n;i++){
        int c1,d1;
        scanf("%d%d",&c1,&d1);
        while(c1--){
            int x;
            scanf("%d",&x);
            add(2*n+x,i,1);
        }
        add(i,i+n,1);
        while(d1--){
            int x;
            scanf("%d",&x);
            add(i+n,2*n+c+x,1);
        }
    }
    int res=0,flow;
    while(bfs())while(flow=find(S,1e8))res+=flow;
    printf("%d",res);
    return 0;
}