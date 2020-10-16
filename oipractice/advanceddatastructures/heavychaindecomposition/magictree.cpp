//p3833
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,M=N<<2;
int n,q,fa[N],dep[N];
int h[N],to[N],nex[N],idx;
int top[N],id[N],son[N],sz[N],cnt;
struct node{
    int l,r;
    ll sum,add;
}tr[M];
inline void add(int a,int b){to[idx]=b,nex[idx]=h[a],h[a]=idx++;}
void dfs1(int x,int d){
    dep[x]=d,sz[x]=1;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        dfs1(j,d+1);
        sz[x]+=sz[j];
        if(sz[j]>sz[son[x]])son[x]=j;
    }
}
void dfs2(int x,int t){
    top[x]=t,id[x]=++cnt;
    if(!son[x])return;
    dfs2(son[x],t);
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(j==son[x])continue;
        dfs2(j,j);
    }
}
void pushup(int u){tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;}
void pushdown(int u){
    if(tr[u].add){
        tr[u<<1].sum+=(tr[u<<1].r-tr[u<<1].l+1)*tr[u].add;
        tr[u<<1|1].sum+=(tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].add;
        tr[u<<1].add+=tr[u].add;
        tr[u<<1|1].add+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}
void update(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].add+=k;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
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
void update_path(int u,int v,int k){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    update(1,id[v],id[u],k);
}
ll query_tree(int u){return query(1,id[u],id[u]+sz[u]-1);}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a++,b++;
        add(a,b);
        fa[b]=a;
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        char op[2];
        int u,v,d;
        scanf("%s%d",op,&u);
        if(*op=='A'){
            scanf("%d%d",&v,&d);
            update_path(u+1,v+1,d);
        }
        else printf("%lld\n",query_tree(u+1));
    }
    return 0;
}