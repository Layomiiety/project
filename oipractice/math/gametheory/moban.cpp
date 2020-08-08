//acw1319
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int N=2005,M=6005;
int n,m,k,sg[N];
int h[N],to[M],nex[M],idx;
set <int> st[N];
inline void add(int a,int b){
    to[idx]=b,nex[idx]=h[a],h[a]=idx++;
}
inline int f(int x){
    if(sg[x]!=-1)return sg[x];
    for(int i=h[x];~i;i=nex[i]){
        st[x].insert(f(to[i]));
    }
    for(int i=0;i<n;i++){if(!st[x].count(i))return sg[x]=i;}
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    memset(h,-1,sizeof h);
    memset(sg,-1,sizeof sg);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    int res=0;
    while(k--){
        int x;
        scanf("%d",&x);
        res^=f(x);
    }
    if(res)puts("win");
    else puts("lose");
    return 0;
}