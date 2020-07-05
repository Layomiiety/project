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
il ll qmul(ll i,ll j,ll mod){
    ll ans=0;
    while(j){
        if(j&1)ans=(ans+i)%mod;
        i=(i<<1)%mod;
        j>>=1;
    }
    return ans;
}
il ll qpow(ll i,ll j,ll mod){
    ll ans=1;
    while(j){
        if(j&1)ans=qmul(ans,i,mod);
        j>>=1;
        i=qmul(i,i,mod);
    }
    return ans;
}
const int maxn=4e6;
ull phi[maxn],pr[maxn>>1],p,n,in2,in6;  
il void presieve(){
	int cnt=0;
	phi[1]=1;
	for(re int i=2;i<maxn;i++){
		if(!phi[i])pr[cnt++]=i,phi[i]=i-1;
		for(re int j=0;j<cnt&&pr[j]*i<maxn;j++){
			if(i%pr[j])phi[i*pr[j]]=qmul(phi[i],pr[j]-1,p);
			else {phi[i*pr[j]]=qmul(phi[i],pr[j],p);break;}
		}
	}
	for(re int i=1;i<maxn;i++)phi[i]=(qmul(phi[i],i*i%p,p)+phi[i-1])%p;
	return;
}
il ull ss(ull x){
	ull ans;
	ans=qmul(x,x+1,p);
	ans=qmul(ans,2*x+1,p);
	ans=qmul(ans,in6,p);
	return ans;
}
il ull cs(ull x){
	ull ans=qmul(x,x+1,p);
	ans=qmul(ans,in2,p);
	ans=qpow(ans,2,p);
	return ans;
}
unordered_map<ull,ull>sp;
il ll solve(ull x){
	if(x<maxn)return phi[x];
	if(sp[x])return sp[x];
	ll ans=cs(x);
	for(re ull l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		ans-=qmul(ss(r)-ss(l-1)+p,solve(x/l),p);
		ans%=p;
	}
	return sp[x]=ans;
}
int main(){
	p=read(),n=read();
	in2=qpow(2,p-2,p),in6=qpow(6,p-2,p);
	presieve();
	ull s=0;
	for(ull l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		s+=qmul(solve(r)-solve(l-1)+p,cs(n/l),p);
		s%=p;
	}
	write(s);
	return 0;
}