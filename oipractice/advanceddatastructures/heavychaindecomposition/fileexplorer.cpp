//acw918
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,id[N],w[N],cnt;
int h[N],to[N],nex[N],idx;
struct node{
    int l,r;
    int ch,sum;
}tr[N<<2];
int fa[N],top[N],sz[N],son[N],dep[N];
void add(int u,int v){to[idx]=v,nex[idx]=h[u],h[u]=idx++;}
void dfs1(int x,int d){
    dep[x]=d,sz[x]=1;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        dfs1(j,d+1);
        if(sz[j]>sz[son[x]])son[x]=j;
        sz[x]+=sz[j];
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
inline void pushup(int u){tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;}
inline void pushdown(int u){
    if(tr[u].ch!=-1){
        tr[u<<1].sum=tr[u].ch*(tr[u<<1].r-tr[u<<1].l+1);
        tr[u<<1|1].sum=tr[u].ch*(tr[u<<1|1].r-tr[u<<1|1].l+1);
        tr[u<<1].ch=tr[u<<1|1].ch=tr[u].ch;
        tr[u].ch=-1;
    }
}
void build(int u,int l,int r){
    tr[u]={l,r,-1,0};
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}
void update(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].ch=k;
        tr[u].sum=(tr[u].r-tr[u].l+1)*k;
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(mid>=l)update(u<<1,l,r,k);
    if(mid<r)update(u<<1|1,l,r,k);
    pushup(u);
    return;
}
void update_path(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,id[top[u]],id[u],1);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    update(1,id[v],id[u],1);
}
void update_tree(int u){update(1,id[u],id[u]+sz[u]-1,0);}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&fa[i]);
        fa[i]++;
        add(fa[i],i);
    }
    dfs1(1,0);
    dfs2(1,0);
    build(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        char op[20];
        int x;
        scanf("%s%d",op,&x);
        x++;
        if(!strcmp(op,"install")){
            int ps=tr[1].sum;
            update_path(1,x);
            printf("%d\n",tr[1].sum-ps);
        }
        else {
            int ps=tr[1].sum;
            update_tree(x);
            printf("%d\n",ps-tr[1].sum);
            }
    }
    return 0;
}
