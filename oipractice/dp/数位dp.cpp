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
ull a,b,f[20][170][170];
int x[20],sum;
il ull dp(bool eq,int cur,int dep,int mod){
    if(cur>sum)return 0;
    if(!dep)return (cur==sum)&&(!mod);
    if(!eq&&f[dep][cur][mod]!=-1)return f[dep][cur][mod];
    ull ans=0;
    int r=eq?x[dep]:9;
    for(int i=0;i<=r;i++)ans+=dp(eq&&(i==r),cur+i,dep-1,(mod*10+i)%sum);
    if(!eq)f[dep][cur][mod]=ans;
    return ans;
}
il ull solve(ull n){
    x[0]=0;
    for(;n;n/=10)x[++x[0]]=n%10;
    ull ans=0;
    for(int i=1;i<=9*x[0];i++){
        memset(f,-1,sizeof(f));
        sum=i;
        ans+=dp(1,0,x[0],0);
    }
    return ans;
}
int main(){
    a=read(),b=read();
    printf("%lld",solve(b)-solve(a-1));
    return 0;
}