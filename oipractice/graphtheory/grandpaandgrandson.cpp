//acw1172
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int N=40005,M=N+N;
int h[N],nex[M],to[M],cnt=1,depth[N],f[N][16],n,m,a,b,root,bb;
inline void add(int x,int y){to[cnt]=y,nex[cnt]=h[x],h[x]=cnt++;}
void bfs(){
    memset(depth,0x3f,sizeof depth);
    depth[0]=0,depth[root]=1;
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int hh=q.front();
        q.pop();
        for(int i=h[hh];i;i=nex[i]){
            int j=to[i];
            if(depth[j]>depth[hh]+1){
                depth[j]=depth[hh]+1;
                q.push(j);
                f[j][0]=hh;
                for(int k=1;k<=bb;k++){
                    f[j][k]=f[f[j][k-1]][k-1];
                }
            }
        }
    }
}
inline int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    for(int i=bb;i>=0;i--){
        if(depth[f[x][i]]>=depth[y])x=f[x][i];
        //printf("%d %d %d\n",i,x,y);
    }
    if(x==y)return x;
    for(int i=bb;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int main(){
    scanf("%d",&n);
    bb=log2(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(b==-1)root=a;
        else {add(a,b),add(b,a);}
    }
    bfs();
    scanf("%d",&m);
    while(m--){
        scanf("%d%d",&a,&b);
        int ff=lca(a,b);
        if(ff==a)puts("1");
        else if(ff==b)puts("2");
        else puts("0");
    }
    return 0;
}