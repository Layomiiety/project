//acw1171
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> pii;
const int N=1e4+5,M=N<<1;
int h[N],nex[M],to[M],w[M],cnt=1,n,m,dist[N],st[N],fa[N],a,b,c,res[M];
vector <pii>query[N];
inline void add(int x,int y,int z){to[cnt]=y,w[cnt]=z,nex[cnt]=h[x],h[x]=cnt++;}
inline int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
inline void dfs(int cur,int pre){
    for(int i=h[cur];i;i=nex[i]){
        int j=to[i];
        if(j==pre)continue;
        dist[j]=dist[cur]+w[i];
        dfs(j,cur);
    }
} 
inline void tarjan(int x){
    st[x]=1;
    for(int i=h[x];i;i=nex[i]){
        int j=to[i];
        //printf("%d %d %d\n",dist[j],i,j);
        if(st[j])continue;
        tarjan(j);
        fa[j]=x;
    }
    for(auto m:query[x]){
        int y=m.first,idx=m.second;
        if(st[y]==2){
            int anc=ff(y);
            res[idx]=dist[x]+dist[y]-dist[anc]*2;
        }
    }
    st[x]=2;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
        }
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    dfs(1,0);
    tarjan(1);
    for(int i=0;i<m;i++)printf("%d\n",res[i]);
    return 0;
}