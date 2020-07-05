#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int maxn=100005;
int n,m,sum[maxn<<2],tag[maxn<<2],val[maxn],o,x,y,z;
il int lc(int k){return k<<1;}
il int rc(int k){return k<<1|1;}
il void build(int k,int l,int r){
    if(l==r){sum[k]=val[l];return;}
    int mid=(l+r)>>1;
    build(lc(k),l,mid);
    build(rc(k),mid+1,r);
    sum[k]=sum[lc(k)]+sum[rc(k)];
    return;
}
il void addtag(int k,int l,int r,int v){
    tag[k]+=v;
    sum[k]+=(r-l+1)*v;
    return;
}
il void push_down(int k,int l,int r){
    int mid=(l+r)>>1;
    addtag(lc(k),l,mid,tag[k]);
    addtag(rc(k),mid+1,r,tag[k]);
    tag[k]=0;
    return;
}
il void update(int nl,int nr,int l,int r,int k,int v){
    if(nl<=l&&nr>=r){
        sum[k]+=v*(r-l+1);
        tag[k]+=v;
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,lc(k),v);
    if(nr>mid)update(nl,nr,mid+1,r,rc(k),v);
    sum[k]=sum[lc(k)]+sum[rc(k)];
    return;
}
il ll query(int ql,int qr,int l,int r,int k){
    ll ans=0;
    if(ql<=l&&qr>=r)return (ll)sum[k];
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid)ans+=query(ql,qr,l,mid,lc(k));
    if(qr>mid)ans+=query(ql,qr,mid+1,r,rc(k));
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("%d",&o);
        if(o==1){
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,1,n,1,z);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(x,y,1,n,1));
        }
    }
    return 0;
}