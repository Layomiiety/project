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
int t,x,n,ori[55],cnt=0;
bool st[55];
int main(){
    t=read();
    while(t--){
        memset(st,0,sizeof st);
        cnt=0;
        n=read();
        for(int i=1;i<=2*n;i++){
            x=read();
            if(st[x])continue;
            else {
                st[x]=true;
                ori[cnt++]=x;
            }
        }
        for(int i=0;i<cnt;i++)printf("%d ",ori[i]);
        puts("");
    }
    return 0;
}