//acw396
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1005,M=2005;
int n,m,t=0,h[N],to[M],nex[M],cnt;
int dfn[N],low[N],cc,dcc,stk[N],tt,root;
bool is_cut[N];
vector <int> dc[N];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il void tarjan(int a){
    low[a]=dfn[a]=++cc;
    if(h[a]==-1){dcc++;dc[dcc].push_back(a);return;}
    stk[++tt]=a;
    int ppc=0;
    for(int i=h[a];~i;i=nex[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j);
            low[a]=min(low[a],low[j]);
            if(low[j]>=dfn[a]){
                ppc++;
                if(ppc>1||a!=root)is_cut[a]=true;
                int y;
                dcc++;
                do{
                    y=stk[tt--];
                    dc[dcc].push_back(y);
                }while(y!=j);
                dc[dcc].push_back(a);
                }
        }
        else low[a]=min(low[a],dfn[j]);
    }
    return;
}
int main(){
    while(cin>>m,m){
        n=1;
        t++;
        for(int i=1;i<=dcc;i++)dc[i].clear();
        cnt=cc=dcc=tt=0;
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        memset(is_cut,0,sizeof is_cut);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            n=max(n,max(a,b));
            add(a,b),add(b,a);
        }
        int minadd=0;
        LL ans=1;
        for(root=1;root<=n;root++){
            if(!dfn[root])tarjan(root);
        }
        for(int i=1;i<=dcc;i++){
            int cutcc=0;
            for(int j:dc[i]){
                if(is_cut[j])cutcc++;
            }
            if(!cutcc){
                if(dc[i].size()==1)minadd++;
                else {minadd+=2,ans*=dc[i].size()*(dc[i].size()-1)/2;}
                }
            else if(cutcc==1){
                minadd+=1;
                ans*=(dc[i].size()-1);
            }
        }
        printf("Case %d: %d %lld\n",t,minadd,ans);
    }
    return 0;
}