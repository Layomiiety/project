//acw255
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define il inline
#define LL long long
using namespace std;
const int N=1e5+5,M=1e4+5;
vector <int> un;
int n,m,a[N];
int root[N],idx;
struct node{
    int l,r,cnt;
}tr[N*4+N*17];
map <int,int> num;
il int build(int l,int r){
    int u=++idx;
    if(l==r)return u;
    int mid=l+r>>1;
    tr[u].l=build(l,mid);
    tr[u].r=build(mid+1,r);
    return u;
}
il int insert(int pre,int l,int r,int x){
    int cur=++idx;
    tr[cur]=tr[pre];
    if(l==r){
        tr[cur].cnt++;
        return cur;
    }
    int mid=l+r>>1;
    if(mid>=x)tr[cur].l=insert(tr[pre].l,l,mid,x);
    else tr[cur].r=insert(tr[pre].r,mid+1,r,x);
    tr[cur].cnt=tr[tr[cur].l].cnt+tr[tr[cur].r].cnt;
    return cur;
}
il int query(int ls,int rs,int k,int l,int r){
    if(l==r)return l;
    int cnt=tr[tr[rs].l].cnt-tr[tr[ls].l].cnt;
    int mid=l+r>>1;
    if(cnt>=k)return query(tr[ls].l,tr[rs].l,k,l,mid);
    return query(tr[ls].r,tr[rs].r,k-cnt,mid+1,r);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        un.push_back(a[i]);
        }
    sort(un.begin(),un.end());
    un.erase(unique(un.begin(),un.end()),un.end());
    for(int i=0;i<un.size();i++)num[un[i]]=i;
    root[0]=build(0,un.size()-1);
    for(int i=1;i<=n;i++){
        root[i]=insert(root[i-1],0,un.size()-1,num[a[i]]);
    }
    while(m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",un[query(root[l-1],root[r],k,0,un.size()-1)]);
    }
    return 0;
}