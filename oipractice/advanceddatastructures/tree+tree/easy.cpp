//acw2488
#include <bits/stdc++.h>
using namespace std;
const int N=5e4+5,M=N<<2,inf=1e9;
int n,m,w[N];
struct node
{
    int l,r;
    multiset <int> s;
}tr[M];
void build(int u,int l,int r){
    tr[u]={l,r};
    //tr[u].s.insert(-inf),tr[u].s.insert(inf);
    for(int i=l;i<=r;i++)tr[u].s.insert(w[i]);
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
}
inline void mod(int u,int p,int x){
    tr[u].s.erase(tr[u].s.find(w[p]));
    tr[u].s.insert(x);
    if(tr[u].l==tr[u].r)return;
    int mid=tr[u].l+tr[u].r>>1;
    if(mid>=p)mod(u<<1,p,x);
    else mod(u<<1|1,p,x);
}
inline int query(int u,int l,int r,int x){
    int ul=tr[u].l,ur=tr[u].r;
    if(ul>=l&&ur<=r){
        auto pos=tr[u].s.lower_bound(x);
        return pos==tr[u].s.begin()?0:*(--pos);
    }
    int mid=ul+ur>>1,res=0;
    if(mid>=l)res=max(res,query(u<<1,l,r,x));
    if(mid<r)res=max(res,query(u<<1|1,l,r,x));
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    build(1,1,n);
    while(m--){
        int op,a,b,x;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&a,&x);
            mod(1,a,x);
            w[a]=x;
        }
        else {
            scanf("%d%d%d",&a,&b,&x);
            printf("%d\n",query(1,a,b,x));
        }
    }
    return 0;
}


