//acw242
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
#define il inline 
#define LL long long
const int N=5e5+5;
int c[N],n,m,ori[N];
il int lowbit(int x){return x&-x;}
il void add(int cc,int p){
    for(int i=p;i<=n;i+=lowbit(i))c[i]+=cc;
}
il int query(int p){
    int res=0;
    for(int i=p;i;i-=lowbit(i))res+=c[i];
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&ori[i]);
    }
    for(int i=1;i<=n;i++)c[i]=ori[i]-ori[i-lowbit(i)];
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            add(d,l);
            add(-d,r+1);
        }
        else {
            int x;
            scanf("%d",&x);
            printf("%d\n",query(x));
        }
    }
    return 0;
}
