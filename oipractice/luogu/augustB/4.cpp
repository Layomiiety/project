#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define LL long long
const int N=5e5+10,M=N;
inline int read() {
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
int a[N],n,r[N],b[N],idx[N],ma[N],s[N>>1];
bool vis[M];
inline bool dfs(int x){
    for(int i=n;i;i--){
        if(i==x||vis[i]||r[idx[i]]==idx[x]||r[idx[x]]==idx[i])continue;
        vis[i]=true;
        if(!ma[i]||dfs(ma[i])){
            ma[x]=i;
            ma[i]=x;
            return true;
        }
    }
    return false;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){a[i]=read(),b[i]=a[i];}
    for(int i=1;i<=n;i++)r[i]=read();
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)idx[lower_bound(b+1,b+n+1,a[i])-b]=i;
    if(n<=3000){
        int cnt=0;
        for(int i=1;i<=n&&cnt<n/2;i++){
            if(ma[i])continue;
            memset(vis,0,sizeof vis);
            if(dfs(i))cnt++;
            }
        if(cnt!=n/2)puts("-1");
        else {
            LL res=0;
            memset(vis,0,sizeof vis);
            for(int i=1;i<=n&&cnt;i++){
                if(vis[i])continue;
                res+=cnt*(LL)a[idx[i]];
                vis[i]=true,vis[ma[i]]=true;
                s[cnt]=i;
                cnt--;
            }
            printf("%lld\n",res);
            for(int i=1;i<=n/2;i++)printf("%d %d\n",idx[s[i]],idx[ma[s[i]]]);
        }
    }
    else {
        LL res=0;
        for(int i=1;i<=n/2;i++){
            res+=(LL)b[i]*(n/2-i+1);
        }
        printf("%lld\n",res);
        for(int i=n/2;i;i--){
            printf("%d %d\n",idx[i],idx[i+n/2]);
        }
    }
    return 0;
}