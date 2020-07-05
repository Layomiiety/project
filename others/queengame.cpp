#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
ll p=0,ls=0;
struct minister{
    ll l,r;
    int s;
}m[20005];
inline int read() {
    char ch=getchar();
    int x=0,f=1;
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
bool cmp(minister a,minister b){
    if(a.s!=b.s)return a.s<b.s;
    if(a.s==-1)return a.l<b.l;
    return a.r>b.r;
}
int main(){
    t=read();
    for(int i=0;i<t;i++){
        ls=0,p=0;
        n=read();
        for(int j=1;j<=n;j++){
            m[j].l=read(),m[j].r=read();
            if(m[j].l>m[j].r)m[j].s=1;
            else{
                if(m[j].l==m[j].r)m[j].s=0;
                else m[j].s=-1;
            }
        }
        sort(m+1,m+1+n,cmp);
        for(int j=1;j<=n;j++){
            ls+=m[j].l;
            p=max(p,ls)+m[j].r;
        }
        printf("%lld\n",p);
    }
    return 0;
}