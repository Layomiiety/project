#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define il inline
using namespace std;
const int N=105,M=N*N;
int h[N],to[M],nex[M],cnt=1,n,dfn[N],low[N],idx[N],scc,stk[N],cc,tt,dout[N],din[N];
bool inst[N];
il void add(int x,int y){to[cnt]=y,nex[cnt]=h[x],h[x]=cnt++;}
il void tarjan(int x){
    stk[++tt]=x;
    inst[x]=true;
    dfn[x]=low[x]=++cc;
    for(int i=h[x];i;i=nex[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j);
            low[x]=min(low[x],low[j]);
        }
        else if(inst[j])low[x]=min(low[x],dfn[j]);
    }
    if(low[x]==dfn[x]){
        scc++;
        int y;
        do{
            y=stk[tt--];
            idx[y]=scc;
            inst[y]=false;
        }while(y!=x);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        while(cin>>m,m)add(i,m);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
        }
    for(int i=1;i<=n;i++){
        //printf("%d %d %d %d\n",i,idx[i],dfn[i],low[i]);
        for(int j=h[i];j;j=nex[j]){
            int k=to[j];
            if(idx[i]!=idx[k]){
                din[idx[k]]++;
                dout[idx[i]]++;
            }
        }
    }
    int zin=0,zout=0;
    for(int i=1;i<=scc;i++){
        //printf("%d %d\n",din[i],dout[i]);
        if(!din[i])zin++;
        if(!dout[i])zout++;
    }
    printf("%d\n",zin);
    if(scc==1)printf("0");
    else printf("%d",max(zin,zout));
    return 0;
}