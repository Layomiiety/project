//acw395
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define il inline
#define ll long long
using namespace std;
const int N=5005,M=20005;
int h[N],nex[M],to[M],cnt=1,n,m,d[N];
int dfn[N],low[N],stk[N],tt=0,id[N],cc=0,dcc=0;
bool is_bridge[M];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il void tarjan(int x,int f){
    low[x]=dfn[x]=++cc;
    stk[++tt]=x;
    for(int i=h[x];i;i=nex[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j,x);
            low[x]=min(low[x],low[j]);
            if(low[j]>dfn[x])is_bridge[i]=is_bridge[2*i-(i^1)]=true;
            }
        else if(j!=f)low[x]=min(low[x],dfn[j]);
    }
    if(low[x]==dfn[x]){
        dcc++;
        int y;
        do{
            y=stk[tt--];
            id[y]=dcc;
        }while(x!=y);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    tarjan(1,0);
    for(int i=1;i<=cnt;i++){
        if(is_bridge[i])d[id[to[i]]]++;
    }
    int ans=0;
    //for(int i=1;i<=n;i++)printf("%d %d\n",dfn[i],low[i]);
    for(int i=1;i<=dcc;i++){
        //printf("%d ",d[i]);
        if(d[i]==1)ans++;
    }
    printf("%d",(ans+1)/2);
    return 0;
}