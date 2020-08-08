//acw884
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=31;
int a[N][N],p[30];
int n,k;
inline int gauss(){
    int r=0;
    for(int c=0;c<n;c++){
        int t=r;
        for(int i=t;i<n;i++){
            if(a[i][c]){
                t=i;
                break;
            }
        }
        if(!a[t][c])continue;
        for(int i=c;i<=n;i++)swap(a[t][i],a[r][i]);
        for(int i=r+1;i<n;i++){
            if(!a[i][c])continue;
            for(int j=n;j>=c;j--)a[i][j]^=a[r][j];
        }
        r++;
    }
    if(r<n){
        for(int i=r;i<n;i++){
            if(a[i][n])return 0;
        }
        return n-r+1;
    }
    return 1;
}
int main(){
    scanf("%d",&k);
    p[0]=1;
    for(int i=1;i<29;i++)p[i]=2*p[i-1];
    while(k--){
        int x,y;
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i][n]);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            a[i][n]^=x;
            a[i][i]=1;
        }
        while(cin>>x>>y,x||y){
            a[y-1][x-1]=1;}
        int t=gauss();
        if(t)printf("%d\n",p[t-1]);
        else puts("Oh,it's impossible~!!");
    }
    return 0;
}
