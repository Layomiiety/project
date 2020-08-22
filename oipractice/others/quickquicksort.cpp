//acw107
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=500005;
int a[N],b[N],f[N],n;
il int lowbit(int x){return x&-x;}
il void add(int p){
    for(int i=p;i<=n;i+=lowbit(i))f[i]++;
}
il ll query(int p){
    ll res=0;
    for(int i=p;i;i-=lowbit(i))res+=(ll)f[i];
    return res;
}
int main(){
    while(cin>>n,n){
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
            }
        sort(b+1,b+n+1,greater<int>());
        ll res=0;
        for(int i=1;i<=n;i++){
            int x=lower_bound(b+1,b+n+1,a[i],greater<int>())-b;
            res+=query(x);
            //printf("%d %d\n",x,res);
            add(x);
        }
        printf("%lld\n",res);
    }
    return 0;
}