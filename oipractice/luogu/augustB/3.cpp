#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define LL long long
typedef pair<int,int>pii;
const int N=3e5+5;
int n,a[N],ma[N],cnt[N];
inline int read() {
    char ch=getchar();
    register int x=0;
    int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline pii find(int rb,int val){
    int lb=1;
    while(lb<rb){
        int mid=lb+rb>>1,x=ma[mid];
        if(x==val){
            lb=mid;
            break;
        }
        if(x<val)lb=mid+1;
        else rb=mid;
    }
    if(ma[lb]==val)return {cnt[lb],lb};
    return {0,0};
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    int cn=0;
    for(int i=1;i<=n;i++){
        if(a[i]>ma[cn]){
            ma[++cn]=a[i];
            cnt[cn]=1;
            }
        else cnt[cn]++;
    }
    LL ans=0;
    for(int i=cn;i>0;i--){
        if(!cnt[i])continue;
        LL res=ma[i]*(LL)cnt[i],base=ma[i];
        int idx=i;
        while(!(base%3)){
            base=base/3*2;
            pii x=find(idx,base);
            if(!x.first)break;
            idx=x.second;
            res+=base*(LL)x.first;
            cnt[idx]=0;
        }
        //printf("%lld %lld\n",ans,res);
        ans=max(ans,res);
    }
    printf("%lld",ans);
    return 0;
}