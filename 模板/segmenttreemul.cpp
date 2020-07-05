#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int maxn=1e5+5;
int val[maxn],adt[maxn<<2],mult[maxn<<2],n,m,mo,o,x,y,z;
ll sum[maxn<<2];
il int lc(int k){return k<<1;}
il int rc(int k){return k<<1|1;}
il void build(int l,int r,int k){
    mult[k]=1;
    if(l==r){sum[k]=val[l]%mo;return;}
    int mid=(l+r)>>1;
    build(l,mid,lc(k));
    build(mid+1,r,rc(k));
    sum[k]=(sum[lc(k)]+sum[rc(k)])%mo;
    return;
}
il void push_down(int l,int r,int k){
    int mid=(l+r)>>1;
    mult[lc(k)]=mult[lc(k)]*mult[k]%mo;
    mult[rc(k)]=mult[rc(k)]*mult[k]%mo;
    adt[lc(k)]=adt[lc(k)]*mult[k]%mo;
    adt[rc(k)]=adt[rc(k)]*mult[k]%mo;
    sum[lc(k)]=sum[lc(k)]*mult[k]%mo;
    sum[rc(k)]=sum[rc(k)]*mult[k]%mo;
    mult[k]=1;
    adt[lc(k)]=(adt[lc(k)]+adt[k])%mo;
    adt[rc(k)]=(adt[rc(k)]+adt[k])%mo;
    sum[lc(k)]=(sum[lc(k)]+(mid-l+1)*adt[k])%mo;
    sum[rc(k)]=(sum[rc(k)]+(r-mid)*adt[k])%mo;
    adt[k]=0;
    return;
}
il void upadd(int nl,int nr,int l,int r,int k,int v){
    if(nl<=l&&nr>=r){
        adt[k]=(adt[k]+v)%mo;
        sum[k]=(sum[k]+(r-l+1)*v)%mo;
        return;
        }
    if(mult[k]!=1||adt[k])push_down(l,r,k);
    int mid=(l+r)>>1;
    if(nl<=mid)upadd(nl,nr,l,mid,lc(k),v);
    if(nr>mid)upadd(nl,nr,mid+1,r,rc(k),v);
    sum[k]=(sum[lc(k)]+sum[rc(k)])%mo;
    return;
}
il void upmul(int nl,int nr,int l,int r,int k,int v){
    if(nl<=l&&nr>=r){
        mult[k]=mult[k]*v%mo;
        adt[k]=adt[k]*v%mo;
        sum[k]=sum[k]*v%mo;
        return;
    }
    if(mult[k]!=1||adt[k])push_down(l,r,k);
    int mid=(l+r)>>1;
    if(nl<=mid)upmul(nl,nr,l,mid,lc(k),v);
    if(nr>mid)upmul(nl,nr,mid+1,r,rc(k),v);
    sum[k]=(sum[lc(k)]+sum[rc(k)])%mo;
    return;
}
il ll query(int ql,int qr,int l,int r,int k){
    if(ql<=l&&qr>=r)return sum[k];
    if((mult[k]!=1)||adt[k])push_down(l,r,k);
    ll ans=0;
    int mid=(l+r)>>1;
    if(ql<=mid)ans=(ans+query(ql,qr,l,mid,lc(k)))%mo;
    if(qr>mid)ans=(ans+query(ql,qr,mid+1,r,rc(k)))%mo;
    return ans;
}
int main(){
    scanf("%d%d",&n,&mo);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    build(1,n,1);
    scanf("%d",&m);
    while(m--){
        scanf("%d",&o);
        switch(o){
            case 1:{
                scanf("%d%d%d",&x,&y,&z);
                upmul(x,y,1,n,1,z);
                break;
            }
            case 2:{
                scanf("%d%d%d",&x,&y,&z);
                upadd(x,y,1,n,1,z);
                break;
            }
            case 3:{
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(x,y,1,n,1));
                break;
            }
        }
    }
    return 0;
}