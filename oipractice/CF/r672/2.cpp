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
const int N=1e5+5;
int t,n,a[40];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ull res=0;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            x=floor(log2(x));
            res+=(ull)a[x];
            a[x]++;
        }
        printf("%lld\n",res);
    }
    return 0;
}