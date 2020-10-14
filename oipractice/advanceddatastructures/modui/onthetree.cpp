//acw2534
#include <bits/stdc++.h>
using namespace std;
const int N=8e4+5,M=1e5+5;
int n,m,len;
int ans[M],w[N],seq[N],fi[N],la[N],po=0,cnt[N];
vector<int> ma;
struct query{
    int id,l,r,anc;
}q[N];
int h[N],nex[N],to[N],idx=0,que[N],hh=0,tt=0,fa[N][16],dep[N];
bool st[N];
inline int get(int x){return x/len;}
inline void adde(int x,int y){to[idx]=y,nex[idx]=h[x],h[x]=idx++;}
void add(int x,int &res){
    st[x]^=1;
    if(st[x]){
        if(!cnt[w[x]])res++;
        cnt[w[x]]++;
        }
    else {
        cnt[w[x]]--;
        if(!cnt[w[x]])res--;
    }
}
bool cmp(query a,query b){return get(a.l)==get(b.l)?a.r<b.r:a.l<b.l;}
void dfs(int x,int fa){
    seq[++po]=x;
    fi[x]=po;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        if(j==fa)continue;
        dfs(j,x);
    }
    seq[++po]=x;
    la[x]=po;
}
void bfs(){
    que[tt++]=1;
    dep[1]=1,dep[0]=0;
    while(hh<tt){
        int x=que[hh++];
        for(int i=h[x];~i;i=nex[i]){
            int j=to[i];
            if(dep[j])continue;
            fa[j][0]=x;
            dep[j]=dep[x]+1;
            for(int k=1;k<=15;k++)fa[j][k]=fa[fa[j][k-1]][k-1];
            que[tt++]=j;
        }
    }
}
int lca(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    for(int i=15;i>=0;i--){
        if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
    }
    if(x==y)return x;
    for(int i=15;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        ma.push_back(w[i]);
        }
    len=sqrt(n*2);
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        adde(x,y);
        adde(y,x);
    }
    dfs(1,-1);
    bfs();
    sort(ma.begin(),ma.end());
    ma.erase(unique(ma.begin(),ma.end()),ma.end());
    for(int i=1;i<=n;i++)w[i]=lower_bound(ma.begin(),ma.end(),w[i])-ma.begin();
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(fi[u]>fi[v])swap(u,v);
        int anc=lca(u,v);
        if(anc==u)q[i]={i,fi[u],fi[v]};
        else q[i]={i,la[u],fi[v],anc};
    }
    sort(q,q+m,cmp);
    for(int i=0,j=1,k=0,res=0;k<m;k++){
        int l=q[k].l,r=q[k].r,id=q[k].id,anc=q[k].anc;
        while(i>r)add(seq[i--],res);
        while(i<r)add(seq[++i],res);
        while(j>l)add(seq[--j],res);
        while(j<l)add(seq[j++],res);
        if(anc)add(anc,res);
        ans[id]=res;
        if(anc)add(anc,res);
        }
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
    return 0;
}