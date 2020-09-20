#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1e6+5,mod=998244353;
int id,n,m;
LL f[N][N],c[N];
inline LL inv(LL x){
    int pow=mod-2;
    LL res=1;
    while(pow){
        x=x*x%mod;
        if(pow&1)res=res*x%mod;
        pow>>=1;
    }
    return res;
}
int main(){
    scanf("%d%d%d",&id,&n,&m);
    for(int i=1;i<=n;i++){
        c[i]=1;
        f[i+1][i]=1;
        }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        c[a]++;
        f[b][a]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)f[i][j]=inv(c[j])*(f[i][j]-c[j])%mod;
            else f[i][j]=inv(c[j])*f[i][j]%mod;
        }
    }
    gauss();
}