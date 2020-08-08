//acw214
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define il inline
const int N=1e5+5,M=N<<1;
int h[N],to[M],nex[M],w[M],idx;
int dout[N],n,m;
double dpp[N];
il void add(int a,int b,int c){to[idx]=b,nex[idx]=h[a],w[idx]=c;h[a]=idx++;}
il double dp(int x){
    if(dpp[x])return dpp[x];
    double ans=0;
    for(int i=h[x];~i;i=nex[i]){
        int j=to[i];
        ans+=(double)(dp(j)+w[i])/dout[x];
    }
    return dpp[x]=ans;
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        dout[a]++;
        }
    printf("%.2lf",dp(1));
}
