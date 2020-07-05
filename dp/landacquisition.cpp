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
const int maxn=5e4+5;
struct land{
    int w,l;
}ol[maxn],la[maxn];
il bool cmp(land a,land b){
    return a.w!=b.w?a.w<b.w:a.l<b.l;
}
int n,cnt=1,q[maxn];
ull f[maxn];
int main(){
    n=read();
    for(re int i=1;i<=n;i++){
        ol[i]={read(),read()};
    }
    sort(ol+1,ol+n+1,cmp);
    for(re int i=1;i<=n;i++){
        while(cnt&&ol[i].l>=la[cnt].l)cnt--;
        la[++cnt]=ol[i];
    }
    f[0]=0;
    int hh=0,tt=0;
    for(int i=1;i<=cnt;i++){
        while(hh<tt&&f[q[hh+1]]-f[q[hh]]<(ll)la[i].w*(la[q[hh]+1].l-la[q[hh+1]+1].l))hh++;
        f[i]=f[q[hh]]+(ll)la[i].w*la[q[hh]+1].l;
        while(hh<tt&&(f[i]-f[q[tt]])*(ll)(la[q[tt-1]+1].l-la[i+1].l)<(f[i]-f[q[tt-1]])*(ll)(la[q[tt]+1].l-la[i+1].l))tt--;
        q[++tt]=i;
    }
    write(f[cnt]);
    return 0;
}