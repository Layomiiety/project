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
const int maxn=2e5+5;
int t;
ll m,l,r,a,b,c;
il void cc(){
    ll lb=max(m-r+l,(ll)1),rb=m+r-l;
    for(a=l;a<=r;a++){
        ll s1=(rb/a)*a;
        if(s1>=lb){
            if(s1>m){
                b=l,c=l+s1-m;
                return;
            }
            else {
                //cout<<s1<<" ";
                c=l,b=m-s1+l;
                return;
            }
        }
    }
}
int main(){
    t=read();
    while(t--){
        scanf("%lld%lld%lld",&l,&r,&m);
        cc();
        printf("%lld %lld %lld\n",a,b,c);
    }
    return 0;
    }