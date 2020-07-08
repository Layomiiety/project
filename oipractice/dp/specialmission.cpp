#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read(){
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
inline void write(ull a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
const int maxn=1e6+5;
int n,a,b,c,hh=0,tt=0,q[maxn];
ll x[maxn],f[maxn];
il ll gety(int k){
    return f[k]+a*x[k]*x[k]-b*x[k];
}
il double slope(int p,int q){
    return (double)(gety(q)-gety(p))/(x[q]-x[p]); 
}
int main(){
    n=read();
    a=read(),b=read(),c=read();
    memset(x,0,sizeof x);
    memset(f,0,sizeof f);
    for(re int i=1;i<=n;i++)x[i]=x[i-1]+read();
    for(re int i=1;i<=n;i++){
        while(hh<tt&&(double)2*a*x[i]<=slope(q[hh],q[hh+1]))hh++;
        f[i]=f[q[hh]]+a*x[q[hh]]*x[q[hh]]-(2*x[i]*a+b)*x[q[hh]]+b*x[i]+c+a*x[i]*x[i];
        while(hh<tt&&slope(i,q[tt])>slope(q[tt],q[tt-1]))tt--;
        q[++tt]=i;
    }
    write(f[n]);
    return 0;
}