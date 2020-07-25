//acw243
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
const int N=1e5+5;
int n,m;
LL a[N];
struct node{
    int l,r;
    LL sum,add;
}tr[N<<2];
il void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
il void pushdown(int u){
    node &root=tr[u],&lc=tr[u<<1],&rc=tr[u<<1|1];
    lc.add+=root.add;
    rc.add+=root.add;
    lc.sum+=root.add*(lc.r-lc.l+1);
    rc.sum+=root.add*(rc.r-rc.l+1);
    root.add=0;
}
il void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r){
        tr[u].sum=a[l];
        return;
        }
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
il void modify(int u,int l,int r,LL c){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].add+=c;
        tr[u].sum+=c*(tr[u].r-tr[u].l+1);
        return;
    }
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid)modify(u<<1,l,r,c);
    if(r>mid)modify(u<<1|1,l,r,c);
    pushup(u);
}
il LL query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    pushdown(u);
    LL res=0;
    int mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid)res+=query(u<<1,l,r);
    if(r>mid)res+=query(u<<1|1,l,r);
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    char op[2];
    int l,r,d;
    while(m--){
        scanf("%s%d%d",op,&l,&r);
        if(*op=='C'){
            scanf("%d",&d);
            modify(1,l,r,d);
        }
        else {
            printf("%lld\n",query(1,l,r));
        }
    }
    return 0;
}