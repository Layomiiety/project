//acw1184
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
const int N=1e5+5,M=N<<2;
int n,m,type;
int h[N],nex[M],to[M],cnt;
bool vis[M];
int din[N],dout[N],ans[M>>1],cc;
il void add(int a,int b){nex[cnt]=h[a],to[cnt]=b,h[a]=cnt++;}
il void dfs(int x){
    for(int &i=h[x];~i;){
        if(vis[i]){
            i=nex[i];
            continue;
        }
        vis[i]=true;
        if(type==1)vis[i^1]=true;
        int j=to[i];
        int t;
        if(type==1){
            t=(i/2)+1;
            if(i&1)t=-t;
        }
        else t=i+1;
        i=nex[i];
        dfs(j);
        ans[++cc]=t;
    }
}
int main(){
    cin>>type;
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        if(type==1)add(b,a);
        din[b]++,dout[a]++;
    }
    if(type==1){
        for(int i=1;i<=n;i++){
            if(din[i]+dout[i] & 1){
                puts("NO");
                return 0;
            }
        }
    }
    else {
        for(int i=1;i<=n;i++){
            if(din[i]!=dout[i]){
                puts("NO");
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(~h[i]){
            dfs(i);
            break;
        }
    }
    if(cc<m){
        puts("NO");
        return 0;
        }
    puts("YES");
    for(int i=m;i;i--)printf("%d ",ans[i]);
    return 0;
}