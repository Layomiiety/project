#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int x,y,t;
};
queue<node>q;
ll dp[105][105][17];
int r1,r2,c1,c2,n,m,tot,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
node a,na;
string cur[105];
inline int read() {
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
    n=read(),m=read(),tot=read();
    for(int i=1;i<=n;i++)cin>>cur[i];
    r1=read(),c1=read(),r2=read(),c2=read();
    q.push(node{r1,c1,0});
    dp[r1][c1][0]=1;
    while(!q.empty()){
        a=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            na.x=a.x+dx[i],na.y=a.y+dy[i],na.t=a.t+1;
            if(na.x<1||na.x>n||na.y<1||na.y>m||na.t>tot||cur[na.x][na.y-1]=='*')continue;
            if(dp[na.x][na.y][na.t]!=0){
                dp[na.x][na.y][na.t]+=dp[a.x][a.y][a.t];
                continue;
            }
            dp[na.x][na.y][na.t]+=dp[a.x][a.y][a.t];
            q.push(na);
        }
    }
    printf("%lld",dp[r2][c2][tot]);
    return 0;
}