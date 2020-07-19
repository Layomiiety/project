//acw1175
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#define il inline
#define ll long long
using namespace std;
const int N=1e5+5,M=1e6+5;
int n,m,x,h[N],nex[M],to[M],cnt=1;
int dfn[N],low[N],idx[N],scc,cc,siz[N],stk[N],tt;
int f[N],fh[N],fn[M],ft[M],fc=1,fcc[N];
bool inst[N];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il void adde(int a,int b){ft[fc]=b,fn[fc]=fh[a],fh[a]=fc++;}
il void tarjan(int a){
    dfn[a]=low[a]=++cc;
    inst[a]=true;
    stk[++tt]=a;
    for(int i=h[a];i;i=nex[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j);
            low[a]=min(low[a],low[j]);
            }
        else if(inst[j])low[a]=min(low[a],dfn[j]);
    }
    if(dfn[a]==low[a]){
        int y;
        scc++;
        do{
            y=stk[tt--];
            idx[y]=scc;
            inst[y]=false;
            siz[scc]++;
        }while(a!=y);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++){if(!dfn[i])tarjan(i);}
    for(int i=1;i<=n;i++){
        for(int j=h[i];j;j=nex[j]){
            int k=to[j];
            int a=idx[i],b=idx[k];
            if(a!=b){
                adde(a,b);
            }
        }
    }
    unordered_set<ll> S;
    for(int i=1;i<=scc;i++){f[i]=siz[i],fcc[i]=1;}
    for(int i=scc;i>0;i--){
        S.empty();
        for(int j=fh[i];j;j=fn[j]){
            int k=ft[j];
            ll hash=i*N+k;
            if(S.count(hash))continue;
            S.insert(hash);
            if(f[k]<f[i]+siz[k]){
                f[k]=f[i]+siz[k];
                fcc[k]=fcc[i];
            }
            else if(f[k]==f[i]+siz[k]){
                fcc[k]=(fcc[k]+fcc[i])%x;
            }
        }
    }
    int ans=0,acc=0;
    for(int i=1;i<=scc;i++){
        //printf("%d %d %d %d\n",fcc[i],f[i],i,siz[i]);
        if(f[i]>ans){
            ans=f[i];
            acc=fcc[i];
        }
        else if(f[i]==ans){
            acc=(acc+fcc[i])%x;
        }
    }
    printf("%d\n%d",ans,acc);
    return 0;
}