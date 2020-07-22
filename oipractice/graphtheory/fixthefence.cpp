//acw1124
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
const int N=505;
int g[N][N],f,ans[1050],cc;
int d[N];
il void dfs(int x){
    for(int i=1;i<=500;i++){
        if(g[x][i]){
            g[x][i]--,g[i][x]--;
            dfs(i);
        }
    }
    ans[++cc]=x;
}
int main(){
    cin>>f;
    for(int i=0;i<f;i++){
        int a,b;
        cin>>a>>b;
        g[a][b]++,g[b][a]++;
        d[a]++,d[b]++;
    }
    int st=1;
    while(!d[st])st++;
    for(int i=st;i<=500;i++){
        if(d[i]&1){st=i;break;}
    }
    dfs(st);
    for(int i=f+1;i;i--)printf("%d\n",ans[i]);
    return 0;
}