#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=205,M=25000;
int n,m,S,T;
int f[M],h[N],to[M],nex[M],l[M],idx;
int in[N];
int cur[N],d[N],q[N];
il void add(int a,int b,int c){
    to[idx]=b,nex[idx]=h[a],f[idx]=c,h[a]=idx++;
    to[idx]=a,nex[idx]=h[b],f[idx]=0,h[b]=idx++;
}
il bool bfs(){
    memset(d,-1,sizeof d);
    int tt=0,hh=0;
    q[tt++]=S;
    cur[S]=h[S],d[S]=0;
    while(hh<tt){
        int t=q[hh++];
        for(int i=h[t];~i;i=nex[i]){
            int j=to[i];
            if(d[j]==-1&&f[i]){
                cur[j]=h[j];
                d[j]=d[t]+1;
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
            int s=find(j,min(f[i],limit-res));
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
    scanf("%d%d",&n,&m);
    S=0,T=n+1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,d-c);
        l[i]=c;
        in[b]+=c;
        in[a]-=c;
    }
    int ff=0;
    for(int i=1;i<=n;i++){
        if(in[i]<0)add(i,T,-in[i]);
        else if(in[i]>0){
            add(S,i,in[i]);
            ff+=in[i];
        }
    }
    int flow,res=0;
    while(bfs())while(flow=find(S,1e8))res+=flow;
    if(res!=ff)puts("NO");
    else {
        puts("YES");
        for(int i=1;i<=m;i++){
            printf("%d\n",f[2*i-1]+l[i]);
        }
    }
    return 0;
}