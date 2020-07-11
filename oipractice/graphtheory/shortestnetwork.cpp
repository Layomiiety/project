//acw1140
#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int g[maxn][maxn];
int n,m;
int dis[maxn];
bool vis[maxn];

int prim(){
    int sum=0;
    memset(dis,0x3f,sizeof dis);dis[1]=0;
    for(int l=0;l<n;l++){
        int t=0;
        for(int i=1;i<=n;i++)if(!vis[i]&&(!t||dis[t]>dis[i]))t=i;
        sum+=dis[t];
        for(int i=1;i<=n;i++)dis[i]=min(dis[i],g[t][i]);
        vis[t]=1;
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&g[i][j]);
    printf("%d\n",prim());
    return 0;
}
