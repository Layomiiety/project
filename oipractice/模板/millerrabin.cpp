#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read() {
    char ch=getchar();
    register ll x=0;
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
typedef unsigned long long LL;
const int S = 8;

LL mult_mod(LL a, LL b, LL c) {
    a %= c;
    b %= c;
    LL ret = 0;
    LL tmp = a;
    while(b) {
        if(b & 1) {
            ret += tmp;
            if(ret > c)ret -= c;
        }
        tmp <<= 1;
        if(tmp > c)tmp -= c;
        b >>= 1;
    }
    return ret;
}

LL pow_mod(LL a, LL n, LL mod) {
    LL ret = 1;
    LL temp = a % mod;
    while(n) {
        if(n & 1)ret = mult_mod(ret, temp, mod);
        temp = mult_mod(temp, temp, mod);
        n >>= 1;
    }
    return ret;
}

bool check(LL a, LL n, LL x, LL t) {
    LL ret = pow_mod(a, x, n);
    LL last = ret;
    for(LL i = 1; i <= t; i++) {
        ret = mult_mod(ret, ret, n);
        if(ret == 1 && last != 1 && last != n - 1)return true;
        last = ret;
    }
    if(ret != 1)return true;
    else return false;
}

bool Miller_Rabin(LL n) {
    if( n < 2)return false;
    if( n == 2)return true;
    if( (n & 1) == 0)return false;
    LL x = n - 1;
    LL t = 0;
    while( (x & 1) == 0 ) {
        x >>= 1;
        t++;
    }
    srand(time(NULL));
    for(int i = 0; i < S; i++) {
        LL a  = rand() % (n - 1) + 1;
        if( check(a, n, x, t) )
            return false;
    }
    return true;
}
ll N,K;
int main(){
    scanf("%lld%lld",&N,&K);
    if(Miller_Rabin(K+1)&&K<<1>=N)cout<<1;
    else cout<<2;
    return 0;
}
