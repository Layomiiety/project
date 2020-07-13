#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
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
const int N=1005;
int T, n, p[N],ma[N],mi[N],mai[N],mii[N];
il void solve(){
    bool cc=0;
    memset(ma,0x3f,sizeof ma);
    memset(mi,0x3f,sizeof mi);
    for(int i=1;i<=n;i++)p[i]=read();
    for(int i=1;i<=n;i++){
        if(p[i]>mi[i-1]){
            mii[i]=mii[i-1];
            mi[i]=mi[i-1];
        }
        else{
            mii[i]=i;
            mi[i]=p[i];
        }
    }
    for(int i=n;i>0;i--){
        if(p[i]>ma[i+1]){
            if(mi[i]!=p[i]){
                printf("YES\n%d %d %d\n",mii[i],i,mai[i+1]);
                cc=1;
                return;
                }
            mai[i]=mai[i+1];
            ma[i]=ma[i+1];
            }
        else {
            mai[i]=i;
            ma[i]=p[i];
        }        
    }
    puts("NO");
    return;
}
int main(){
    T=read();
    while(T--){
        n=read();
        solve();
    }
    return 0;
}