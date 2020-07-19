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
const int N=131075;
int t,n,ar[N],k;
char ss[N];
il int dfs(int l,int r,int ff){
    if(l==r){return ar[l]!=ff;}
    int mid=(l+r)>>1;
    int ans1=dfs(mid+1,r,ff+1);
    for(int i=l;i<=mid;i++){
        if(ar[i]!=ff)ans1++;
    }
    int ans2=dfs(l,mid,ff+1);
    for(int i=mid+1;i<=r;i++){
        if(ar[i]!=ff)ans2++;
    }
    return min(ans1,ans2);
}
int main(){
    t=read();
    while(t--){
        n=read();
        for(int i=0;i<=17;i++){
            if(1<<i==n){
                k=i;
                break;
                }
        }
        cin>>ss;
        for(int i=0;i<n;i++){
            ar[i]=ss[i]-'a';
            //cout<<ar[i]<<" ";
        }
        printf("%d\n",dfs(0,n-1,0));
    }
    return 0;
}