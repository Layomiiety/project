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
const int maxn=2e5+5;
int n,m,fa[5005],ans=0,l=0;
struct edge{
    int u,v,val;
}e[maxn<<1];
bool cmp(edge a, edge b){
    return a.val<b.val;
}
il int find(int i){
    if(fa[i]==i)return i;
    return fa[i]=find(fa[i]);
}
il void kruskal(){
    sort(e+1,e+m+1,cmp);
    for(re int i=1,fu,fv;i<=m&&l!=n-1;i++){
        fu=find(e[i].u);
        fv=find(e[i].v);
        if(fu==fv)continue;
        fa[fv]=fu;
        ans+=e[i].val;
        l++;
    }
}
int main(){
    n=read(),m=read();
    for(re int i=1;i<=n;i++)fa[i]=i;
    for(re int i=1;i<=m;i++){
        e[i].u=read(),e[i].v=read(),e[i].val=read();
    }
    kruskal();
    if(l!=n-1)printf("orz");
    else printf("%d",ans);
    return 0;
}
