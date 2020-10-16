//cf915e
#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
int n,m;
vector <int>ma;
struct query{
    int l,r,k;
}q[N>>1];
struct node{
    int l,r;
    int ch,sum;
}tr[N<<2];
inline void pushup(int u){tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;}
inline int get(int x){return lower_bound(ma.begin(),ma.end(),x)-ma.begin();}
inline void pushdown(int u){
    if(tr[u].ch!=-1){
        tr[u<<1].sum=(ma[tr[u<<1].r]-ma[tr[u<<1].l])*tr[u].ch;
        tr[u<<1|1].sum=(ma[tr[u<<1|1].r]-ma[tr[u<<1|1].l])*tr[u].ch;
        tr[u<<1].ch=tr[u<<1|1].ch=tr[u].ch;
        tr[u].ch=-1;
    }
}
void build(int u,int l,int r){
    tr[u]={l,r,-1,ma[r]-ma[l]};
    //printf("%d %d %d %d %d %d\n",u,l,r,ma[l],ma[r],tr[u].sum);
    if(l==r-1)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid,r);
}
void update(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].ch=k;
        tr[u].sum=(ma[tr[u].r]-ma[tr[u].l])*k;
        //printf("update%d %d %d\n",tr[u].l,tr[u].r,tr[u].sum);
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(mid>l)update(u<<1,l,r,k);
    if(mid<r)update(u<<1|1,l,r,k);
    pushup(u);
    //printf("update%d %d %d\n",tr[u].l,tr[u].r,tr[u].sum);
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        q[i]={l,r+1,k-1};
        ma.push_back(l),ma.push_back(r+1);
        }
    ma.push_back(0),ma.push_back(n+1),ma.push_back(1);
    sort(ma.begin(),ma.end());
    ma.erase(unique(ma.begin(),ma.end()),ma.end());
    build(1,1,get(n+1));
    //exit(0);
    for(int i=0;i<m;i++){
        int l=get(q[i].l),r=get(q[i].r),k=q[i].k;
        //printf("%d %d\n",l,r);
        update(1,l,r,k);
        printf("%d\n",tr[1].sum);
    }
    return 0;
}