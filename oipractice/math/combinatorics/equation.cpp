//acw1307
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
int k,x,f[1000][100][140];
int qp(int x){
    int res=1,p=x,b=x%1000;
    for(;p;p>>=1){
        if(p&1)res=(res*b)%1000;
        b=(b*b)%1000;
    }
    return res;
}
il void add(int a[],int b[],int c[]){
    for(int i=0,t=0;i<140;i++){
        t+=b[i]+c[i];
        a[i]=t%10;
        t/=10;
    }
}
int main(){
    scanf("%d%d",&k,&x);
    int m=qp(x)-1;
    k=min(m-k+1,k-1);
    if(k==0)puts("1");
    else {
        for(int i=0;i<=m;i++){
            for(int j=0;j<=k&j<=i;j++){
                if(!j)f[i][j][0]=1;
                else add(f[i][j],f[i-1][j],f[i-1][j-1]);
            }
        }
        int n=139;
        while(!f[m][k][n])n--;
        for(int i=n;i>=0;i--)printf("%d",f[m][k][i]);
    }
    return 0;
}