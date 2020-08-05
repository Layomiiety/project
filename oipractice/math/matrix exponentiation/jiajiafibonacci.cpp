//acw1304
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long ULL;
ULL n,m, ma[4][4]={{0,1,0,0},{1,1,1,1},{0,0,1,1},{0,0,0,1}},f[4]={1,1,1,1};
il void mul(ULL res[],ULL a[],ULL b[][4]){
    ULL temp[4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            temp[i]=(temp[i]+a[j]*b[j][i])%m;
        }
    }
    memcpy(res,temp,sizeof temp);
}
il void qmul(ULL res[][4],ULL a[][4],ULL b[][4]){
    ULL temp[4][4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%m;
            }
        }
    }
    
    memcpy(res,temp,sizeof temp);
}
int main(){
    scanf("%lld%lld",&n,&m);
    ULL x=n-1;
    for(;x;x>>=1){
        if(x&1)mul(f,f,ma);
        qmul(ma,ma,ma);
    }
    ULL ans=(((n+1)%m*f[2]%m-f[3])%m+m)%m;
    printf("%lld",ans);
    return 0;
}
