//acw1063
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
    int s[2],imp,idx,p,size;
    void init(int im,int id,int pp){
        imp=im,idx=id,p=pp,size=1;
    }
}tr[N];
int n,m,fa[N],root[N],cnt;
int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
void pushup(int u){
    tr[u].size=tr[tr[u].s[0]].size+tr[tr[u].s[1]].size+1;
}
void rotate(int x){
    int y=tr[x].p,z=tr[y].p,yy=tr[y].s[1]==x,zz=tr[z].s[1]==y;
    tr[tr[x].s[yy^1]].p=y,tr[y].s[yy]=tr[x].s[yy^1];
    tr[x].s[yy^1]=y,tr[y].p=x;
    tr[z].s[zz]=x,tr[x].p=z;
    pushup(y),pushup(x);
}
void splay(int x,int k,int u){
    while(tr[x].p!=k){
        int y=tr[x].p,z=tr[y].p;
        if(z!=k){
            if((tr[y].s[0]==x)^(tr[z].s[0]==y))rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k)root[u]=x;
}
void insert(int im,int id,int u){
    int x=root[u],p=0;
    while(x){p=x,x=tr[x].s[im>tr[x].imp];}
    x=++cnt;
    if(p)tr[p].s[im>tr[p].imp]=x;
    tr[x].init(im,id,p);
    splay(x,0,u);
}
int query(int u,int k){
    if(tr[u].size<k)return -1;
    while(u){
        int x=tr[tr[u].s[0]].size;
        if(k==x+1)return tr[u].idx;
        if(k<=x)u=tr[u].s[0];
        else {
            k-=x+1;
            u=tr[u].s[1];
        }
    }
}
void dfs(int a,int b){
    if(tr[a].s[0])dfs(tr[a].s[0],b);
    if(tr[a].s[1])dfs(tr[a].s[0],b);
    insert(tr[a].imp,tr[a].idx,b);
}
void merge(int a,int b){
    if(tr[root[a]].size>tr[root[b]].size)swap(a,b);
    dfs(root[a],b);
    fa[a]=b;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        fa[i]=i;
        scanf("%d",&x);
        tr[i].init(x,i,0);
        root[i]=i;
    }
    cnt=n;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a=ff(a),b=ff(b);
        if(a!=b)merge(a,b);
    }
    scanf("%d",&m);
    while (m--){
        char op[2];
        int a,b;
        scanf("%s%d%d",op,&a,&b);
        if(*op=='B'){
            a=ff(a),b=ff(b);
            if(a!=b)merge(a,b);
        }
        else printf("%d\n",query(root[ff(a)],b));
    }
    return 0;
}