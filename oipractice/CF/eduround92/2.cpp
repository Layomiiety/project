#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
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
const int N=1e5+5;
int T,n,k,z;
int a[N],ans,s[N],adj[N],ma[N];
il void solve(){
    for(int i=1;i<=n;i++)a[i]=read();
    memset(ma,0,sizeof ma);
    for(int i=1;i<=k+1;i++){
        s[i]=s[i-1]+a[i];
        if(i!=k+1){
            adj[i]=a[i]+a[i+1];
            ma[i]=max(ma[i-1],adj[i]);
            }
        }
    ans=s[k+1];
    for(int i=1;i<=min(z,(k+1)/2);i++){
        ans=max(ans,s[k+1-2*i]+ma[k-2*i]*i);
    }
    printf("%d\n",ans);
    return;
}
int main(){
    T=read();
    while(T--){
        ans=0;
        n=read(),k=read(),z=read();
        solve();
    }
    return 0;
}