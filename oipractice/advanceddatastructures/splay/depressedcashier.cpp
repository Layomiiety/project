//acw950;
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=N<<1,inf=1e8;
int n,m;
struct node{
    int s[2],p,v,size;
    void init(int pp,int vv){
        p=pp,v=vv;
        size=1;
    }
}tr[N];
int delta,root,idx,tot;
inline void pushup(int x){tr[x].size=tr[tr[x].s[0]].size+tr[tr[x].s[1]].size+1;}
void rotate(int x){
    int y=tr[x].p,z=tr[y].p,w=tr[y].s[1]==x,e=tr[z].s[1]==y;
    tr[z].s[e]=x,tr[x].p=z;
    tr[y].s[w]=tr[x].s[w^1],tr[tr[y].s[w]].p=y;
    tr[x].s[w^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}
void splay(int x,int k){
    while(tr[x].p!=k){
        int y=tr[x].p,z=tr[y].p;
        if(z!=k){
            if((tr[y].s[1]==x)^(tr[z].s[1]==y))rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k)root=x;
}
void insert(int v){
    int u=root,p=0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u=++idx;
    if(p)tr[p].s[v>tr[p].v]=u;
    tr[u].init(p,v);
    splay(u,0);
}
int find(int v){
    int u=root,p=0;
    while(u){
        if(v<=tr[u].v)p=u;
        u=tr[u].s[v>tr[u].v];
    }
    return p;
}
int find(int k,int p){
    int ss=tr[tr[p].s[0]].size;
    if(ss+1==k)return tr[p].v;
    if(ss>=k)return find(k,tr[p].s[0]);
    return find(k-ss-1,tr[p].s[1]);
}
int main(){
    scanf("%d%d",&n,&m);
    insert(-inf),insert(inf);
    while(n--){
        char op[2];
        int k;
        scanf("%s%d",&op,&k);
        if(op[0]=='I'){
            k-=delta;
            if(k+delta>=m){
                insert(k);
                tot++;
            }
        }
        else if(op[0]=='A')delta+=k;
        else if(op[0]=='S'){
            delta-=k;
            int r=find(m-delta);
            splay(r,0),splay(1,r);
            tr[1].s[1]=0;
            pushup(1),pushup(r);
        }
        else {
            int x=tr[root].size;
            printf("%d\n",x-2>=k?find(x-k,root)+delta:-1);
        }
    }
    printf("%d",tot-tr[root].size+2);
    return 0;
}