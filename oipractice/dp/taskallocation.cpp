#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
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
inline void write(ull a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
const int maxn=3e5+5;
int n,s,hh=1,tt=1,q[maxn];
ll t[maxn],c[maxn],f[maxn];
int main(){
    n=read(),s=read();
    f[0]=t[0]=c[0]=0;
    for(re int i=1;i<=n;i++){
        t[i]=read();
        c[i]=read();
        t[i]+=t[i-1];
        c[i]+=c[i-1];
    }
    for(re int i=1;i<=n;i++){
        int l=hh,r=tt,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(f[mid+1]-f[mid]<=(c[mid+1]-c[mid])*(s+t[i]))l=mid+1;
            else r=mid-1;
        }
        f[i]=f[q[r]]-c[q[r]]*(s+t[i])+t[i]*c[i]+s*c[n];
        while(hh<tt&&(f[i]-f[q[tt]])*(c[q[tt]]-c[q[tt-1]])<=(f[q[tt]]-f[q[tt-1]])*(c[i]-c[q[tt]]))tt--;
        q[++tt]=i;
    }
    printf("%lld\n",f[n]);
    return 0;
}