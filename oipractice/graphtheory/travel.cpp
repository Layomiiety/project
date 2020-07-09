#include <bits/stdc++.h>
using namespace std;
const int N=105,inf=0x3f3f3f3f;
int adj[N][N],dist[N][N],tr[N][N],path[N],cnt,ans=inf,n,m,u,v,l;
inline void get_path(int i,int j){
    if(!tr[i][j])return;
    get_path(i,tr[i][j]);
    path[cnt++]=tr[i][j];
    get_path(tr[i][j],j);
    return;
}
int main(){
    cin>>n>>m;
    memset(adj,0x3f,sizeof adj);
    while(m--){
        scanf("%d%d%d",&u,&v,&l);
        adj[u][v]=adj[v][u]=min(adj[v][u],l);
    }
    memcpy(dist,adj,sizeof adj);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(ans>(long long)adj[i][k]+adj[j][k]+dist[i][j]){
                    ans=adj[i][k]+adj[j][k]+dist[i][j];
                    cnt=0;
                    path[cnt++]=k;
                    path[cnt++]=i;
                    get_path(i,j);
                    path[cnt++]=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
                    tr[i][j]=tr[j][i]=k;
                }
            }
        }
    }
    if(ans==inf)puts("No solution.");
    else for(int i=0;i<cnt;i++)printf("%d ",path[i]);
    return 0;
}