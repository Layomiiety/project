#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read() {
    char ch=getchar();
    register int x=0;
    int f=1;
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
int T, ans,dx[8]={-1,-2,-2,-1,1,2,2,1},dy[8]={-2,-1,1,2,2,1,-1,-2};
char gg[5][5],st[5][6]={{"11111"},{"01111"},{"00*11"},{"00001"},{"00000"}};
il int astar(){
    int res=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(gg[i][j]!=st[i][j])res++;
        }
    }
    return res;
}
il void solve(int x,int y,int step){
        if(!astar()){ans=min(ans,step);return;}
        if(astar()+step>15)return;
        for(int i=0;i<8;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>4||yy<0||yy>4)continue;
            swap(gg[xx][yy],gg[x][y]);
            solve(xx,yy,step+1);
            swap(gg[xx][yy],gg[x][y]);
        }
        return;
}
int main(){
    T=read();
    while(T--){
        for(int i=0;i<5;i++)scanf("%s",gg[i]);
        int x,y;
        ans=16;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(gg[i][j]=='*'){
                    x=i,y=j;
                    break;
                }
            }
        }
        solve(x,y,0);
        if(ans<16)printf("%d\n",ans);
        else puts("-1");
    }
}