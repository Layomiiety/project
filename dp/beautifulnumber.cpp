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
ull l,r,f[20][48][2520],g[20][48][2520];
int t,lc[10][48],llc[48],cnt,nu[20],cll[3000];
il ull dp(bool eq,int dep,int clcm,int mod){
    if(!dep)return !(mod%llc[clcm]);
    if(eq&&~f[dep][clcm][mod])return f[dep][clcm][mod];
    if(!eq&&~g[dep][clcm][mod])return g[dep][clcm][mod];
    ull ans=0;
    int r=eq?nu[dep]:9;
    for(re int i=0;i<=r;i++)ans+=dp(eq&&(i==r),dep-1,i?lc[i][clcm]:clcm,(mod*10+i)%2520);
    if(eq)f[dep][clcm][mod]=ans;
    else g[dep][clcm][mod]=ans;
    return ans;
}
il ull solve(ull x){
    nu[0]=0;
    for(;x;x/=10)nu[++nu[0]]=x%10;
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));
    return dp(true,nu[0],0,0);
}
il int gcd(int i,int j){return j?gcd(j,i%j):i;}
il int lcm(int i,int j){return i*j/gcd(i,j);}
int main(){
    t=read();
    for(re int i=1;i<=2520;i++){
        if(!(2520%i))llc[cnt]=i,cll[i]=cnt++;
    }
    for(int i=1;i<=9;i++){
        for(int j=0;j<cnt;j++)lc[i][j]=cll[lcm(llc[j],i)];
    }
    while(t--){
        l=read(),r=read();
        write(solve(r)-solve(l-1));
        cout<<"\n";
    }
    return 0;
}