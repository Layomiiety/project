//acw1293
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define il inline
const int N=1e5;
int pr[N],cnt,n;
bool st[N];
void init(){
    for(int i=2;i<=n+1;i++){
        if(!st[i])pr[cnt++]=i;
        for(int j=0;j<cnt&&pr[j]*i<=n+1;j++){
            st[pr[j]*i]=true;
            if(!(i%pr[j]))break;
        }
    }
}
int main(){
    scanf("%d",&n);
    init();
    if(n==1||n==2)puts("1");
    else puts("2");
    for(int i=2;i<=n+1;i++){
        printf("%d ",st[i]?2:1);
    }
    return 0;
}