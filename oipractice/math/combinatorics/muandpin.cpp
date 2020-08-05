//acw1307
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
typedef long long ULL;
const int mod=5000011,N=1e5+5;
int n,k,dp[N];
int main(){
    scanf("%d%d",&n,&k);
    dp[0]=1;
    int sum=1;
    for(int i=1;i<=n;i++){
        if(i-k-1<=0)dp[i]=1;
        else dp[i]=(dp[i-1]+dp[i-k-1])%mod;
        //printf("%d ",dp[i]);
        sum=(sum+dp[i])%mod;
    }
    printf("%d",sum);
}