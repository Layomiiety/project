//acw1141
#include <bits/stdc++.h>
using namespace std;
const int N=105,M=205;
int n,k,p[N],res=0;
struct edge{
    int a,b,w;
    bool operator <(const edge &t)const{return w<t.w;}
}e[M];
inline int ff(int x){return p[x]==x?x:p[x]=ff(p[x]);}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<k;i++){
        scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
    }
    sort(e,e+k);
    for(int i=0;i<k;i++){
        int a=ff(e[i].a),b=ff(e[i].b),w=e[i].w;
        if(a!=b)p[a]=b;
        else res+=w;
    }
    printf("%d",res);
    return 0;
}