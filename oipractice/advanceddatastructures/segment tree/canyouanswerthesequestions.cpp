//acw245
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
const int N=5e5+5;
int n,m,a[N];
struct node{
    int l,r;
    int tmax,lmax,rmax,sum;
}tr[N<<2];
il void pushup(node &u,node &lc,node &rc){
    u.sum=lc.sum+rc.sum;
    u.rmax=max(rc.rmax,rc.sum+lc.rmax);
    u.lmax=max(lc.lmax,lc.sum+rc.lmax);
    u.tmax=max(max(lc.tmax,rc.tmax),lc.rmax+rc.lmax);
}
il void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
il void build(int u,int l,int r){
    if(l==r){
        tr[u]={l,r,a[l],a[l],a[l],a[l]};
        return;
    }
    tr[u]={l,r};
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
il void modify(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x){
        tr[u].tmax=v,tr[u].lmax=v,tr[u].rmax=v,tr[u].sum=v;
    }
    else {
        int mid=(tr[u].l+tr[u].r)>>1;
        if(mid>=x)modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}
il node query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
    int mid=(tr[u].l+tr[u].r)>>1;
    if(mid>=r)return query(u<<1,l,r);
    if(mid<l)return query(u<<1|1,l,r);
    node res,lc=query(u<<1,l,r),rc=query(u<<1|1,l,r);
    pushup(res,lc,rc);
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        int k,x,y;
        scanf("%d%d%d",&k,&x,&y);
        if(k==1){
            if(x>y)swap(x,y);
            printf("%d\n",query(1,x,y).tmax);
        }
        else modify(1,x,y);
    }
    return 0;
}