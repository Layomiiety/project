//acw241
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
const int N=2e5+5;
int y[N],c[N],gg[N],ss[N],n;
il int lowbit(int x){return x&-x;}
il void add(int x,int p){
    for(int i=p;i<=n;i+=lowbit(i))c[i]+=x;
}
il int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=c[i];
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&y[i]);
    for(int i=1;i<=n;i++){
        gg[i]=query(n)-query(y[i]);
        ss[i]=query(y[i]-1);
        add(1,y[i]);
    }
    memset(c,0,sizeof c);
    LL gres=0,sres=0;
    for(int i=n;i;i--){
        gres+=(LL)gg[i]*(query(n)-query(y[i]));
        sres+=(LL)ss[i]*(query(y[i]-1));
        add(1,y[i]);
    }
    printf("%lld %lld",gres,sres);
    return 0;
}