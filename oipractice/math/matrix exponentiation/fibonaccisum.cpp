//acw1303
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
LL n,m, ma[3][3]={{0,1,0},{1,1,1},{0,0,1}},f[3]={1,1,1};
il void mul(LL res[],LL a[],LL b[][3]){
    LL temp[3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp[i]=(temp[i]+a[j]*b[j][i])%m;
        }
    }
    memcpy(res,temp,sizeof temp);
}
il void qmul(LL res[][3],LL a[][3],LL b[][3]){
    LL temp[3][3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%m;
            }
        }
    }
    
    memcpy(res,temp,sizeof temp);
}
int main(){
    scanf("%lld%lld",&n,&m);
    n-=1;
    for(;n;n>>=1){
        if(n&1)mul(f,f,ma);
        qmul(ma,ma,ma);
    }
    printf("%lld",f[2]);
    return 0;
}
