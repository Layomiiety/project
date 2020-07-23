//acw1252
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
const int N=10005;
int n,m,w,fa[N],c[N],v[N],tv[N],tc[N];
il int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
int main(){
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++){
        fa[i]=i;
        scanf("%d%d",&c[i],&v[i]);
    }
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a=ff(a),b=ff(b);
        if(a!=b)fa[a]=b;
    }
    for(int i=1;i<=n;i++){
        tv[ff(i)]+=v[i];
        tc[fa[i]]+=c[i];
    }
    int dp[N];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        if(!tv[i])continue;
        for(int j=w;j>=tc[i];j--)dp[j]=max(dp[j],dp[j-tc[i]]+tv[i]);
    }
    printf("%d",dp[w]);
    return 0;
}