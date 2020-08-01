//acw1294
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define il inline
typedef long long LL;
const int N=2e9+5;
int n,pri[9]={2,3,5,7,11,13,17,19,23},ans=1,maxp=1;
il LL qp(LL ori,int p,LL base){
    for(;p;p>>=1){
        if(p&1)ori*=base;
        base*=base;
    }
    return ori;
}
il void dfs(int cur,int last,LL numb,int f){
    if(cur==9){
        if(f>maxp||(f==maxp&&numb<ans)){
            maxp=f,ans=numb;
        }
        return;
    }
    for(int i=min(int(floor(log(n/numb)/log(pri[cur]))),last);i>=0;i--){
        //printf("%d %d %d %d\n",i, pri[cur],numb,f);
        dfs(cur+1,i,qp(numb,i,pri[cur]),f*(i+1));
    }
}
int main(){
    scanf("%d",&n);
    dfs(0,31,1,1);
    printf("%d",ans);
    return 0;
}