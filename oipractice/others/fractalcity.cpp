//acw 98
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll>pll;
inline pll get(ll n,ll x){
    if(!n)return {0,0};
    ll bl=1ll<<(2*n-2),len=1ll<<(n-1);
    pll p=get(n-1,x%bl);
    ll xx=p.first,yy=p.second;
    int m=x/bl;
    switch(m){
        case 0:
            return {yy,xx};
            break;
        case 1:
            return {xx+len,yy};
            break;
        case 2:
            return {xx+len,yy+len};
            break;
        case 3:
            return {len-1-yy,len*2-1-xx};
            break;
    }
    return {0,0};
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        ll m,a,b;
        scanf("%lld%lld%lld",&m,&a,&b);
        pll x=get(m,a-1);
        pll y=get(m,b-1);
        printf("%.0lf\n",10*sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second)));
    }
    return 0;
}