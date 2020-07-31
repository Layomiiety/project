#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define il inline
const int N=1e6+5;
bool st[N];
int prime[N>>2],cnt;
il void init(){
    for(int i=2;i<=1e6;i++){
        if(!st[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=1e6;j++){
            st[prime[j]*i]=1;
            if(!(i%prime[j]))break;
        }
    }
    st[1]=st[1]=2;
}
int main(){
    int n;
    init();
    while(scanf("%d",&n),n){
        for(int i=2;i<=cnt&&prime[i]<=n>>1;i++){
            if(!st[n-prime[i]]){
                printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
                break;
            }
        }
    }
    return 0;
}