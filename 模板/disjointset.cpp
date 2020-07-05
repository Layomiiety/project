#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
const int maxn=1005;
int n,m,fa[maxn],ene[maxn],x,y,cnt;
char z;
il int ff(int i){
    if(!fa[i])return i;
    return fa[i]=ff(fa[i]);
}
il void merge(int x,int y){
    int fx=ff(x),fy=ff(y);
    if(fx!=fy)fa[fx]=fy;
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%s%d%d",&z,&x,&y);
        if(z=='F')merge(x,y);
        else {
            if(ene[x])merge(ene[x],y);
            else ene[x]=y;
            if(ene[y])merge(ene[y],x);
            else ene[y]=x;
        }
    }
    for(int i=1;i<=n;i++){if(!fa[i])cnt++;}
    printf("%d",cnt);
    return 0;
}