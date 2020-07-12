//acw1146
#include <bits/stdc++.h>
using namespace std;
const int N=305,inf=0x3f3f3f3f;
int n,p[N][N],v;
int prim(){
    int res=0;
    bool st[N];
    int dist[N];
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    for(int i=0;i<=n;i++){
        int cur=-1;
        for(int j=0;j<=n;j++){
            if(!st[j]&&(cur==-1||dist[cur]>dist[j]))cur=j;
        }
        st[cur]=true;
        res+=dist[cur];
        for(int j=0;j<=n;j++){
            dist[j]=min(dist[j],dist[cur]+p[cur][j]);
        }
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        scanf("%d",&v);
        p[0][i]=p[i][0]=v;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)scanf("%d",p[i][j]);
    }
    printf("%d",prim());
    return 0;
}