//acw835
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define il inline
#define LL long long
using namespace std;
const int N=3e6+5;
int son[N][2],idx,cnt[N],n,ans=0;
il void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int t=x>>i&1;
        if(!son[p][t])son[p][t]=++idx;
        p=son[p][t];
        cnt[p]++;
    }
}
il int query(int x){
    int p=0,res=0;
    for(int i=30;i>=0;i--){
        int t=1-(x>>i&1);
        if(cnt[son[p][t]]){
            p=son[p][t];
            res+=1<<i;
        }
        else{
            p=son[p][1-t];
        }
    }
    return res;
}
int main(){
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        ans=max(ans,query(x));
        insert(x);
    }
    printf("%d",ans);
    return 0;
}