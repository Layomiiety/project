//acw1145
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=505;
double g[N][N];
int n,k;
pii vil[N];
double prim(){
    bool st[N];
    double dist[N];
    priority_queue <double> q;
    for(int i=1;i<=n;i++)dist[i]=0x7fffffff;
    dist[1]=0;
    for(int i=1;i<=n;i++){
        int cur=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(cur==-1||dist[j]<dist[cur]))cur=j;
        }
        st[cur]=true;
        q.push(dist[cur]);
        //printf("%d %.2lf\n",cur,dist[cur]);
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],g[cur][j]);
        }
    }
    while(k--&&!q.empty()){
        double cd=q.top();
        q.pop();
    }
    return q.top();
}
int main(){
    scanf("%d%d",&n,&k);
    k--;
    for(int i=1;i<=n;i++)scanf("%d%d",&vil[i].first,&vil[i].second);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)g[i][j]=g[j][i]=sqrt((vil[i].first-vil[j].first)*(vil[i].first-vil[j].first)+(vil[i].second-vil[j].second)*(vil[i].second-vil[j].second));
        }
    printf("%.2lf",prim());
    return 0;
}
