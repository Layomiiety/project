//acw164
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
#define il inline 
#define LL long long
const int N=3e4+4;
int h[N],nex[N],to[N],cnt=1;
int n,m,d[N];
bitset<N> f[N];
il void add(int a,int b){to[cnt]=b,nex[cnt]=h[a],h[a]=cnt++;}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(b,a);
        d[a]++;
        }
    int q[N],hh,tt=-1;
    for(int i=1;i<=n;i++){
        if(!d[i])q[++tt]=i;
        f[i][i]=1;
    }
    while(hh<=tt){
        int x=q[hh++];
        for(int i=h[x];i;i=nex[i]){
            int y=to[i];
            f[y]|=f[x];
            if(--d[y]==0)q[++tt]=y;
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",f[i].count());
    return 0;
}