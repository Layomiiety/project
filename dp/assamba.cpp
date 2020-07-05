#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,p,mid,l,r,curd,maxd=-inf,mind=inf,ans;
int ex[4]={1,0,-1,0},ey[4]={0,1,0,-1},d[1005][1005],vis[1005][1005];
bool judge(int dam){
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    vis[0][0]=1;
    while(!q.empty()){
        int xc=q.front().first;
        int yc=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=xc+ex[i];
            int ny=yc+ey[i];
            if(nx<0||nx>n-1||ny<0||ny>m-1||vis[nx][ny]==1||d[nx][ny]>dam)continue;
            if (nx==n-1) return true;
            vis[nx][ny]=1;
            q.push(make_pair(nx,ny));
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)scanf("%d",&curd),d[i][j]=curd,mind=min(curd,mind),maxd=max(curd,maxd);
    }
    l=mind,r=maxd;
    while(l<=r){
        mid=l+r>>1;
        memset(vis,0,sizeof(vis));
        if (judge(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}