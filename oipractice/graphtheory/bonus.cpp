//acw1192
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
const int N=10005,M=20005;
int n,m,ans;
int h[N],nex[M],to[M],cnt=1;
int dist[N],d[N];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il bool topsort(){
    int q[N],tt=-1,hh;
    for(int i=1;i<=n;i++){
        if(!d[i])q[++tt]=i;
    }
    while(hh<=tt){
        int x=q[hh++];
        for(int i=h[x];i;i=nex[i]){
            int y=to[i];
            if(--d[y]==0){
                q[++tt]=y;
                dist[y]=dist[x]+1;
            }
        }
    }
    return tt==n-1;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(b,a);
        d[a]++;
    }
    for(int i=1;i<=n;i++)dist[i]=100;
    if(!topsort()){
        puts("Poor Xed");
        return 0;
        }
    for(int i=1;i<=n;i++){
        ans+=dist[i];
    }
    cout<<ans;
    return 0;
}