//acw257
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
const int N=105;
typedef pair<int,int> pii;
bool st[N][N],br[N][N];
pii match[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,t;
il bool find(int x,int y){
    for(int i=0;i<4;i++){
        int sx=x+dx[i],sy=y+dy[i];
        if(sx<1||sx>n||sy<1||sy>n||br[sx][sy]||st[sx][sy])continue;
        st[sx][sy]=true;
        if(!match[sx][sy].first||find(match[sx][sy].first,match[sx][sy].second)){
            match[sx][sy]={x,y};
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        br[a][b]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2&&!br[i][j]){
                memset(st,0,sizeof st);
                if(find(i,j))ans++;
            }
        }
    }
    cout<<ans;
}