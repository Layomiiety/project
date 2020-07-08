#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m;
int w[maxn],v[maxn],l[maxn],r[maxn],maxs=0,mins=1e6;
ll s,cur,curs,ans=inf,prew[maxn],preva[maxn];
bool judge(int W){
    memset(prew,0,sizeof(prew));
    memset(preva,0,sizeof(preva));
    for(int i=1;i<=n;i++){
        prew[i]=prew[i-1];
        preva[i]=preva[i-1];
        if (w[i]>=W)preva[i]+=v[i],prew[i]++;
    }
    curs=0;
    for(int i=1;i<=m;i++){
        curs+=(preva[r[i]]-preva[l[i]-1])*(prew[r[i]]-prew[l[i]-1]);
    }
    cur=abs(curs-s);
    return curs>s;
}
int main(){
    scanf("%d%d%lld",&n,&m,&s);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&w[i],&v[i]),mins=min(w[i],mins),maxs=max(maxs,w[i]);
    for(int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
    int lb=mins,rb=maxs+1,mid;
    while(lb<=rb){
        mid=(lb+rb)>>1;
        if(judge(mid))lb=mid+1;
        else rb=mid-1;
        ans=min(ans,cur);
    }
    printf("%lld",ans);
    return 0;
}
