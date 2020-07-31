//acw253
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
const int N=1e6+5,inf=1e9;
struct treap{
    int l,r,key,val;
    int size,cnt;
}tr[N];
int idx,n,root;
il int get_node(int p){
    tr[++idx].key=p;
    tr[idx].val=rand();
    tr[idx].size=1;
    tr[idx].cnt=1;
    return idx;
} 
il void pushup(int p){
    tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+tr[p].cnt;
}
il void zig(int &p){
    int q=tr[p].l;
    tr[p].l=tr[q].r,tr[q].r=p,p=q;
    pushup(tr[p].r),pushup(p);
}
il void zag(int &p){
    int q=tr[p].r;
    tr[p].r=tr[q].l,tr[q].l=p,p=q;
    pushup(tr[p].l),pushup(p);
}
il void build(){
    root=get_node(-inf);
    tr[root].r=get_node(inf);
    pushup(root);
    if(tr[tr[root].r].val>tr[root].val)zag(root);
}
il void insert(int &p,int key){
    if(!p)p=get_node(key);
    else if(tr[p].key==key)tr[p].cnt++;
    else if(tr[p].key>key){
        insert(tr[p].l,key);
        if(tr[tr[p].l].val>tr[p].val)zig(p);
    }
    else {
        insert(tr[p].r,key);
        if(tr[tr[p].r].val>tr[p].val)zag(p);
    }
    pushup(p);
}
il void delet(int &p,int key){
    if(!p)return;
    if(tr[p].key==key){
        if(tr[p].cnt>1)tr[p].cnt--;
        else if(tr[p].l||tr[p].r){
            if(!tr[p].r||tr[tr[p].l].val>tr[tr[p].r].val){
                zig(p);
                delet(tr[p].r,key);
            }
            else {
                zag(p);
                delet(tr[p].l,key);
            }
        }
        else p=0;
    }
    else if(tr[p].key>key) {
        delet(tr[p].l,key);
    }
    else delet(tr[p].r,key);
    pushup(p);
}
il int get_rank_by_key(int p,int key){
    if(!p)return inf;
    if(tr[p].key==key)return tr[tr[p].l].size+1;
    if(tr[p].key>key)return get_rank_by_key(tr[p].l,key);
    else return tr[tr[p].l].size+tr[p].cnt+get_rank_by_key(tr[p].r,key);
}
il int get_key_by_rank(int p,int rank){
    if(!p)return -inf;
    if(tr[tr[p].l].size>=rank)return get_key_by_rank(tr[p].l,rank);
    if(tr[tr[p].l].size+tr[p].cnt>=rank)return tr[p].key;
    return get_key_by_rank(tr[p].r,rank-tr[p].cnt-tr[tr[p].l].size);
}
il int get_max_small(int p, int key){
    if(!p)return -inf;
    if(tr[p].key>=key)return get_max_small(tr[p].l,key);
    else return max(tr[p].key,get_max_small(tr[p].r,key));
}
il int get_min_large(int p,int key){
    if(!p)return inf;
    if(tr[p].key<=key)return get_min_large(tr[p].r,key);
    else return min(tr[p].key,get_min_large(tr[p].l,key));
}
int main(){
    scanf("%d",&n);
    int op,x;
    build();
    for(int i=0;i<n;i++){
        scanf("%d%d",&op,&x);
        switch(op){
            case(1):
                insert(root,x);
                break;
            case(2):
                delet(root,x);
                break;
            case(3):
                printf("%d\n",get_rank_by_key(root,x)-1);
                break;
            case(4):
                printf("%d\n",get_key_by_rank(root,x+1));
                break;
            case(5):
                printf("%d\n",get_max_small(root,x));
                break;
            case(6):
                printf("%d\n",get_min_large(root,x));
        }
    }
    return 0;
}