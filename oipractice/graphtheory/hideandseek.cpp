//acw379
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
const int N=205,M=30005;
bool g[N][N],st[N];
int n,m;
int match[N];
il bool find(int x){
    for(int i=1;i<=n;i++){
        if(!g[x][i]||st[i])continue;
        st[i]=true;
        if(!match[i]||find(match[i])){
            match[i]=x;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a][b]=true;
        }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                g[i][j]|=g[i][k]&g[k][j];
            }
        }
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        memset(st,0,sizeof st);
        if(find(i))ans--;
    }
    printf("%d",ans);
    return 0;
}