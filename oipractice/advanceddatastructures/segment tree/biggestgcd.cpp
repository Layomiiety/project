//acw246
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
int n,m;
LL a[N];
struct node{
    int l,r;
    LL g,sum;
}tr[N<<2];
il LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
il void pushup(node &u,node &lc,node &rc){
    u.g=gcd(lc.g,rc.g);
    u.sum=lc.sum+rc.sum;
}
il void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
il void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r){
        tr[u].g=tr[u].sum=a[l]-a[l-1];
        return;
    }
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
il void modify(int u,int x,LL c){
    if(x==tr[u].l&&x==tr[u].r){
        tr[u].g+=c;
        tr[u].sum=tr[u].g;
        return;
    }
    int mid=(tr[u].l+tr[u].r)>>1;
    if(mid>=x)modify(u<<1,x,c);
    else modify(u<<1|1,x,c);
    pushup(u);
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
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    while(m--){
        char op[2];
        int l,r;
        scanf("%s%d%d",op,&l,&r);
        if(*op=='C'){
            LL d;
            scanf("%lld",&d);
            modify(1,l,d);
            if(r>=n)continue;
            modify(1,r+1,-d);
        }
        else {
            printf("%lld\n",(LL)abs(gcd(query(1,l+1,r).g,query(1,1,l).sum)));
        }
    }
    return 0;
}