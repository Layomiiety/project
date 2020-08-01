//acw1291
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define il inline
typedef long long LL;
const int N=1e6+5;
int n, cnt[N], s[N],a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        }
    for(int i=1;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            s[j]+=cnt[i];
        }
    }
    for(int i=1;i<=n;i++)printf("%d\n",s[a[i]]-1);
    return 0;
}