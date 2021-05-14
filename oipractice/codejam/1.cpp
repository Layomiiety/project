#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5,M=2e5+5,inf=1e9+7;
#define ull unsigned long long
#define pii pair<int,int>
int n,m,Q,T;
int h[N],to[N<<1],nex[N<<1],lo[N<<1],idx;
ull d[N<<1],ans[M];
bool vis[N];
struct seg{
    int l,r;
    ull v=0;
}tr[M<<2];
vector<pii> q[N];
inline ull gcd(ull a,ull b){
    if(a<b)swap(a,b);
    return b==0?a:gcd(b,a%b);
}
inline void add(int x,int y,int a,int b){
    to[idx]=y,nex[idx]=h[x],lo[idx]=a,d[idx]=b,h[x]=idx++;
}
inline void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}
inline void pushup(int u){
    tr[u].v=gcd(tr[u<<1].v,tr[u<<1|1].v);
}
inline ull query(int x,int y,int u){
    if(tr[u].l>=x&&tr[u].r<=y)return tr[u].v;
    int mid=tr[u].l+tr[u].r>>1;
    ull ls=0,rs=0;
    if(mid>=x)ls=query(x,y,u<<1);
    if(mid<y)rs=query(x,y,u<<1|1);
    //printf("qu%d %d %d %d %d %d\n",x,y,ls,rs,tr[u].l,tr[u].r);
    if(ls&&rs)return gcd(ls,rs);
    return ls+rs;
}
inline void update(int p,int u,ull v){
    if(tr[u].l==tr[u].r){
        tr[u].v=v;
        return;
        }
    int mid=tr[u].l+tr[u].r>>1;
    if(mid>=p)update(p,u<<1,v);
    else update(p,u<<1|1,v);
    pushup(u);
}
inline void dfs(int p){
    vis[p]=true;
    for(auto x:q[p]){
        int id=x.first,w=x.second;
        ans[id]=query(1,w,1);
        //printf("ans%d %d\n",id,ans[id]);
    }
    for(int i=h[p];~i;i=nex[i]){
        int j=to[i];
        if(vis[j])continue;
        update(lo[i],1,d[i]);
        dfs(j);
        update(lo[i],1,0);
    }
}
inline void solve(int ca){
    scanf("%d%d",&n,&Q);
    memset(h,-1,sizeof h);
    memset(vis,0,sizeof vis);
    idx=0,m=0;
    for(int i=1;i<n;i++){
        int x,y,a;
        ull b;
        scanf("%d%d%d%lld",&x,&y,&a,&b);
        add(x,y,a,b);
        add(y,x,a,b);
        m=max(m,a);
    }
    for(int i=1;i<=Q;i++){
        int c,w;
        scanf("%d%d",&c,&w);
        q[c].push_back(make_pair(i,w));
    }
    dfs(1);
    printf("Case #%d: ",ca);
    for(int i=1;i<=Q;i++)printf("%lld ",ans[i]);
    puts("");
}
int main(){
    scanf("%d",&T);
    build(1,1,2e5);
    for(int i=1;i<=T;i++){
        solve(i);
    }
}