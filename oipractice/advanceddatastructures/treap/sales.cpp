//acw265
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
const int N=40000,inf=1e9;
int n,idx,root;
struct treap{
    int l,r,key,val;
}tr[N];
il int get_node(int key){
    tr[++idx].key=key;
    tr[idx].val=rand();
    return idx;
}
il void zig(int &p){
    int q=tr[p].l;
    tr[p].l=tr[q].r,tr[q].r=p,p=q;
}
il void zag(int &p){
    int q=tr[p].r;
    tr[p].r=tr[q].l,tr[q].l=p,p=q;
}
il void insert(int &p,int key){
    if(!p)p=get_node(key);
    else if(tr[p].key==key)return;
    else if(tr[p].key>key){
        insert(tr[p].l,key);
        if(tr[tr[p].l].val>tr[p].val)zig(p);
    }
    else {
        insert(tr[p].r,key);
        if(tr[tr[p].r].val>tr[p].val)zag(p);
    }
}
il int get_prev(int p,int key){
    if(!p)return inf;
    if(tr[p].key==key)return 0;
    if(tr[p].key<key)return min(key-tr[p].key,get_prev(tr[p].r,key));
    else return get_prev(tr[p].l,key);
}
il int get_next(int p,int key){
    if(!p)return inf;
    if(tr[p].key==key)return 0;
    if(tr[p].key>key)return min(tr[p].key-key,get_next(tr[p].l,key));
    else return get_next(tr[p].r,key);
}
int main(){
    scanf("%d",&n);
    int x;
    LL ans=0;
    scanf("%d",&x);
    ans+=(LL)x;
    root=get_node(x);
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        ans+=(LL)min(get_prev(root,x),get_next(root,x));
        insert(root,x);
    }
    printf("%lld",ans);
    return 0;
}