//acw244
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
const int N=1e5+5;
int n,m,a[N];
LL cp[N],cnp[N];
il int lowbit(int x){return x&-x;}
il void add(int ch,int p){
    for(int i=p;i<=n;i+=lowbit(i)){
        cp[i]+=(LL)ch;
        cnp[i]+=(LL)ch*p;
    }
}
il LL query(int p){
    LL res=0;
    for(int i=p;i;i-=lowbit(i)){
        res+=((p+1)*cp[i]-cnp[i]);
    }
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        add(a[i]-a[i-1],i);
    }
    for(int i=1;i<=m;i++){
        char op;
        scanf("%s",&op);
        if(op=='C'){
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            add(d,l);
            add(-d,r+1);
        }
        else {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(r)-query(l-1));
        }
    }
    return 0;
}