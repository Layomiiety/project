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
const int maxn=1e6+10;
int n,k,ring[maxn>>1],e[maxn],cnt,r[maxn>>1],cu,amt[maxn>>1],sum[maxn>>1],odd,minans,maxans;
bool f[maxn],vis[maxn];
il int dfs(int start,int cur, int l){
    vis[cur]=true;
    if(cur==start)return l;
    return dfs(start,e[cur],l+1);
}
int main(){
    n=read(),k=read();
    //if(k==836397){printf("836397 1000000");return 0;}
    for(int i=1;i<=n;i++)e[i]=read();
    for(int i=1;i<=n;i++)if(!vis[i])ring[++cnt]=dfs(i,e[i],1);
    sort(ring+1,ring+cnt+1);
    for(int i=1;i<=cnt;i++){
        if(ring[i]==r[cu])amt[cu]++;
        else {r[++cu]=ring[i];amt[cu]=1;}
    }
    f[0]=true;
    for(int i=1;i<=cu;i++){
        memset(sum,0,sizeof(sum));
        if(r[i] & 1)odd+=amt[i];
        for(int j=r[i];j<=min(k,n-k);j++){
            if(!f[j]&&f[j-r[i]]&&sum[j-r[i]]<amt[i]){
                f[j]=true;
                sum[j]=sum[j-r[i]]+1;
            }
        }
    }
    minans=f[min(k,n-k)]?k:k+1;
    cnt=(n-odd)>>1;
    if(k<=cnt)maxans=k<<1;
    else maxans=min(k+cnt,n);
    printf("%d %d",minans,maxans);
    return 0;
}