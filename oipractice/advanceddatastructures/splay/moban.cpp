//acw2437
#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=1e5+5;
int n,m,root,idx;
struct node
{
    int s[2],p,v,size;
    int rev;
    void init(int pp,int vv){
        p=pp,v=vv;
        size=1;
    }
}tr[N];
il void pushup(int x){
    tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+1;
}
il void pushdown(int x){
    if(tr[x].rev){
        swap(tr[x].s[0],tr[x].s[1]);
        tr[tr[x].s[0]].rev^=1;
        tr[tr[x].s[1]].rev^=1;
        tr[x].rev=0;
    }
}
il void rotate(int x){
    int y=tr[x].p,z=tr[y].p,k=tr[y].s[1]==x,l=tr[z].s[1]==y;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[y].s[k]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    tr[z].s[l]=x,tr[x].p=z;
    pushup(y),pushup(x);
}
il void splay(int x,int k){
    while(tr[x].p!=k){
        int y=tr[x].p,z=tr[y].p;
        if(z!=k){
            if((tr[y].s[0]==x)==(tr[z].s[0]==y))rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!k)root=x;
}
il void insert(int v){
    int u=root,p=0;
    while(u)p=u,u=tr[u].s[v>tr[u].v];
    u=++idx;
    if(p)tr[p].s[v>tr[p].v]=u;
    tr[u].init(p,v);
    splay(u,0);
}
il int find(int u,int x){
    pushdown(u);
    int ss=tr[tr[u].s[0]].size;
    if(x<=ss)return find(tr[u].s[0],x);
    if(x==ss+1)return u;
    return find(tr[u].s[1],x-ss-1);
}
il void print(int u){
    pushdown(u);
    if(tr[u].s[0])print(tr[u].s[0]);
    if(tr[u].v>=1&&tr[u].v<=n)printf("%d ",tr[u].v);
    if(tr[u].s[1])print(tr[u].s[1]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++)insert(i);
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        l=find(root,l),r=find(root,r+2);
        splay(l,0),splay(r,l);
        tr[tr[r].s[0]].rev^=1;
    }
    print(root);
    return 0;
}

