#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<cstdlib>
#include<vector> 
#define gc getchar()
#define ll long long
#define ull unsigned long long
#define file(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define I inline 
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n)) 
using namespace std;
const int N=4e5+5,mod=1e9+7,M=1<<15;
const double pi=acos(-1);
template<class o>I void qr(o &x)
{
    char c=gc;int f=1;x=0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc;}
    while(c>='0'&&c<='9'){x=x*10+(c^48);c=gc;}
    x*=f;
}
template<class o>I void qw(o x)
{
    if(x<0)x=-x,putchar('-');
    if(x/10)qw(x/10);
    putchar(x%10+48);
}
I int ksm(int a,int b=mod-2){int ans=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ans=1ll*ans*a%mod;return ans;}
struct cp
{
	double x,y;
	cp(double x=0.0,double y=0.0):x(x),y(y){}
	I cp operator +(const cp &a)const{return cp(x+a.x,y+a.y);}
	I cp operator -(const cp &a)const{return cp(x-a.x,y-a.y);}
	I cp operator *(const cp &a)const{return cp(x*a.x-y*a.y,x*a.y+y*a.x);}
	I cp operator /(const double &a)const{return cp(x/a,y/a);}
	I cp operator *(const double &a)const{return cp(x*a,y*a);}
	I cp operator +(const double &a)const{return cp(x+a,y+a);}
}w[N<<1];
cp Ii=cp(0,1);
int tr[N<<1],cnt;
I void rev(int n)
{
	if(cnt==n)return ;cnt=n;
	for(int i=0;i<n;i++)tr[i]=(tr[i>>1]>>1|((i&1)?n>>1:0));
}
I void Init(int n){for(int i=1;i<n;i<<=1){w[i]=cp(1,0);for(int j=1;j<i;j++)w[i+j]=(((j&31)==1)?cp(cos(pi*j/i),sin(pi*j/i)):w[i+j-1]*w[i+1]);}}
void dft(cp *g,bool op,int n)
{
	rev(n);
	static cp f[N<<1],t;
	for(int i=0;i<n;i++)f[i]=g[tr[i]];
	for(int p=2,l=1;p<=n;l=p,p<<=1)
		for(int i=0;i<n;i+=p)for(int j=0;j<l;j++)
			t=w[j|l]*f[i|j|l],f[i|j|l]=f[i|j]-t,f[i|j]=f[i|j]+t;
	if(op)for(int i=0;i<n;i++)g[i]=f[i]/n;
	else for(int i=0;i<n;i++)g[i]=f[i];
}
cp a0[N<<1],a1[N<<1],b0[N<<1],b1[N<<1],p[N<<1],q[N<<1];
void calc(cp *a,cp *b,int n)
{
	for(int i=0;i<n;i++)p[i]=a[i]+Ii*b[i];
	dft(p,0,n);q[0]=cp(p[0].x,-p[0].y);
	for(int i=1,j=n-1;i<n;i++,j--)q[i]=cp(p[j].x,-p[j].y);
	for(int i=0;i<n;i++)a[i]=(p[i]+q[i])*0.5,b[i]=(q[i]-p[i])*0.5*Ii;
}
ll num(double x){return x<0?(ll)(x-0.49)%mod:(ll)(x+0.49)%mod;}
void mtt(int *f,int *g,int m)
{
	int n=1;for(;n<(m<<1);n<<=1);
	for(int i=0;i<m;i++)a0[i]=cp(f[i]>>15,0),a1[i]=cp(f[i]&(M-1),0);
	for(int i=0;i<m;i++)b0[i]=cp(g[i]>>15,0),b1[i]=cp(g[i]&(M-1),0);
	for(int i=m;i<n;i++)a0[i]=a1[i]=b0[i]=b1[i]=cp(0,0);
	
	calc(a0,a1,n);calc(b0,b1,n);
	for(int i=0;i<n;i++)p[i]=a0[i]*b0[i]+Ii*a1[i]*b0[i],q[i]=a0[i]*b1[i]+Ii*a1[i]*b1[i];
	reverse(p+1,p+n),reverse(q+1,q+n);
	dft(p,1,n),dft(q,1,n);
	for(int i=0;i<m;i++)f[i]=(1ll*M*M%mod*num(p[i].x)%mod+1ll*M*num(p[i].y+q[i].x)%mod+num(q[i].y)+4ll*mod)%mod;
	for(int i=m;i<n;i++)f[i]=0;
}
int f[N],sav[N],g[N];//f[i]->f[i]/i!
int fac[N],ifac[N],k,dfac[N],pw[N];
void init(int m)
{	
	fac[0]=ifac[0]=pw[0]=1;for(int i=1;i<=m;i++)fac[i]=1ll*fac[i-1]*i%mod,pw[i]=pw[i-1]*2%mod;
	dfac[0]=1;for(int i=1;i<=m;i++)dfac[i]=1ll*dfac[i-1]*(k-i+1)%mod;
	ifac[m]=ksm(fac[m]);for(int i=m-1;i;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
void add(int m)
{
	for(int i=1;i<m;i++)f[i]=1ll*f[i]*pw[i]%mod*ifac[i]%mod;
	mtt(f,sav,m);
	for(int i=1;i<m;i++)f[i]=1ll*f[i]*fac[i]%mod;
}
void mul(int l,int m)
{
	for(int i=1;i<m;i++)f[i]=1ll*f[i]*ifac[i]%mod;cpy(g,f,m);
	for(int i=1;i<m;i++)f[i]=1ll*f[i]*ksm(pw[l],i)%mod;
	mtt(f,g,m);
	for(int i=1;i<m;i++)f[i]=1ll*f[i]*fac[i]%mod;
}
int C(int n,int m)
{
	if(n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll n;
int main()
{
	qr(n),qr(k);int t=n;
	if(n>k){puts("0");return 0;}
	init(k);
	int m=k+1;
	for(n=1;n<(m<<1);n<<=1);
	Init(n);for(int i=1;i<m;i++)f[i]=1,sav[i]=ifac[i];
	int lg=log2(t),j=1;
	for(int i=lg-1;~i;i--)
	{
		mul(j,m);j<<=1;
		if(t&(1<<i))
			add(m),j|=1;
	}
	ll ans=0;
	for(int i=1;i<=k;i++)
		ans=(ans+1ll*f[i]*C(k,i)%mod)%mod;
	qw(ans);puts("");
	return 0;
}