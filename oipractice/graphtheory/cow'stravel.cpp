#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=155;
const double inf=0x7fffffff;
int n;
char c[N][N];
pii pas[N];
double dist[N][N],res1=0,res2=inf,maxd[N];
inline double fidd(pii x,pii y){
    return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&pas[i].first,&pas[i].second);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>c[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j){
                if(c[i][j]=='1')dist[i][j]=fidd(pas[i],pas[j]);
                else dist[i][j]=inf;
                }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dist[j][k]=min(dist[j][k],dist[i][j]+dist[i][k]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dist[i][j]!=inf){
                res1=max(res1,dist[i][j]);
                maxd[i]=max(maxd[i],dist[i][j]);
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dist[i][j]==inf){
                res2=min(res2,fidd(pas[i],pas[j])+maxd[i]+maxd[j]);
            }
    printf("%lf",max(res1,res2));
    return 0;
}