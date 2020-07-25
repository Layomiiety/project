//acw1277
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
int n,p,m;
LL a[N];
struct node{
    int l,r;
    LL add,mul,sum;
}tr[N<<2];
il void pushup(int u){
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}
il void pushdown(int u){
    node &lc=tr[u<<1],&rc=tr[u<<1|1],&r=tr[u];
    lc.sum=(lc.sum*r.mul+r.add*(lc.r-lc.l+1))%p;
    rc.sum=(rc.sum*r.mul+r.add*(rc.r-rc.l+1))%p;
    lc.add=(lc.add*r.mul+r.add)%p;
    rc.add=(rc.add*r.mul+r.add)%p;
    lc.mul=lc.mul*r.mul%p;
    rc.mul=rc.mul*r.mul%p;
    r.add=0,r.mul=1;
}
il void build(int u,int l,int r){
    tr[u]={l,r,0,1,0};
    if(l==r)tr[u].sum=a[l];
    else{
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
il void add(int u,int l,int r,LL c){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].add=(tr[u].add+c)%p;
        tr[u].sum=(tr[u].sum+c*(tr[u].r-tr[u].l+1))%p;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(mid>=l)add(u<<1,l,r,c);
    if(mid<r)add(u<<1|1,l,r,c);
    pushup(u);
}
il void mul(int u,int l,int r,LL c){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].mul=tr[u].mul*c%p;
        tr[u].add=tr[u].add*c%p;
        tr[u].sum=(tr[u].sum*c)%p;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(mid>=l)mul(u<<1,l,r,c);
    if(mid<r)mul(u<<1|1,l,r,c);
    pushup(u);
}
il LL query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    LL res=0;
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(mid>=l)res=query(u<<1,l,r);
    if(mid<r)res+=query(u<<1|1,l,r);
    return res%p;
}
int main(){
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    int op,t,g;
    LL c;
    while(m--){
        scanf("%d%d%d",&op,&t,&g);
        if(op==1){
            scanf("%lld",&c);
            mul(1,t,g,c);
        }
        else if(op==2){
            scanf("%lld",&c);
            add(1,t,g,c);
        }
        else {
            printf("%lld\n",query(1,t,g));
        }
    }
    return 0;
}