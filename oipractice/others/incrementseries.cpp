#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline ll read() {
    char ch=getchar();
    register ll x=0;
    int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=3e4+5;
int n,dis[maxn],cnt,sm[maxn],bi[maxn];
ull num[maxn],di[maxn],ans,sum[maxn<<2];
il int lc(int k){return k<<1;}
il int rc(int k){return k<<1|1;}
il void update(int l,int r,int k,int p){
    if(l==r&&l==p){
        sum[k]++;
        return;
    }
    int mid=(l+r)>>1;
    if(p>mid)update(mid+1,r,rc(k),p);
    else update(l,mid,lc(k),p);
    sum[k]=sum[lc(k)]+sum[rc(k)];
    return;
}
il ull query(int l,int r,int k,int lb,int rb){
    if(l>=lb&&r<=rb)return sum[k];
    int mid=(l+r)>>1;
    ull res=0;
    if(rb>mid)res+=query(mid+1,r,rc(k),lb,rb);
    if(lb<=mid)res+=query(l,mid,lc(k),lb,rb);
    //printf("%d %d %d %d %d\n",l,r,sum[k],lb,rb);
    return res;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)num[i]=di[i]=read();
    sort(di+1,di+n+1);
    cnt=unique(di+1,di+n+1)-di-1;
    for(int i=1;i<=n;i++)dis[i]=lower_bound(di+1,di+cnt+1,num[i])-di;
    for(int i=1;i<=n;i++){
        if(dis[i]>1)sm[i]=query(1,cnt,1,1,dis[i]-1);
        update(1,cnt,1,dis[i]);
    }
    //printf("%d",sm[n]);
    memset(sum,0,sizeof(sum));
    for(int i=n;i>0;i--){
        if(dis[i]<cnt)bi[i]=query(1,cnt,1,dis[i]+1,cnt);
        update(1,cnt,1,dis[i]);
    }
    for(int i=1;i<=n;i++){
        ans+=(ull)sm[i]*bi[i];
    }
    printf("%lld",ans);
    return 0;
}
