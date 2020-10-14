#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,M=N<<2,E=N<<1;
int n,m,w[N],nw[N],id[N],cnt;
int h[N],to[E],nex[E],idx;
struct node{
    int l,r;
    ll add,sum;
}tr[M];
int top[N],sz[N],son[N],fa[N],dep[N];
inline void add(int u,int v){to[idx]=v,nex[idx]=h[u],h[u]=idx++;}
void dfs1(int x,int p,int d){
    sz[x]=1,dep[x]=d,fa[x]=p;
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
        node &root=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
        l.add+=root.add;
        l.sum+=(ll)root.add*(l.r-l.l+1);
        r.add+=root.add;
        r.sum+=(ll)root.add*(r.r-r.l+1);
        root.add=0;
    }
}
void build(int u,int l,int r){
    tr[u]={l,r,0,nw[r]};
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
void update(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].add+=k;
        tr[u].sum+=(ll)k*(tr[u].r-tr[u].l+1);
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(mid>=l)update(u<<1,l,r,k);
    if(mid<r)update(u<<1|1,l,r,k);
    pushup(u);
}
ll query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    ll res=0;
    if(mid>=l)res+=query(u<<1,l,r);
    if(mid<r)res+=query(u<<1|1,l,r);
    return res;
}
void update_path(int u,int v,int k){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    update(1,id[v],id[u],k);
}
void update_tree(int u,int k){update(1,id[u],id[u]+sz[u]-1,k);}
ll query_path(int u,int v){
    ll res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        res+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    res+=query(1,id[v],id[u]);
    return res;
}
ll query_tree(int u){return query(1,id[u],id[u]+sz[u]-1);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,-1,0);
    dfs2(1,1);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int op,u,v,k;
        scanf("%d%d",&op,&u);
        if(op==1){
            scanf("%d%d",&v,&k);
            update_path(u,v,k);
        }
        else if(op==2){
            scanf("%d",&k);
            update_tree(u,k);
        }
        else if(op==3){
            scanf("%d",&v);
            printf("%lld\n",query_path(u,v));
        }
        else printf("%lld\n",query_tree(u));
    }
    return 0;
}