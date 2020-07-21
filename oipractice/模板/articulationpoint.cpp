#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#define il inline 
using namespace std;
const int N=2e4+5,M=2e5+5;
int n,m,h[N],nex[M],to[M],cnt=0;
int dfn[N],low[N],stamp,root;
bool is_art[N];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il void tarjan(int x,int last){
    dfn[x]=low[x]=++stamp;
    int cc=0;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(!dfn[j]){
            tarjan(j,i);
            low[x]=min(low[x],low[j]);
            if(low[j]>=dfn[x]){
                cc++;
                if(cc>1||x!=root)is_art[x]=true;
            }
        }
        else if(i!=1^last)low[x]=min(low[x],dfn[j]);
        }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(root=1;root<=n;root++){
        if(!dfn[root])tarjan(root,-1);
    }
    int ans=0,art[N];
    for(int i=1;i<=n;i++){
        if(is_art[i])art[ans++]=i;
    }
    printf("%d\n",ans);//number of articulation points
    for(int i=0;i<ans;i++)printf("%d ",art[i]);//index of every articulation point
    return 0;
}