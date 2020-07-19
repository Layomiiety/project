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
typedef pair<int,int>pii;
const int N=2e5+5,M=2e5+5;
int h[N],nex[M],to[M],cnt=1,n,m,dist[N],cc[N],pc=0;
pii p[N];
bool st[N];
int t,x,y,z;
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
il bool bfs(){
    memset(st,0,sizeof st);
    queue<int> q;
    if
    
}
int main(){
    t=read();
    while(t--)
        memset(h,0,sizeof h);
        cnt=1;
        n=read(),m=read();
        for(int i=0;i<m;i++){
            x=read(),y=read(),z=read();
            if(x)add(y,z);
            else {
                p[pc++]={y,z};
            }
        }
    if(bfs())puts("NO");
    return 0;
    }