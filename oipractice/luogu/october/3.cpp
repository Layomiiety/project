#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define il inline
const int N=25,M=5e5+5;
int n,m,ma[N];
bool st[N][N],st2[N];
int vis[M];
struct query{
    int l,r,val;
}q[M];
bool find(int x){
    for(int i=0;i<=n;i++){
        if(!st[x][i]&&!st2[i]){
            st2[i]=true;
            if(ma[i]==-1||find(ma[i])){
                ma[i]=x;
                return true;
            }
        }
    }
    return false;
}
bool judge(){
    memset(ma,-1,sizeof ma);
    for(int i=1;i<=m;i++){
        int a=q[i].l,b=q[i].r,c=q[i].val;
        if(c>n){
            if(c==n+1){
                if(a==0&&b==n)continue;
                else return false;
            }
            return false;
        }
        for(int j=a;j<=b;j++)st[c][j]=1;
        for(int j=0;j<c;j++){
            for(int k=0;k<a;k++)st[j][k]=1;
            for(int k=b+1;k<=n;k++)st[j][k]=1;
        }
    }
    for(int i=0;i<=n;i++){
        memset(st2,0,sizeof st2);
        if(!find(i))return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    int mc=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        q[i]={a,b,c};
        vis[a]++,vis[b+1]--;
        mc=max(mc,c);
    }
    if(mc){
        if(judge()){
            for(int i=0;i<=n;i++)printf("%d ",ma[i]);
        }
        else puts("-1");
    }
    else {
        int mm[M];
        memset(mm,-1,sizeof mm);
        bool flag=true;
        for(int i=0;i<=n;i++){
            vis[i]+=vis[i-1];
            if(!vis[i]){
                mm[i]=0;
                flag=false;
                break;
            }
        }
        if(flag)puts("-1");
        else {
            for(int i=0,j=1;i<=n;i++){
                if(mm[i]==0)printf("0 ");
                else printf("%d ",j++);
            }
        }
    }
    return 0;
}