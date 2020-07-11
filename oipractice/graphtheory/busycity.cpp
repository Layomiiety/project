//acw1142
#include <bits/stdc++.h>
using namespace std;
const int N=305,M=8005;
int n,m,fa[N],ans;
struct edge{
    int a,b,w;
    bool operator<(const edge &t)const{
        return w<t.w;
    }
}e[M];
inline int ff(int x){return fa[x]==x?x:fa[x]=ff(fa[x]);}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
    sort(e,e+m);
    for(int i=0;i<m;i++){
        int a=ff(e[i].a),b=ff(e[i].b);
        if(a!=b){fa[a]=b,ans=e[i].w;}
    }
    printf("%d %d",n-1,ans);
    return 0;
}