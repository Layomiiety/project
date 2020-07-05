#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define il inline
#define re register
inline int read(){
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
const int maxn=1e5+5;
int n,m,p,q[maxn];
ll f[2][maxn],d[maxn],a[maxn],sa[maxn];
il ll gety(int x,int y){
    return f[x&1][y]+sa[y];
}
int main(){
    n=read(),m=read(),p=read();
    for(re int i=1;i<n;i++)d[i]=d[i-1]+read();
    for(re int i=1;i<=m;i++){
        int h=read();
        ll t=read();
        a[i]=t-d[h-1];
    }
    sort(a+1,a+m+1);
    for(re int i=1;i<=m;i++)sa[i]=sa[i-1]+a[i];
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(re int i=1;i<=p;i++){
        int ni=i&1,pr=1-ni;
        int hh=0,tt=0;
        q[0]=0;
        memset(f[ni],0x3f,sizeof f[ni]);
        f[ni][0]=0;
        for(re int j=1;j<=m;j++){
            while(hh<tt&&gety(pr,q[hh+1])-gety(pr,q[hh])<(q[hh+1]-q[hh])*a[j])hh++;
            f[ni][j]=f[pr][q[hh]]-sa[j]+sa[q[hh]]+a[j]*(j-q[hh]);
            while(hh<tt&&(gety(pr,j)-gety(pr,q[tt]))*(j-q[tt-1])<
            (gety(pr,j)-gety(pr,q[tt-1]))*(j-q[tt]))tt--;
            q[++tt]=j;
        }
    }
    write(f[p%2][m]);
    return 0;
}