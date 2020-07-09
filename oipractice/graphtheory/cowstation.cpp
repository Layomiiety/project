#include <bits/stdc++.h>
using namespace std;
const int N=205;
int k,n=0,m,t,s,e,dis[N][N],a,b,l,res[N][N],temp[N][N];
map <int,int>idx;
inline void floyd(int x[][N],int y[][N]){
    memset(temp,0x3f,sizeof temp);
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=min(temp[i][j],x[i][k]+y[k][j]);
            }
        }
    }
    memcpy(x,temp,sizeof temp);
    return;
}
void qmul(){
    memset(res,0x3f,sizeof res);
    for(int i=0;i<n;i++)res[i][i]=0;
    while(k){
        if(k&1)floyd(res,dis);
        floyd(dis,dis);
        k>>=1;
    }
    return;
}
int main(){
    cin>>k>>m>>s>>e;
    memset(dis,0x3f,sizeof dis);
    while(m--){
        scanf("%d%d%d",&l,&a,&b);
        if(!idx.count(a))idx[a]=n++;
        if(!idx.count(b))idx[b]=n++;
        a=idx[a],b=idx[b];
        dis[a][b]=dis[b][a]=min(dis[a][b],l);
    }
    s=idx[s],e=idx[e];
    qmul();
    printf("%d",res[s][e]);
    return 0;
}