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
int ori[N],n,h[N],a[N],c[N];
il int lowbit(int x){return x&-x;}
il void add(int x,int ch){
    for(int i=x;i<=n;i+=lowbit(i))c[i]+=ch;
}
il int query(int x){
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=c[i];
    return res;
}
il int ff(int x){
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        int cur=query(mid);
        //printf("%d %d\n",mid,cur);
        if(cur<x)l=mid+1;
        else r=mid;
        }
    return r;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)add(i,1);
    for(int i=2;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i;i--){
        h[i]=ff(a[i]+1);
        add(h[i],-1);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",h[i]);
    }
    return 0;
}