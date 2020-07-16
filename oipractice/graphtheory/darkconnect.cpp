//acw354
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
const int N=1e5+5,M=2e5+5;
int n,m,h[N],nex[M],to[M],cnt=1,x,y,depth[N],d[N],fa[N][17],res;
il void add(int a,int b){nex[cnt]=h[a],to[cnt]=b,h[a]=cnt++;}
void bfs(){
    queue<int> q;
    memset(depth,0x3f,sizeof depth);
    depth[1]=1,depth[0]=0;
    q.push(1);
    while(!q.empty()){
        int hh=q.front();
        q.pop();
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(depth[j]>depth[hh]+1){
                depth[j]=depth[hh]+1;
                q.push(j);
                fa[j][0]=hh;
                for(int k=1;k<=16;k++)fa[j][k]=fa[fa[j][k-1]][k-1];
            }
        }
    }
}
il int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    for(int k=16;k>=0;k--){
        if(depth[fa[x][k]]>=depth[y]){
            x=fa[x][k];
        }
    }
    if(x==y)return x;
    for(int k=16;k>=0;k--){
        if(fa[x][k]!=fa[y][k]){
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return fa[x][0];
}
il int dfs(int cur,int father){
    int cs=d[cur];
    for(int i=h[cur];i;i=nex[i]){
        int j=to[i];
        if(j==father)continue;
        int s=dfs(j,cur);
        if(!s)res+=m;
        else if(s==1)res++;
        cs+=s;
    }
    return cs;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y),add(y,x);
    }
    bfs();
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        int ac=lca(x,y);
        d[ac]-=2,d[x]++,d[y]++;
    }
    dfs(1,0);
    printf("%d",res);
    return 0;
}