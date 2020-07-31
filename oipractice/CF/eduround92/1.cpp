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
int T,l,r;
il void solve(){
    if(2*l>r)printf("-1 -1\n");
    else printf("%d %d\n",l,2*l);
}
int main(){
    T=read();
    while(T--){
        l=read(),r=read();
        solve();
    }
    return 0;
}