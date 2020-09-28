#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int N=5e4+5;
int t,n,a[N],c[N],b[N],d[N],num;
il int lowbit(int x){return x&-x;}
il void add(int p){
    for(int i=p;i<=num;i+=lowbit(i))c[i]++;
}
il int query(int p){
    int res=0;
    for(int i=p;i;i-=lowbit(i))res+=c[i];
    return res;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(c,0,sizeof c);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        num=0;
        for(int i=1;i<=n;i++){
            if(b[i]==d[num])continue;
            d[++num]=b[i];
        }
        ull res=0;
        for(int i=n;i;i--){
            int x=lower_bound(d+1,d+num+1,a[i])-d;
            res+=(ull)query(a[i]-1);
            add(a[i]);
        }
        if(res>=(ull)(n-1)*n/2)puts("NO");
        else puts("YES");
    }
    return 0;
}