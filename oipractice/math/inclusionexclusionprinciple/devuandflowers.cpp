//acw214
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define il inline
const int N=22, mod=1e9+7;
LL a[N],m,n;
il LL qp(LL base,LL p){
    LL res=1;
    for(;p;p>>=1){
        if(p&1)res=res*base%mod;
        base=base*base%mod;
    }
    return res;
}
il LL pp(LL x){
    LL res=1,times=n-1;
    while(times--){
        res=x%mod*res%mod;
        x--;
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    LL res=0,down=1;
    for(int i=1;i<n;i++)down=down*i%mod;
    down=qp(down,mod-2);
    for(int i=0;i<1<<n;i++){
        int sign=1;
        LL up=m+n-1;
        for(int j=0;j<n;j++){
            if(i>>j&1){
                up-=a[j]+1;
                sign*=-1;
            }
        }
        if(up<n-1)continue;
        res=(res+pp(up)*down%mod*sign)%mod;
        //printf("%d %lld\n",i,res);
    }
    cout<<(res+mod)%mod;
    return 0;
}
