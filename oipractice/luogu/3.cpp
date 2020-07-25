#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1e6+5;
int a[N],b[N],c[N],n,ma[N],mb[N],mc[N];
LL ans=0;
bool can=true;
il void ms(int l,int r){
    if(l==r)return;
    int mid=l+r >>1;
    ms(l,mid),ms(mid+1,r);
    int i=l,j=mid+1,k=1;
    while(i<=mid&&j<=r){
        if(b[i]<=b[j])c[k++]=b[i++];
        else {
            c[k++]=b[j++];
            ans+=(LL)(mid-i+1);
        }
    }
    while(i<=mid)c[k++]=b[i++];
    while(j<=r)c[k++]=b[j++];
    for(int i=l,k=1;i<=r;i++,k++)b[i]=c[k];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        ma[a[i]]=x;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        mb[b[i]]=x;
    }
    int cc=0;
    for(int i=1;i<=n;i++){
        if(ma[a[i]]!=mb[a[i]]){
            can=false;
            break;}
        else {
            mc[a[i]]=++cc;
        }
    }
    if(!can)printf("dldsgay!!1");
    else {
        for(int i=1;i<=n;i++){
            b[i]=mc[b[i]];
            //cout<<b[i]<<" ";
        }
        ms(1,n);
        printf("%lld",ans);
    }
    return 0;
}