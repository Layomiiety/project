#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1005;
ll ans=0,summ[maxn],w[maxn],c;
int n;
void dfs(int curn,ll curw){
    if(curw>c)return;
    if(curw+summ[curn-1]<=c) {
        ans=max(ans,curw+summ[curn-1]);
        return;
        }
    ans=max(ans,curw);
    for(int i=curn-1;i>=1;i--)dfs(i,curw+w[i]);
    return;
}
inline int read(){
    char ch=getchar();
    register int x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
int main(){
    scanf("%d%lld",&n,&c);
    for(int i=1;i<=n;i++)w[i]=read(),summ[i]=summ[i-1]+w[i];
    dfs(n+1,0);
    printf("%lld",ans);
    return 0;
}