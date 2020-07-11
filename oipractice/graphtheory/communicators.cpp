//acw1143
#include <bits/stdc++.h>
using namespace std;
const int N=2005,M=10005;
int n,m,p,u,v,w,fa[N],res=0,cnt=0;
struct edge{
    int a,b,v;
    bool operator <(const edge &t) const{
        return v<t.v;
    }
}e[M];
inline int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&p,&u,&v,&w);
        if(p==2)e[cnt++]={u,v,w};
        else {
            u=ff(u),v=ff(v);
            res+=w,fa[u]=v;
        }
    }
    sort(e,e+cnt);
    for(int i=0;i<cnt;i++){
        int a=ff(e[i].a),b=ff(e[i].b);
        if(a!=b){res+=e[i].v,fa[a]=b;}
    }
    printf("%d",res);
    return 0;
}