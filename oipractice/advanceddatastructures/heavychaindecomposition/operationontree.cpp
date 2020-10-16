//haoi2015
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,M=N<<1;
int n,m;
int h[N],to[M],nex[M],idx;
int w[N],nw[N],id[N],top[N],fa[N],son[N],sz[N],dep[N],cnt;
void add(int a,int b){to[idx]=b,nex[idx]=h[a],h[a]=idx++;}
struct node{
    int l,r;
    ll add,sum;
}tr[M<<1];
void dfs1(int x,int p,int d){
    dep[x]=d,sz[x]=1,fa[x]=p;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(j==p)continue;
        dfs1(j,x,d+1);
        sz[x]+=sz[j];
        if(sz[j]>sz[son[x]])son[x]=j;
    }
}
void dfs2(int x,int t){
    id[x]=++cnt,nw[cnt]=w[x],top[x]=t;
    if(!son[x])return;
    dfs2(son[x],t);
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(j==son[x]||j==fa[x])continue;
        dfs2(j,j);
    }
}
void pushup(int u){tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;}
void pushdown(int u){
    if(tr[u].add){
        tr[u<<1].sum+=tr[u].add*(tr[u<<1].r-tr[u<<1].l+1);
        tr[u<<1|1].sum+=tr[u].add*(tr[u<<1|1].r-tr[u<<1|1].l+1);
        tr[u<<1].add+=tr[u].add;
        tr[u<<1|1].add+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r){
    tr[u]={l,r,0};
    if(l==r){
        tr[u].sum=nw[l];
        return;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
    return;
}
void update(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].sum+=(ll)k*(tr[u].r-tr[u].l+1);
        tr[u].add+=k;
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(mid>=l)update(u<<1,l,r,k);
    if(mid<r)update(u<<1|1,l,r,k);
    pushup(u);
    return;
}
ll query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    ll res=0;
    int mid=tr[u].l+tr[u].r>>1;
    pushdown(u);
    if(mid>=l)res+=query(u<<1,l,r);
    if(mid<r)res+=query(u<<1|1,l,r);
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs1(1,0,0);
    dfs2(1,1);
    build(1,1,n);
    while(m--){
        int op,a,x;
        scanf("%d%d",&op,&x);
        if(op==1){
            scanf("%d",&a);
            update(1,id[x],id[x],a);
        }
        else if(op==2){
            scanf("%d",&a);
            update(1,id[x],id[x]+sz[x]-1,a);
        }
        else {
            ll res=0;
            while(top[x]!=1){
                res+=query(1,id[top[x]],id[x]);
                x=fa[top[x]];
            }
            res+=query(1,1,id[x]);
            printf("%lld\n",res);
        }
    }
    return 0;
}