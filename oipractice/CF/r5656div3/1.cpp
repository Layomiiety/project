#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
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
const int maxn=2e5+5;
int t,x,y,z;
int main(){
    t=read();
    while(t--){
        x=read(),y=read(),z=read();
        int a=x,b=x,c=y;
        if(a>y)a=y;
        if(b>z)b=z;
        if(c>z)c=z;
        if(max(a,b)!=x||max(a,c)!=y||max(b,c)!=z)puts("NO");
        else {printf("YES\n%d %d %d\n",a,b,c);}
        }
    return 0;
    }