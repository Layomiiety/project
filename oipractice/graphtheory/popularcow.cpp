//acw1174
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#define il inline
using namespace std;
const int N=1e4+5,M=5e4+5;
int h[N],to[M],nex[M],cnt=1,n,m,dfn[N],low[N],idx[N],scc,stk[N],cc,tt,dout[N],siz[N];
bool inst[N];
il void add(int x,int y){to[cnt]=y,nex[cnt]=h[x],h[x]=cnt++;}
il void tarjan(int x){
    dfn[x]=++cc;
    low[x]=cc;
    stk[++tt]=x;
    inst[x]=true;
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
            //printf("%d %d\n",scc,y);
            idx[y]=scc;
            inst[y]=false;
            siz[scc]++;
        }while(y!=x);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++){
        //printf("%d %d %d %d\n",i,dfn[i],low[i],idx[i]);
        for(int j=h[i];j;j=nex[j]){
            int k=to[j];
            if(idx[i]!=idx[k]){
                dout[idx[i]]++;
            }
        }
    }
    int zeros=0,sum=0;
    for(int i=1;i<=scc;i++){
        if(!dout[i]){
            sum+=siz[i];
            zeros++;
            if(zeros>1){
                sum=0;
                break;
            }
        }
    }
    printf("%d",sum);
    return 0;
}