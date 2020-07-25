//acw1275
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
const int N=2e5+5;
int m,p,n=0,last=0;
struct segt{
    int l,r,v;
}tr[N<<2];
il void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r)return;
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}
il void pushup(int x){
    tr[x].v=max(tr[x<<1].v,tr[x<<1|1].v);
}
il int  query(int u,int l,int r){
    int ul=tr[u].l,ur=tr[u].r;
    if(ul>=l&&ur<=r)return tr[u].v;
    int res=0;
    int mid=(ul+ur)>>1;
    if(l<=mid)res=query(u<<1,l,r);
    if(r>mid)res=max(res,query(u<<1|1,l,r));
    return res;
}
il void modify(int u,int x,int v){
    int ul=tr[u].l,ur=tr[u].r;
    if(x==ul&&x==ur){
        tr[u].v=v;
        return;
    }
    int mid=(ul+ur)>>1;
    if(x<=mid)modify(u<<1,x,v);
    else modify(u<<1|1,x,v);
    pushup(u);
}
int main(){
    scanf("%d%d",&m,&p);
    build(1,1,m);
    for(int i=1;i<=m;i++){
        char op[2];
        int nn;
        scanf("%s%d",op,&nn);
        if(*op=='Q'){
            last=query(1,n-nn+1,n);
            printf("%d\n",last);
        }
        else {
            modify(1,++n,(nn+last)%p);
        }
    }
    return 0;
}