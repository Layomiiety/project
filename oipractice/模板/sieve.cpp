#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
inline void write(ll x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
const int maxn=8e6;
int cnt,pr[maxn>>1],phi[maxn],mu[maxn],smu[maxn];
ll sphi[maxn];
inline void presieve(){
    phi[1]=mu[1]=sphi[1]=smu[1]=1;
    for(register int i=2;i<maxn;i++){
        if(!phi[i]) phi[i]=i-1,mu[i]=-1,pr[cnt++]=i;
        for(register int j=0;j<cnt&&pr[j]*i<maxn;j++){
            if(!(i%pr[j])){
                phi[pr[j]*i]=phi[i]*pr[j];
                mu[pr[j]*i]=0;
                break;
                }
            phi[pr[j]*i]=phi[i]*(pr[j]-1);
            mu[pr[j]*i]=-mu[i];
        }
        sphi[i]=sphi[i-1]+phi[i],smu[i]=smu[i-1]+mu[i];
    }
    return;
}
unordered_map<ull, ll>sph;
unordered_map<ull, int>sm;
inline ll gsphi(ull n){
    if(n<maxn)return sphi[n];
    if(sph[n])return sph[n];
    ll ans=(ll)n*(n+1)/2;
    for(register unsigned int l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(ll)(r-l+1)*gsphi(n/l);
    }
    return sph[n]=ans;
}
inline int gsmu(ull n){
    if(n<maxn)return smu[n];
    if(sm[n])return sm[n];
    int ans=1;
    for(ull l=2,r;l<=n;l=r+1){
        r=n/(n/l);
        ans-=(r-l+1)*gsmu(n/l);
    }
    return sm[n]=ans;
}
int t;
ull n;
int main(){
    presieve();
    t=read();
    while(t--){
        n=read();
        write(gsphi(n));
        printf(" %d\n",gsmu(n));
    } 
    return 0;
}