#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
il ll read() {
    char ch=getchar();
    register ll x=0;
    int f=1;
    while(ch<'0'||ch>'9')if(ch=='-'){f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
il void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int N=1e6+500;
ull n,f1[N],f2[N];
ull solve(long long n)
{
    int sqn=sqrt(n);long long s=0;
    long long i=1;
    for(;i<=sqn;i++)s+=n/i,f1[i]=s;
    for(long long lt;i<=n;i=lt+1)
    {
        lt=n/(n/i),s+=(lt-i+1)*(n/i);
        if(lt<=sqn)f1[lt]=s;
        else f2[n/lt]=s;
    }
    ull ans=0;
    for(ull x=1;x<=n;x<<=1)
        for(ull y=1;y*x<=n;y*=5)
            if(n/(x*y)<=sqn)ans+=f1[n/(x*y)];
            else ans+=f2[x*y];
    return ans;
}
int main()
{
    n=read();
    write(solve(n)-solve(n>>1)-solve(n/5)+solve(n/10));
}