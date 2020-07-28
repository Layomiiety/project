//acw256
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define il inline
#define LL long long
using namespace std;
const int N=6e5+5,M=N*25;
int tr[M][2],root[N],maxid[M],idx,pre[N],rc;
int n,m;
il void insert(int x,int cur,int pr,int id){
    for(int i=23;i>=0;i--){
        int t=x>>i&1;
        tr[cur][t]=++idx;
        maxid[tr[cur][t]]=id;
        if(pr){
            tr[cur][t^1]=tr[pr][t^1];
        }
        pr=tr[pr][t];
        cur=tr[cur][t];
    }
}
il int query(int l,int r,int x){
    x^=pre[rc];
    int p=root[r-1];
    l-=1;
    for(int i=23;i>=0;i--){
        int t=x>>i&1;
        if(maxid[tr[p][t^1]]>=l){
            p=tr[p][t^1];
        }
        else p=tr[p][t];
    }
    return pre[maxid[p]]^x;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(maxid,-1,sizeof maxid);
    for(int i=1;i<=n;i++){
        scanf("%d",&pre[i]);
        root[++rc]=++idx;
        pre[rc]^=pre[rc-1];
        insert(pre[rc],root[rc],root[rc-1],rc);
    }
    char op[2];
    int l,r,x;
    while(m--){
        scanf("%s",op);
        if(op[0]=='A'){
            root[++rc]=++idx;
            scanf("%d",&pre[rc]);
            pre[rc]^=pre[rc-1];
            insert(pre[rc],root[rc],root[rc-1],rc);
        }
        else {
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(l,r,x));
        }
    }
    return 0;
}