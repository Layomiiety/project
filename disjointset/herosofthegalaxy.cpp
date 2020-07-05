#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
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
inline void write(ull a)    
{
    if(a>9)
        write(a/10);
    putchar(a%10+'0');
}
int T,x,y,fa[30005],nu[30005],ii,jj,l[30005];
char ord;
il int ff(int i){
    if(fa[i]==i)return i;
    int fat=ff(fa[i]);
    nu[i]+=nu[fa[i]];
    //printf("%d %d\n",i,nu[i]);
    return fa[i]=fat;
}
int main(){
    T=read();
    for(re int i=1;i<=30000;i++){
        fa[i]=i;
        l[i]=1;
    }
    while(T--){
        scanf("%s%d%d",&ord,&x,&y);
        ii=ff(x),jj=ff(y);
        if(ord=='M'){
            fa[ii]=jj;
            nu[ii]=l[jj];
            l[jj]+=l[ii];
            }
        else{
            if(ii==jj)printf("%d\n",abs(nu[x]-nu[y])-1);
            else printf("-1\n");
        }
    }
    return 0;
}