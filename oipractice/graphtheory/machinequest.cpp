//acw376
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
const int N=105,M=2005;
int g[N][N],st[N],n,m,k;
int match[N];
il bool find(int x){
    for(int i=1;i<m;i++){
        if(st[i]||!g[x][i])continue;
        st[i]=true;
        if(!match[i]||find(match[i])){
            match[i]=x;
            return true;
        }
    }
    return false;
}
int main(){
    while(cin>>n,n){
        cin>>m>>k;
        memset(match,0,sizeof match);
        memset(g,0,sizeof g);
        while(k--){
            int i,a,b;
            cin>>i>>a>>b;
            g[a][b]=true;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            memset(st,0,sizeof st);
            if(find(i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}