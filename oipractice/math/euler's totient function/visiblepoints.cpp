//acw1291
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
const int N=1002;
int n,c;
int pr[N],phi[N],cnt;
void init(){
    phi[1]=1;
    for(int i=2;i<=1000;i++){
        if(!phi[i]){
            pr[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<cnt&&pr[j]*i<=N;j++){
            if(!(i%pr[j])){
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
            phi[i*pr[j]]=phi[i]*(pr[j]-1);
        }
        phi[i]+=phi[i-1];
    }
}
int main(){
    scanf("%d",&c);
    init();
    //for(int i=0;i<=50;i++)printf("%d %d\n",i,phi[i]);
    for(int i=1;i<=c;i++){
        scanf("%d",&n);
        printf("%d %d %d\n",i,n,phi[n]*2+1);
    }
    return 0;
}