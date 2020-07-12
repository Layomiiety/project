//acw346
#include <bits/stdc++.h>
using namespace std;
const int N=6005;
int x,y,z,n,t,fa[N],siz[N];
struct edge{
    int a,b,w;
    bool operator <(const edge &t)const{
        return w<t.w;
    }
}e[N];
inline int ff(int i){return i==fa[i]?i:fa[i]=ff(fa[i]);} 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<=n;i++){fa[i]=i,siz[i]=1;}
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            e[i]={x,y,z};
        }
        sort(e+1,e+n);
        for(int i=1;i<n;i++){
            x=ff(e[i].a),y=ff(e[i].b);
            fa[y]=x;
            ans+=(siz[x]*siz[y]-1)*(e[i].w+1);
            siz[x]=siz[y]+siz[x];
        }
        printf("%d\n",ans);
    }
    return 0;
}