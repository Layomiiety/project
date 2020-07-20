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
const int N=1e9+5,M=1e5+5;
int t,n,m,a[M],b[M],ans=0,plu=0,le;
int main(){
    t=read();
    while(t--){
        n=read(),m=read();
        plu=0,ans=0,le=n;
        for(int i=1;i<=m;i++){a[i]=read(),b[i]=read();}
        for(int i=1;i<=m;i++){
            if(a[i]>plu)
        }
    }
    return 0;
    }