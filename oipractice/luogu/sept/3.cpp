#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define il inline 
#define LL long long
const int N=1e6+5,mod=998244353;
int n,k;
int a[N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k==1){
        int ans=0,cur=1,last=1;
        while(a[cur]){
            //for(int i=1;i<=n;i++)printf("%d ",a[i]);
            int mm=mod;
            while(a[cur]&&cur<=n){
                mm=min(mm,a[cur]);
                cur++;
            }
            printf("%d ",mm);
            ans+=mm;
            while(a[cur]&&cur<=n){
                a[cur]-=mm;
                cur++;
            }
            while(!a[last]&&last<=n)last++;
            cur=last;
        }
        printf("%d",ans);
    }
    else {
        for(int i)
    }
}