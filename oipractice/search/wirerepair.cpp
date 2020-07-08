#include <bits/stdc++.h>
using namespace std;
#define il inline
#define re register
typedef pair<int,int> pii;
int T,r,c,dist[505][505];
bool vis[505][505];
char ma[505][505];
deque <pii> q;
il int bfs(){
    int dx[4]={-1,-1,1,1},dy[4]={-1,1,-1,1},ix[4]={-1,-1,0,0},iy[4]={-1,0,-1,0};
    string ss="\\//\\";
    q.push_front({0,0});
    while(!q.empty()){
        pii h=q.front();
        q.pop_front();
        if(vis[h.first][h.second])continue;
        vis[h.first][h.second]=true;
        //printf("%d %d %d\n",h.first,h.second,dist[h.first][h.second]);
        for(int i=0;i<4;i++){
            int xx=dx[i]+h.first,yy=dy[i]+h.second,xi=ix[i]+h.first,yi=iy[i]+h.second;
            if(xx<0||xx>r||yy<0||yy>c)continue;
            if(ma[xi][yi]==ss[i]){
                dist[xx][yy]=min(dist[h.first][h.second],dist[xx][yy]);
                q.push_front({xx,yy});
                }
            else {
                dist[xx][yy]=min(dist[h.first][h.second]+1,dist[xx][yy]);
                q.push_back({xx,yy});
            }
        }
    }
    return dist[r][c];
}
int main(){
    scanf("%d%d",&r,&c);
    for(re int i=0;i<r;i++)scanf("%s",ma[i]);
    if((r-c)&1){printf("NO SOLUTION\n");return 0;}
    memset(dist,0x3f,sizeof dist);
    dist[0][0]=0;
    printf("%d\n",bfs());
    return 0;
}
