//acw1183
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define il inline
#define ll long long
using namespace std;
const int N=10005,M=30005;
int h[N],nex[M],to[M],cnt,n,m;
int dfn[N],low[N],idx[N],cc,dcc,ans;
il void add(int a ,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il void tarjan(int x,int root){
    low[x]=dfn[x]=++cc;
    int c=0;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j,root);
            low[x]=min(low[x],low[j]);
            if(low[j]>=dfn[x])c++;
        }
        else low[x]=min(low[x],dfn[j]);
    }
    if(x!=root)c++;
    ans=max(ans,c);
}
int main(){
    while(scanf("%d%d",&n,&m),n||m){
        memset(h,-1,sizeof h);
        cnt=cc=dcc=ans=0;
        memset(dfn,0,sizeof dfn);
        //memset(low,0,sizeof low);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b),add(b,a);
        }
        for(int i=0;i<n;i++){
            if(!dfn[i]){
                dcc++;
                tarjan(i,i);
            }        
        }
        printf("%d\n",ans+dcc-1);
    }
}